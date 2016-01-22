//
//  decrypt.cpp
//  XORencrypt
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#include "head.h"

using namespace std;

int decrypt(const char * filename) {
	
	//declare locals outside of try
	streampos size;
	char * memblock = {0};
	
	// all enclosing try statment
	try{
		
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
		else throw runtime_error("Unable to open file");
		
		// Ask for key
		cout << "Please enter your key: ";
		BIG rawKey;
		cin >> rawKey;
		
		
		SMALL keyArray[KEY_LENGTH] = {0};
		memcpy(keyArray, &rawKey, sizeof(BIG));
		
		// Actually doing the XORing
		for (int iter = 0; iter < size; iter++) {
			memblock[iter] = memblock[iter] ^ keyArray[iter%KEY_LENGTH];
		}
		
		
		// Output to a new file
		ofstream output("decrypted.txt", ios::out|ios::binary);
		if(output.is_open()) {
			output.write(memblock, size);
		} else throw runtime_error("Couldn't open file");
		output.close();
		
		//cleanup
		delete [] memblock;
		
		// catch errors
	} catch (runtime_error e) {
		cerr << e.what() << endl; // print error
		delete[] memblock; //cleanup
		return -1;
	}
	
	return 0;
}
