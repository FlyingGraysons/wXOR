//
//  main.c
//  wXOR
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#include "head.h"

int checkArgs(int argc, const char * arg2) {
	switch (argc) {
  case 4:
			if ( (strcmp(arg2, "-e") != 0) && (strcmp(arg2, "-d") != 0) ) {
				printf("Please use \'-e\' or \'-d\'\n");
				return -1;
			}
			break;
  default:
			printf("Too many arguments\n");
			return -2;
			break;
	}
	return 0;
}

void printHelp() {
	printf("wXOR Encryption:\n");
	printf("More info: http://www.github.com/FlyingGraysons/wXOR/\n");
	printf("Usage:\n");
	printf("\tArguments: -e [filename] [output file], -d [filename] [output file]\n");
	printf("\t\t-e: encyption\n");
	printf("\t\t-d: decryption\n");
}

int main(int argc, const char * argv[]) {
	
		
	// makes sure arguments are done right
	if (checkArgs(argc, argv[1]) < 0) {
		printHelp();
		return -1;
	}
	
	// set defaults
	bool encrypting = true;
	BIG rawKey = 0;
	
	if ( strcmp(argv[1], "-d") == 0 ) {
		encrypting = false;
		printf("Please enter your key: ");
		scanf("%lld", &rawKey);
	}
	
	encryptDe(argv[2], encrypting, rawKey, argv[3]);
	
	return 0;
}


// do the encrypting and decrypting
// has default outPutFile of "wXOR.txt", raw key will be prompted if not set, randomly generated for outPut files.
void encryptDe(const char * filename, const bool encrypting, const BIG rawKey, const char * outPutFile) {
	//declare array outside of try
	char * memblock;
	
	FILE *f; // make file pointer
	f = fopen(filename, "rb"); // set to input file
	
	fseek(f, 0, SEEK_END); // seek to end of file
	long size = ftell(f); // get current file pointer
	fseek(f, 0, SEEK_SET); // seek back to beginning of file
	
	memblock = calloc( size, sizeof(char)); // allocate memblock to correct size
	fread(memblock, sizeof(char), size, f);// Reads file into memory block.
	fclose(f); // Close file
	
	
	// declare array of keys
	SMALL keyArray[KEY_LENGTH];
	
	if (encrypting) {
		
		//initialize random
		srand(time(NULL));
		
		// Make the key
		int i;
		for (i = 0; i < KEY_LENGTH; i++) {
			keyArray[i] = rand();
		}
		
		// Make private key an int
		BIG key = 0;
		memcpy(&key, keyArray, (sizeof(SMALL) * KEY_LENGTH));
		
		// Print it
		// for (auto i: keyArray) { printf(static_cast<int>(i) << endl; } // prints each key
		printf("Your private key is: %llu\n", key);
		
	} else {
		// copy key into the keyArray
		memcpy(keyArray, &rawKey, sizeof(BIG));
	}
	
	// Actually doing the XORing
	for (int iter = 0; iter < size; iter++) {
		memblock[iter] = memblock[iter] ^ keyArray[iter%KEY_LENGTH];
	}
	
	
	// Output to a new file
	fopen(outPutFile, "w+b"); // open file
	fwrite( memblock, sizeof(char), size, f); // write to file
	fclose(f); // close file

	free(memblock); // cleanup memory
}