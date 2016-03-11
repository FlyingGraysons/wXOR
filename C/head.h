//
//  head.h
//  XORencrypt
//
//  Created by Henry on 3/10/16.
//  Copyright © 2016 Henry. All rights reserved.
//

#ifndef head_h
#define head_h

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum { false, true } bool; // boolean type

#define  SMALL uint8_t // keep same, perfect size for XORing with other chars

// Change
// BIG must be KEY_LENGTH times bigger than SMALL
// they all move in proportion
// eg. if KEY_LENGTH is 4, use uint32_t as BIG
#define BIG uint64_t // change to keep proportion
#define KEY_LENGTH 8

//funtions:
void encryptDe(const char * filename, const bool encrypting, const BIG rawKey, const char * outPutFile);
// encrypts with random key, or decrypts
// first param, input filename, second, encryption or decryption, third is raw key for decryption, fourth output filename



#endif /* head_h */
