/**
Brian Aguirre
ba5bx
huffmanenc.cpp
*/

#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
//NOTE THAT THE CODE USED TO READ THE FILE AND LOOP THROUGH IT
//IS FROM fileio.cpp, WRITTEN BY AARON BLOOFIELD. TAKEN FROM CS2150 - LAB 10
//FILES

//SORRY FOR THE MESS!
//HAD TO FIGURE THINGS OUT FOR MYSELF WHICH RESULTS IN THE NASTIEST CODE
//EVER!
int returnValues(huffmanNode *n){


}


huffmanNode * getUnique(huffmanTree *tree){



}

int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    int freq = 0;
    int arrayOfValues[128];
    for(int i=0; i<128; i++){
        arrayOfValues[i] = 0;
    }



    // attempt to open the supplied file.  FILE is a type desgined to
    // hold file pointers.  The first parameter to fopen() is the
    // filename.  The second parameter is the mode -- "r" means it
    // will read from the file.
    FILE *fp = fopen(argv[1], "r");
    // if the file wasn't found, output and error message and exit
    if ( fp == NULL ) {
        cout << "File '" << argv[1] << "' does not exist!" << endl;
        exit(2);
    }

    int numOfDistict = 0;
    int numberOfASC;
    char g;
    int sum = 0;
    int f[256]; // ASCII LIMIT:
    // read in each character, one by one.  Note that the fgetc() will
    // read in a single character from a file, and returns EOF when it
    // reaches the end of a file.
    //INITIALIZE
    for(int i=0; i<256; i++){
        f [i] = 0;
    }

    while ((g = fgetc(fp)) != EOF){
        if (g>=32 && g<= 126){
            f[g]++;
            sum++;

        }
    }

    //COUNTING NUMBER OF DISTINCT CHARATERS:
    for (int i = 0; i<256; i++){
        if (f[i]){
            numOfDistict++;
        }
    }

    int counter1 = 0; //There is another counter somewhere else - check for overloading error


    heap Brian = heap(numOfDistict+5);
    char Helen;

    //Char Helen is placed in the heap Brian ;)
    for (int i=0; i<256; i++){
        if (f[i] > 0 ){
            Helen = (char) i;
            huffmanNode *n = new huffmanNode(Helen, f[i]);
            Brian.insertNode(n);
        }
    }

    Brian.createTree();

    //CALCULATION VARIABLES:
    int total = sum * 8; //Take into account extra digits
    int totalBits = 0;
    double costOfHeap = 0;

    //CODE THAT MIGHT WORK BUT DIDN'T GET AROUND TO FIX IT!
    //COME BACK LATER FOR THIS:
    /**
    while ( (g = fgetc(fp)) != EOF ){
        numberOfASC = (int) g;
        if (numberOfASC > 31 && numberOfASC < 128){
            frequency[numberOfASC]++;
            arrayOfValues[freq]++;
            counter1++;
            freq++;
        }
        else if (numberOfASC < 31){
            //cout<<"Invalid number of range.";
        }
        cout << g;
    }*/
        /**
    heap heapBrian;

    for (int i=0;i<128;i++){
    	if (frequency[i]>0){ //Value check
            huffmanNode *t = new huffmanNode(frequency[i], (char) i); //CONSTRUCTOR:
            heapBrian.insertTree(t);

            numOfDistict++;
        }
    }
*/
    Brian.printPrefix(Brian.getMin(), "");


    cout<< "\n" << endl;

    // a nice pretty separator
    //I LOVE THIS NICE PRETTY SEPARATOR:

    cout << "----------------------------------------" << endl;
    // rewinds the file pointer, so that it starts reading the file
    // again from the begnning



    rewind(fp);
    string temporaryString;
    // read the file again, and print to the screen

    //GET TOTAL BITS COMBINED;
    while ( (g = fgetc(fp)) != EOF ){
        //SAME AS ABOVE!:
        if (g>=32 && g<=126){
            temporaryString = Brian.words[g];
            cout<< temporaryString;
            cout<< " ";
            totalBits++;
        }
    }

    //GET COST OF CONVERTING:
    for (int i=0; i<256; i++){
        if (f[i]>0){
            temporaryString = Brian.words[i];
            costOfHeap += ((temporaryString.length()) * ((double) f[i]/sum));
        }
    }
  


    //INFORMATION:
    cout<< "Disctinct characters:" << numOfDistict << " "<< endl;
    cout<< "Total Symbols:" << total << " "<< endl;
    cout<< "Original Bits" << numOfDistict << " "<< endl;
    cout<< "Compressed Bits:" << numOfDistict << " "<< endl;
    cout<< "Cost of Copression:" << costOfHeap << " "<< endl;
    cout<< "Ratio:" << (double) total/totalBits << " "<< endl;
    // close the file





    delete(Brian.getMin());

    fclose(fp);
}
