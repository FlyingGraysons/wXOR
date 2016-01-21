//
//  encrypt.cpp
//  XORencrypt
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#include "head.h"
#include "encrypt.hpp"

using namespace std;

int encrypt(const char * arg1) {
//declare locals outside of try
streampos size;
char * memblock = {0};

// all enclosing try statment
try{
	
	// Reads file into memory block.
	ifstream file (arg1, ios::in|ios::binary|ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char [size];
		file.seekg (0, ios::beg);
		file.read (memblock, size);
		file.close();
		
	}
	else throw runtime_error("Unable to open file");
		
	/*	To be implemented as a password picker.
	 cout << endl << "Please enter your 8 character key. If you want no key, please leave blank: ";
	 char * key;
	 cin.get(key, cin);
	 */
	
	//initialize random
	srand(time(NULL));
	
		// Make the key
		char keyArray[KEY_LENGTH];
	for (int i = 0; i < KEY_LENGTH; i++) {
		keyArray[i] = rand();
	}
	
	// Actually doing the XORing
	for (int iter = 0; iter < size; iter++) {
		memblock[iter] = memblock[iter] ^ keyArray[iter%KEY_LENGTH];
	}
	
	
	// Output to a new file
	ofstream output("encrypted.txt", ios::out|ios::binary);
	if(output.is_open()) {
		output.write(memblock, size);
	} else throw runtime_error("Couldn't open file");
		output.close();
		
		// Make private key an int
		unsigned int key = 0;
		for (auto i: keyArray) {
			key = key << sizeof(char);
			key+=i;
		}
	
	// Print it
	// for (auto i: keyArray) { cout << static_cast<int>(i) << endl; } // prints each key
	cout << "Your private key is: " << key << endl;
	
	
	// catch errors
	} catch (runtime_error e) {
		cerr << e.what() << endl; // print error
		delete[] memblock; //cleanup
		return -1;
	}
	
	return 0;
}