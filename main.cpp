//
//  main.cpp
//  XORencrypt
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#include "head.h"

using namespace std;

void checkArgs(int argc, const char * arg2) {
	switch (argc) {
  case 1:
  case 2:
			throw runtime_error("Please enter a file to encrypt as an argument");
			break;
  case 3:
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
	cout << "More info: www.leekspin.com" << endl;
	cout << "Usage:" << endl;
	cout << "\tArguments: -e [filename], -d [filename]" << endl;
	cout << "\t\t-e: encyption" << endl;
	cout << "\t\t-d: decryption" << endl;
}

int main(int argc, const char * argv[]) {
	
	try {
	
	// makes sure arguments are done right
	checkArgs(argc, argv[1]);
		
	} catch (runtime_error e) {cerr << e.what() << endl << endl; printHelp(); return -1;}
	
	if ( strcmp(argv[1], "-e") == 0 ) {encrypt(argv[2]);}
	//else {decrypt(argv[2]);} //not  yet implemented
	else cout << "lelelel";
	return 0;
}
