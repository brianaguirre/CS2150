/**
Brian Aguirre
ba5bx
heap.h
*/

#ifndef HEAP_H
#define HEAP_H


//NOTE USING VECTOR TO CREATE LIST OF HUFFMANNODES:
#include <vector>
#include <iostream>
#include "huffmantree.h"
#include "huffmannode.h"
#include <string>

using namespace std;

class heap{
public:
	heap(int x);
	~heap();

	bool isEmpty();
	void insertNode(huffmanNode *n);
	void insertTree(huffmanTree *t);
	huffmanNode* getMin();
	huffmanTree * findMin();
	huffmanTree * deleteMinTree();
	huffmanNode* deleteMinNode();
	huffmanNode* deleteMin();
	int getSize();
	vector<huffmanNode*> getList();
	huffmanNode* returnMin();

	void createTree();
	void printPrefix(huffmanNode *n, string code);
	int childNode;

	vector<string> words;
private:
	int currentSize;
	vector<huffmanNode*> list;
	vector<huffmanTree*> list1;
	string codeOfNode;
	void percolateDown(int hole);
	void percolate(int hole);


	int frequency;
	huffmanNode* tempNode;
};

#endif




