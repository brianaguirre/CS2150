/**
Brian Aguirre
ba5bx
heap.h
*/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "huffmannode.h"
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


//Creates the Tree of Nodes:
class huffmanTree{
public:
	//Defaults
	huffmanTree();
	~huffmanTree();


	//Initiation:
	void printNodeValue();
	void insertNode(huffmanNode *node, char value);
	int getFrequency()const;
	char getValue();
	void getValues(huffmanNode *node, char value);
	string getCode(huffmanNode *node, string code);

	int freq;
	//OPERATORS:
	bool operator<(const huffmanTree &n) const;
	
	//Variables:
	huffmanNode *root;
	huffmanNode *node;
	int numOfNodes;


};

#endif