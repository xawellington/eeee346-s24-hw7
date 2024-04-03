# Introduction

In this homework assignment, you will be exploring a couple of simple cipher algorithms. In addition, you will gain experience working with inheritance and polymorphism. The two ciphers you will implement are the Caesar cipher and the Autokey cipher.

# Tasks

In `AutokeyCipher.cpp` and `CaesarCipher.cpp`:
  * Implement the encode() and decode() member functions as specified in `AutokeyCipher.h` and `CaesarCipher.h`.

In `Cipher.h`:
  * Complete the class definition as described in the comments.

Do not modify other files.

# Usage of Inheritance

This homework assignment explores inheritance by defining a base class Cipher. The Cipher class is meant to define common behavior for all cipher classes (AutokeyCipher and CaesarCipher) that inherit from it.

# Usage of Polymorphism

The Cipher class defines the encode(), decode(), and isValidCharacter() member functions, but it should not implement them. The Cipher class is meant to be abstract, which means that its member functions should be inherited but only implemented in the derived classes. Thus, the member functions should be pure virtual functions.

Furthermore, the main function (provided) demonstrates polymorphism by using a base class pointer (cipher) to call derived class objects. The derived classes in this case are the CaesarCipher and AutokeyCipher. Each of these classes has its own implementations for encode() and decode() functions.

# Caesar Cipher

The Caesar cipher is a simple substitution cipher that replaces a letter with another letter by shifting it by a fixed number of positions.

![caesar_cipher](https://github.com/sskeme/eeee346-s24-hw7/assets/154963758/4c61f52f-88b0-403d-a462-455ed5eae53b)

See https://en.wikipedia.org/wiki/Caesar_cipher for more complete information.

For this homework assignment, the pseudocode is provided to help you.

# Autokey Cipher

The autokey cipher is a polyalphabetic substitution cipher that uses a key to encode/decode a message. The cipher appends a primer to the message to create a key which is then used to securely encode the given message.

![autokey_cipher](https://github.com/sskeme/eeee346-s24-hw7/assets/154963758/2cff6001-c7f3-497f-be34-10eaba433769)

See https://en.wikipedia.org/wiki/Autokey_cipher for more information.

The psuedocode has been provided to help you.

# Psuedocode: Caesar Cipher Encode

```
For each character in a message:
  If the character is valid (A-Z):
    Convert the character from ASCII code to an alphabet number (by subtracting 65 or 'A')
    Shift the number by subtracting the member shift
    If the shifted number > 25:
      Subtract 26 from the number
    Else if the shifted number is < 0: 
      Add 26 to the number
    Reconvert the number to ASCII code (by adding 65 or 'A')
    Add (concat) this code to encoded message 
    * Note: if the input message character is a white space (' '), the code for this iteration is a white space
  Else:
    return False
Store the encoded message in the member encoded
```

# Psuedocode: Caesar Cipher Decode

The decoding algorithm is the same procedure as the encoding with one minor difference: instead of subtracting the shift value, you need to add the shift value.

# Psuedocode: Autokey Cipher Encode

```
Set a key to the member primer concatenated with the message (i.e., primer + message)
For each character in the message and each character in the key (they share the same index):
  If the message character is valid (A-Z):
    Add the key character and the message character together
    Take this value mod 26
    Reconvert the number to ASCII code (by adding 65 or 'A')
    Add (concat) this code to encoded message
    * Note: if the input message character is a white space (' '), the code for this iteration is a white space
  Else:
    return False
Store the encoded message in the member encoded
```

# Psuedocode: Autokey Cipher Decode

```
Set a key to the member primer
For each character in the message and each character in the key (they share the same index):
  If the message character is valid (A-Z):
    Subtract the key character from the message character
    Take this value mod 26
    Reconvert the number to ASCII Code (by adding 65 or 'A')
    If the corresponding code is a number less than 65 or 'A':
      Add 26 to the code
    Add (concat) this code to decoded message
    Add (concat) this code to the key
    * Note: if the input message character is a white space (' '), the code for this iteration is a white space
  Else:
    return False
Store the decoded message in the member decoded
```

# Compile and Run

* For Cygwin users: 1) type the following commands on Terminal and 2) provide inputs.

```
g++ -o main *.cpp *.h
```
```
./main
```

* For CLion users: 1) update the CMakeLists.txt file as below, 2) click the Compile and Run button, and 3) provide inputs.

```
add_executable(your_project_name main.cpp AutokeyCipher.cpp AutokeyCipher.h CaesarCipher.cpp CaesarCipher.h Cipher.h tests.cpp tests.h)
```

Output (printed) messages will be written in the result.txt file.

# Inputs

1. Name of cipher to use (Caesar or Autokey)
2. Specific cipher info (shift amount for Caesar, primer for Autokey )
3. Action (DECODE/ENCODE)
4. Message to encode/decode

Example:

```
Caesar
3
DECODE
XYZ
```

# Tests 

There are four test inputs in the `inputs` folder.

Check that the result.txt file (for CLion users: this file is located in the cmake-build-debug folder) is identical to the resulting txt file in the `golden` folder for each test.

# Submit

Since the problem between GitHub Classroom and Codespaces has not been resolved yet, please upload your `AutokeyCipher.cpp`, `CaesarCipher.cpp`, and `Cipher.h` files to `myCourses > Assignments > Homework 7`. Do not submit *.docx, *.pdf, *.txt, or *.zip file. 
