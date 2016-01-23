//
//  head.h
//  XORencrypt
//
//  Created by Henry on 1/21/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define KEY_LENGTH 4

//typing
typedef uint8_t SMALL;
typedef uint32_t BIG;

//funtions:
void encryptDe(const char * filename, const bool encrypting, const uint32_t rawKey, const char * outPutFile = "wXOR.txt"); // encrypts with random key, or decrypts
// first param, input filename, second, encryption or decryption, third is raw key for decryption, fourth optional output filename
