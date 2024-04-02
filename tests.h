#ifndef TESTS_H
#define TESTS_H

#include <memory>
#include <string>
#include <iostream>
#include <fstream> // for filewrite
#include "Cipher.h"

using namespace std;

/**
 * test encoding a message
 * @param cipher - shared smart pointer to base class cipher to use
 * @param msg - string of the message to encode
 * @return true if encode is success else false
 */
bool testEncode(shared_ptr<Cipher> cipher, string msg);

/**
 * test decoding a message
 * @param cipher - shared pointer to base class cipher to use
 * @param msg - string of the message to decode
 * @return true if decode is success else false
 */
bool testDecode(shared_ptr<Cipher> cipher, string msg);

/**
 * print out details of specific cipher using downcasting
 * @param cipher - shared smart pointer to base class cipher
 * @return true if downcasts and details printed out else false
 */
bool printCipherDetails(shared_ptr<Cipher> cipher);

/**
 * string constant for encode action
 */
const string ACTION_ENCODE = "ENCODE";

/**
 * string constant for decode action
 */
const string ACTION_DECODE = "DECODE";

#endif
