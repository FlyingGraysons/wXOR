# wXOR
              __  __          
     __      _\ \/ /___  _ __ 
     \ \ /\ / /\  // _ \| '__|
      \ V  V / /  \ (_) | |   
       \_/\_/ /_/\_\___/|_|   
                       

Custom encyrption system, run from the Command line.  
Written in C, with an alternate version in C++.

### To compile
###### C Version
navigate to the `/C` directory of the repo, then run
`gcc main.cpp -o wXOR` (wXOR is the output executable in this case)
###### C++ Version
navigate to the `/CPP` directory of the repo, then run
`g++ main.cpp -o wXOR` (wXOR is the output executable in this case)
### To use
`./wXOR -e <input file> <output file>` encrypts input file  
`./wXOR -d <input file> <output file>` decrypts input file  
In the C++ version only, the output file is optional, and defaults to wXOR.txt.
#Features
- Randomly generated 64-bit encryption, using XOR. 
- *Because it does not use hashes, it is incredible time consuming to crack*
- Also, anyone can change bit-count of the encryption by changing simple setting in the header file.
- The output filename is also settable.
- Uses binary read and write to encrypt any file type, of any length.
- Clearly documented.
- Written in both C and C++, if for whatever reasons you need one or the other.
- Works cross-platform, on every platform.

#ToDo
1. Allow people to set their own passwords
2. Optimize code better, make code more compact.
3. Add extra security:
  - Set variables to clear from debuggers
  - Other cool stuff
4. Allow key to be used from command line
