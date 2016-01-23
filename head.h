//
//  head.h
//  XORencrypt
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#pragma once

// DONT CHANGE
#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
typedef uint8_t SMALL; // keep same, perfect size for XORing with other chars

//typing
// BIG must be KEY_LENGTH times bigger than SMALL
// the all move in proportion
// eg. if KEY_LENGTH is 4, use uint32_t as BIG
typedef uint64_t BIG; // change to keep proportion
#define KEY_LENGTH 8

//funtions:
void encryptDe(const char * filename, const bool encrypting, const BIG rawKey, const char * outPutFile = "wXOR.txt"); // encrypts with random key, or decrypts
// first param, input filename, second, encryption or decryption, third is raw key for decryption, fourth optional output filename
