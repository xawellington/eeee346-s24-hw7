#include "CaesarCipher.h"

const string CaesarCipher::CIPHER_NAME = "Caesar";

CaesarCipher::CaesarCipher(int shift) : Cipher(CIPHER_NAME), shift(shift){}

bool CaesarCipher::encode(string decodedMsg) {
  string encodedMsg = "";
    for (char c : decodedMsg) {
        if (c == ' ') {
            encodedMsg += ' ';
        } else if (isValidChar(c)) {
            int charNum = c - 'A';
            charNum -= shift;
            if (charNum > 25)
                charNum -= 26;
            else if (charNum < 0)
                charNum += 26;
            char encodedChar = charNum + 'A';
            encodedMsg += encodedChar;
        } else {
            return "False";
        }
    }
    return encodedMsg;
}

bool CaesarCipher::decode(string encodedMsg) {
  string decodedMsg = "";
    for (char c : encodedMsg) {
        if (c == ' ') {
            decodedMsg += ' ';
        } else if (isValidChar(c)) {
            int charNum = c - 'A'; 
            charNum += shift;
            if (charNum > 25)
                charNum -= 26;
            else if (charNum < 0)
                charNum += 26;
            char decodedChar = charNum + 'A'; 
            decodedMsg += decodedChar;
        } else {
            return "False";
        }
    }
    return decodedMsg;
}
}

bool CaesarCipher::isValidCharacter(char c) {
  return ((c >= 'A') && (c <= 'Z')) || (c == ' ');
}
