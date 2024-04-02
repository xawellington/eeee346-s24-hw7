#include "AutokeyCipher.h"

const string AutokeyCipher::CIPHER_NAME = "Autokey";

AutokeyCipher::AutokeyCipher(string primer) : Cipher(CIPHER_NAME), primer(primer) {}

bool AutokeyCipher::encode(string decodedMsg) {
  /*TODO: write your code*/
}

bool AutokeyCipher::decode(string encodedMsg) {
  /*TODO: write your code*/
}

bool AutokeyCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
