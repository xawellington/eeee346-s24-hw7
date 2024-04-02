#include "CaesarCipher.h"

const string CaesarCipher::CIPHER_NAME = "Caesar";

CaesarCipher::CaesarCipher(int shift) : Cipher(CIPHER_NAME), shift(shift){}

bool CaesarCipher::encode(string decodedMsg) {
  /*TODO: write your code*/
}

bool CaesarCipher::decode(string encodedMsg) {
  /*TODO: write your code*/
}

bool CaesarCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
