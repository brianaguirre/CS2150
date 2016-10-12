/**
Brian Aguirre
ba5bx
huffmannode.h
*/

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <string>
#include <iostream>

using namespace std;

class huffmanNode{

public:
	huffmanNode();
	huffmanNode(char x, int f);
	~huffmanNode();

	char element;
	int frequency;
	huffmanNode *left;
	huffmanNode *right;
	huffmanNode *root;

	char getElement();
	void printNodeValue();
	void insert(huffmanNode *n, char l, string code);
	int getFrequency();



};
#endif