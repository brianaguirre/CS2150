

#include "huffmannode.h"
using namespace std;


huffmanNode::huffmanNode(){
}

huffmanNode::huffmanNode(char x, int f){
	left = NULL;
	right = NULL;
	frequency = f;
	element = x;
}

huffmanNode::~huffmanNode(){
	delete right;
	delete left;

}

char huffmanNode::getElement(){
	return element;
}

int huffmanNode::getFrequency(){
	return frequency;
}

//PRINTS PREFIX:
//CODE GATHERED FROM PREVIOUS LAB AND LECTURE NOTE ON 
//ALGORITHM FOR PREFIX PRINTING:
void huffmanNode::insert(huffmanNode *n, char l, string code){
	int len = code.length();

	//IF IT HAS A STRING NOT NULL

	huffmanNode *temp0 = new huffmanNode('&',0);
	if (len>0){
		huffmanNode *temp1 = new huffmanNode('&',0);
		//FIRST CHARACTER!
		char first = code[0];

		//SECOND CHARACTER!
		char firstChar = code[0];
		
		if (first == '0'){
			if (n->left == NULL){
				huffmanNode *temp = new huffmanNode('*', 0);
				n->left = temp;
				huffmanNode *temp2 = new huffmanNode('&',0);
				string subString = code.substr(1); //GETS RID OF code[0]
				insert(n->left, l, subString);
			}

			else{
				string subString = code.substr(1); //GETS RID OF code[0]
				insert(n->left, l, subString);
			}
		}
		else{
			if (n->right == NULL){
				huffmanNode *temp = new huffmanNode('*', 0);
				n->right = temp;
				huffmanNode *temp2 = new huffmanNode('&',0);
				string subString = code.substr(1); //GETS RID OF code[0]
				insert(n->right, l, subString);
			}
			else{
				string subString = code.substr(1); //GETS RID OF code[0]
				insert(n->right, l, subString);
			}
		}
	}
	else{
			n->element = l;
		}
}

void huffmanNode::printNodeValue(){

	cout << "Node value: " << element << endl;
}
