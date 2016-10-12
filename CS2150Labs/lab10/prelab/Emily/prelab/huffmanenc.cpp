// Emily (Thien-Huong) Tran
// ID: tnt5tz
// File: heap.cpp
// Date: November 16, 2011

#include "heap.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int main (int argc, char **argv) {

  if ( argc != 2 ) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);

  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }

  // read in the first section of the file: the prefix codes
  char buffer[256];
    huffNode *n = new huffNode('-', 0); 
  while ( true ) {
    char first = file.get();
    if ( (first == '\n') || (first == '\r') )
      continue;
    char second = file.get();
    if ( (first == '-') && (second == '-') ) {
      file.getline(buffer, 255, '\n');
      break;
    }
    // read in the prefix code
    file.getline(buffer, 255, '\n');

    // create tree
    //cout << "character '" << first << "' has prefix code '" << buffer << "'" << endl;
        n->insertPrefix(n, first, buffer); 
  }

  // read in the second section of the file: the encoded message
  char bit;
    string s;
    huffNode *cur = n; // cur equals root node n    
    cout << "\nDecoded message:\n " << endl;
  while ( (bit = file.get()) != '-' ) {
    if ( (bit != '0') && (bit != '1') ) {
      continue;
        }
        if (bit == '0') {
            cur = cur->left;
            if (cur->left == NULL && cur->right == NULL) {
                cout << cur->value; 
                cur = n; 
            }
        }
        else {
            cur = cur->right;
            if (cur->left == NULL && cur->right == NULL) {
                cout << cur->value; 
                cur = n; 
            }
        }
  }
    cout << "\n\n";

  // close the file before exiting
  file.close();
}