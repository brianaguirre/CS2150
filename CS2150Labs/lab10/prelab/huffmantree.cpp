/**
Brian Aguirre
ba5bx
huffmantree.cpp
*/

#include "huffmantree.h"

using namespace std;

//DEFAULTS:

huffmanTree::huffmanTree(){

}



huffmanTree::~huffmanTree(){
	delete root;
	delete node;
}


void huffmanTree::insertNode(huffmanNode *n, char val){
	huffmanNode *temporaryNode;

	temporaryNode = root;
	char tempChar = '*';
	int tempInt = 0;
	root = new huffmanNode(tempChar, tempInt);
	root -> right = temporaryNode;
	root -> left = new huffmanNode(tempChar, tempInt);
	numOfNodes += numOfNodes;
}

int huffmanTree::getFrequency() const{
	return freq;
}


bool huffmanTree::operator<(const huffmanTree& n) const{
	if (this->getFrequency() > n.getFrequency()){
		return true;
	}

	else{
		return false;
	}
}
















