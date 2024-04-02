#ifndef CAESARCYPHER_H
#define CAESARCYPHER_H

#include "Cipher.h"

// derived concrete class of the abstract base class Cipher
class CaesarCipher : public Cipher {
public:
  /**
   * constructor
   * @param shift - set amount to shift in cipher
   */
  CaesarCipher(int shift);

  /**
   * performs Caesar encoding of a message
   * @param decodedMsg - string message to encode
   * @return true if encoding is successful else false
   */
  bool encode(string decodedMsg);

  /**
   * performs Caesar decoding of message
   * @param encodedMsg - string message to decode
   * @return true if decoding is successful else false
   */
  bool decode(string encodedMsg);

  /**
   * checks if the character is valid for a Caesar cipher
   * for this implementation capital A-Z or a space are only valid
   * ASCII representation of A-Z are decimal numbers 65-90
   * @param c - character to check
   * @return - true if character is A-Z or space otherwise false
   */
  bool isValidCharacter(char c);

  /**
   * getter
   * @return shift value used with the cipher
   */
  int getShiftValue() { return shift; };

  /**
   * static const string for a Caesar cipher name
   */
  static const string CIPHER_NAME;

private:
  /**
   * shift value for a Caesar cipher
   */
  int shift;
};
#endif
