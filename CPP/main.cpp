//
//  main.cpp
//  wXOR
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#include "head.hpp"

using namespace std;

void checkArgs(int argc, const char * arg2) {
	switch (argc) {
	case 1:
	case 2:
			throw runtime_error("Please enter a file to encrypt as an argument");
			break;
	case 3:
	case 4:
			if ( (strcmp(arg2, "-e") != 0) && (strcmp(arg2, "-d") != 0) ) {
				throw runtime_error("Please use \'-e\' or \'-d\'");
			}
			break;
	default:
			throw runtime_error("Too many arguments");
			break;
	}
}

void printHelp() {
	cout << "wXOR Encryption:" << endl;
	cout << "More info: http://www.github.com/FlyingGraysons/wXOR/" << endl;
	cout << "Usage:" << endl;
	cout << "\tArguments: -e [filename] [output file], -d [filename] [output file]" << endl;
	cout << "\t\t-e: encyption" << endl;
	cout << "\t\t-d: decryption" << endl;
	cout << "\t\tThe output file is optional, and has a default value of wXOR.txt" << endl;
}

int main(int argc, const char * argv[]) {

	try {

		// makes sure arguments are done right
		checkArgs(argc, argv[1]);

	} catch (runtime_error e) {
		cerr << e.what() << endl << endl; printHelp(); return -1;
	}

	// set defaults
	bool encrypting = true;
	BIG rawKey = 0;

	if ( strcmp(argv[1], "-d") == 0 ) {
		encrypting = false;
		cout << "Please enter your key: ";
		cin >> rawKey;
	}

	if (argc ==4) {
		encryptDe(argv[2], encrypting, rawKey, argv[3]);
	} else {
		encryptDe(argv[2], encrypting, rawKey);
	}

	return 0;
}


// do the encrypting and decrypting
// has default outPutFile of "wXOR.txt", raw key will be prompted if not set, randomly generated for outPut files.
void encryptDe(const char * filename, const bool encrypting, const BIG rawKey, const char * outPutFile) {
	//declare array outside of try
	char * memblock = {0};

	// all enclosing try statment
	try{
		// declare local variables
		streampos size;

		// Reads file into memory block.
		ifstream file (filename, ios::in|ios::binary|ios::ate);
		if (file.is_open())
		{
			size = file.tellg();
			memblock = new char [size];
			file.seekg (0, ios::beg);
			file.read (memblock, size);
			file.close();

		}
		else throw runtime_error("Unable to open input file");

		/*	To be implemented as a password picker.
		 cout << endl << "Please enter your 8 character key. If you want no key, please leave blank: ";
		 char * key;
		 cin.get(key, cin);
		 */

		// declare array of keys
		SMALL keyArray[KEY_LENGTH];

		if (encrypting) {

			//initialize random
			srand(time(0));

			// Make the key
			for (int i = 0; i < KEY_LENGTH; i++) {
				keyArray[i] = rand();
			}

			// Make private key an int
			BIG key = 0;
			memcpy(&key, keyArray, (sizeof(SMALL) * KEY_LENGTH));

			// Print it
			// for (auto i: keyArray) { cout << static_cast<int>(i) << endl; } // prints each key
			cout << "Your private key is: " << key << endl;

		} else {
			// copy key into the keyArray
			memcpy(keyArray, &rawKey, sizeof(BIG));
		}

		// Actually doing the XORing
		for (int iter = 0; iter < size; iter++) {
			memblock[iter] = memblock[iter] ^ keyArray[iter%KEY_LENGTH];
		}


		// Output to a new file
		ofstream output(outPutFile, ios::out|ios::binary);
		if(output.is_open()) {
			output.write(memblock, size);
		} else throw runtime_error("Couldn't open output file");
		output.close();

		// cleanup
		delete [] memblock;

		// catch errors
	} catch (runtime_error e) {
		cerr << e.what() << endl; // print error
		delete[] memblock; //cleanup
		return;
	}
}
