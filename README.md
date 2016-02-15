# wXOR
Custom encyrption system, run from the Command line.

### To compile:
`g++ main.cpp -o wXOR` (wXOR is the output filename in this case)
### To use:
`./wXOR -e <input file> <output file>` encrypts input file  
`./wXOR -d <input file> <output file>` decrypts input file
#Features
- Randomly generated 64-bit encryption, using XOR. 
- Because it does not use hashes, it is incredible time consuming to crack
- Also, anyone can change bit-count by changing simple setting in the header file.
- The output filename is also settable.
- Uses binary read and write to encrypt any file type, of any length.
- Clearly documented.
- Written in C++.
- Works cross-platform.

#ToDo
1. Allow people to set their own passwords
2. Optimize code better, make code more compact.
3. Add extra security:
  - Set variables to clear from debuggers
  - Other cool stuff
