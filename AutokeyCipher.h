#ifndef AUTOKEYCYPHER_H
#define AUTOKEYCYPHER_H

#include "Cipher.h"

// derived concrete class of the abstract base class Cipher
class AutokeyCipher : public Cipher {
public:
  /**
   * constructor
   * @param primer - primer to use for cipher
   */
  AutokeyCipher(string primer);
  
 /**
   * performs Autokey encoding of a message
   * @param decodedMsg - string message to encode
   * @return true if encoding is successful else false
   */
  bool encode(string decodedMsg);

  /**
   * performs Autokey decoding of a message
   * @param encodedMsg - string message to decode
   * @return true if decoding is successful else false
   */
  bool decode(string encodedMsg);

  /**
   * checks if the character is valid for an Autokey cipher
   * for this implementation capital A-Z or a space are only valid
   * ASCII representation of A-Z are decimal numbers 65-90
   * @param c - character to check
   * @return - true if character is A-Z or space otherwise false
   */
  bool isValidCharacter(char c);

  /**
   * getter
   * @return key used in the cipher
   */
  string getPrimerValue() { return primer; };

  /**
   * static const string for an AutokeyCipher name
   */
  static const string CIPHER_NAME;

private:
  /**
   * primer used in an Autokey cipher
   */
  string primer;
};
#endif
