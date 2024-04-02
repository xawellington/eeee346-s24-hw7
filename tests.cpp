#include "tests.h"
#include "CaesarCipher.h"
#include "AutokeyCipher.h"

extern ofstream myFile; // for filewrite

bool testEncode(shared_ptr<Cipher> cipher, string msg) {
  bool status = true;
  myFile << "Encoding message using " << cipher->getCipherName() << " Cipher encoder!" << endl;

  // attempt to encode
  // this uses polymorphism. cipher is a shared pointer of the abstract base class Cipher
  // however, it calls the encode function of the derived concrete class in which it points
  if (cipher->encode(msg)) {
    myFile << "Encoded Message is:" << endl;
    myFile << cipher->getEncoded() << endl;
  } else {
    myFile << "Failed to encode message!" << endl;
    status = false;
  }
    
  return status;
}

bool testDecode(shared_ptr<Cipher> cipher, string msg) {
  bool status = true;
  myFile << "Decoding message using " << cipher->getCipherName() << " Cipher decoder!" << endl;

  // attempt to decode
  // this uses polymorphism. cipher is a shared pointer of the abstract base class Cipher
  // however, it calls the decode function of the derived concrete class in which it points
  if (cipher->decode(msg)) {
    myFile << "Decoded Message is:" << endl;
    myFile << cipher->getDecoded() << endl;
  } else {
    myFile << "Failed to decode message!" << endl;
    status = false;
  }

  return status;
}

bool printCipherDetails(shared_ptr<Cipher> cipher) {
  bool status = true;

  // we want to print out the detail of the derived class that cipher points to
  // this information is not available in the base class Cipher
  // therefore, we need to downcast to gain access to that information

  // use dynamic_pointer_cast to attempt downcast Cipher to CaesarCipher
  shared_ptr<CaesarCipher> cc = dynamic_pointer_cast<CaesarCipher>(cipher);

  // use dynamic_pointer_cast to attempt downcast Cipher to AutokeyCipher
  shared_ptr<AutokeyCipher> xc = dynamic_pointer_cast<AutokeyCipher>(cipher);

  myFile << "Details for Cipher Used:" << endl;

  // if a cast is successful, it will not be a nullptr
  // go through and check which downcast was successful and print out extra details
  if (cc != nullptr){
    myFile << cc->getCipherName() << " Cipher used a shift of " << cc->getShiftValue() << endl;
  } else if ( xc != nullptr ){
    myFile << xc->getCipherName() << " Cipher used a key of " << xc->getPrimerValue() << endl;
  } else {
    myFile << "Unable to obtain cipher details!" << endl;
    status = false;
  }

  return status;
}
