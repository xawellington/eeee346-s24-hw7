#include <iostream>
#include <memory>

#include "tests.h"
#include "CaesarCipher.h"
#include "AutokeyCipher.h"

using namespace std;

ofstream myFile; // for filewrite

int main() {
  myFile.open("result.txt");
  
  // storage of values from cin
  string cipherName;
  string msg;
  string action;

  // result variable
  bool actionStatus;

  // shared pointer to abstract base class cipher
  shared_ptr<Cipher> cipher;

  // request name for the cipher to use
  cin >> cipherName;

  // use string compar() to know which cipher to setup
  if(cipherName.compare(CaesarCipher::CIPHER_NAME) == 0) {
    // requested Caesar cipher, it needs a shift value
    int shift;
        
    // get shift value
    cin >> shift;

    // setup Polymorphism
    // assign a shared pointer to point to a concrete derived class of type CaesarCipher
    cipher = make_shared<CaesarCipher>(shift);
  } else if(cipherName.compare(AutokeyCipher::CIPHER_NAME) == 0) {
    // requested Autokey cipher, it requires a char key
    string key;

    // get the key
    cin >> key;

    // setup Polymorphism
    // assign shared pointer to point to a concrete derived class of Type AutokeyCipher
    cipher = make_shared<AutokeyCipher>(key);

  } else {
    cout << "Bad cipher name ( " << cipherName << " )" << endl;
    return -1;
  }

  // request action (ENCODE or DECODE)
  cin >> action;

  // check the action entered
  if( (action.compare(ACTION_ENCODE) != 0)  && (action.compare(ACTION_DECODE) != 0) ) {
    cout << "Bad cipher action ( " << action << " )" << endl;
    return -1;
  }

  // request for message
  getline(cin >> ws, msg); // >> ws: to extract and discard any leading whitespace characters

  // based on action, perform encode or decode
  if (action.compare(ACTION_ENCODE) == 0) {
    actionStatus = testEncode(cipher, msg);
  } else if (action.compare(ACTION_DECODE) == 0) {
    actionStatus = testDecode(cipher, msg);
  } else {
    cout << "Bad cipher action ( " << action << " )" << endl;
    return -1;
  }

  // attempt to print out the details of Abstract Base Class Cipher
  if (!actionStatus || !printCipherDetails(cipher)) {
    return -1;
  }

  return 0;
}
