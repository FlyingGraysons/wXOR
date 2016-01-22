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

#include "encrypt.hpp"
#include "decrypt.hpp"

#define KEY_LENGTH 4

//typing
typedef uint8_t SMALL;
typedef uint32_t BIG;