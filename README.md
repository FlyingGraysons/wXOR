# wXOR
Custom encyrption system, run from the Command line.
### Usage:  
wXOR Encryption:  
Usage:  
  Arguments: -e [filename] [output file], -d [filename] [output file]  
    -e: encyption  
    -d: decryption  
    The output file is optional, and has a default value of wXOR.txt 


### To compile:
`g++ main.cpp -o wXOR` (wXOR is the output filename in this case)

#Features
- Randomly generated 64-bit encryption, using XOR. 
- Also, anyone can change bit-count by changing simple setting in the header file.
- The output filename is also settable.
- Uses binary read and write to encrypt any file type, of any length.
- Clearly documented.
- Written in C++.
- Works cross-platform.


#ToDo
1. Allow people to set their own passwords
2. Optimize code better, make code more compact.
