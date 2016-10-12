// Emily (Thien-Huong) Tran
// ID: tnt5tz
// File: huffmanenc.cpp
// Date: November 22, 2011

#include "heap.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main(int argc, char **argv) {
    if ( argc != 2 ) {
       cout << "Must supply the input file name as the one and only parameter" << endl;
       exit(1);
  }

    FILE *f = fopen(argv[1], "r");

    if (f == NULL) {
        cout << "File was not found." << endl;
    }

    // counts and stores frequencies of charactes from file in an array
    int freq[256] = { 0 }; 
    int totalc = 0;
    char g;
  while ( (g = fgetc(f)) != EOF ) {
        if (g>=32 && g<=126)    {   
            freq[g]++;
            totalc++;
        }
    }

    // counts number of distinct characters 
    int dc = 0;
    for (int j = 0; j < 256; j++) {
        if (freq[j] > 0) {
            dc++; 
        }
    }

    // creates huff nodes for non-zero entries in array and inserts them into heap
    heap hp = heap(dc+5);
    char c;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            c = (char) i; 
            huffNode *n = new huffNode(c, freq[i]);
            hp.insert(n); 
        }
    }

    // generates huffman tree and prints stuff 
    hp.createHuff();

    int tBit = totalc*8; 
    int comBit = 0;
    float cost = 0;

    cout << "\n";
    hp.prefix(hp.getMin(), "");
    cout << "----------------------------------------" << endl;

    rewind(f);
    string s; 
    while ( (g = fgetc(f)) != EOF ) {
        if (g>=32 && g<=126)    {   
            s = hp.s[g];
            cout << s << " ";
            comBit += s.length();
        }
    }

    for (int z = 0; z < 256; z++) {
        if (freq[z] > 0) {
            s = hp.s[z];
            cost += ( (s.length()) * ((float) freq[z]/totalc) );
        }
    }
    
    float dec = (float) tBit/comBit; 

    cout << "\n----------------------------------------" << endl;
    cout << "There are a total of " << totalc << " symbols that are encoded." << endl;
    cout << "There are " << dc << " distinct characters used." << endl;
    cout << "There are " << tBit << " bits in the original file." << endl;
    cout << "There were " << comBit << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << dec << "." << endl;
    cout << "The cost of the Huffman tree is " << cost  << " bits per characters.\n" << endl;
    
    delete (hp.getMin());

    fclose(f);

return 0;
}