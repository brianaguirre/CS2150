/**
Brian Aguirre
ba5bx
heap.cpp
*/

#include "heap.h"

heap::heap(int x){
	list = vector<huffmanNode*> (x+1); //Initializing the list of nodes
	words = vector<string> (256);
	currentSize = 0;
}

heap::~heap(){
	//Sets and clears list attributes:
	currentSize = 0;
	list.clear();
}

bool heap::isEmpty(){
	if (currentSize == 0){
		return true;
	}
	else{
		if(currentSize>0){
			return false;
		}
	}
}


huffmanNode* heap::getMin(){
	return list[1];
}
/**
huffmanTree* heap::deleteMinTree(){
	if (isEmpty()){
		cout<< "It's already empty."<<endl;
		return NULL;
	}
	else if (!isEmpty()){
		huffmanTree * l = list[1];
		list[1] = list [currentSize];
		percolateDown(1);

		return l;
	}
}
*/



//FROM CS2150 SLIDES AND LECTURE:
huffmanTree* heap::deleteMinTree(){
	if (isEmpty()){
		cout << "Already empty." << endl;
	}

	huffmanTree *value = list1[1];
	list1[1] = list1[currentSize--];
	percolateDown(1);

	return value;
}

huffmanNode * heap::deleteMinNode(){
	if (isEmpty()){
		cout<<"Already empty"<<endl;

	}
	else{
		huffmanNode* temp = list[1];
		percolateDown(1);
		return temp;
	}
}
//FROM CS2150 SLIDES ON HEAPS
void heap::percolateDown(int hole){
	childNode;
	int childPosition;
	huffmanNode *temp1;
	huffmanTree *temp;

	for (; hole*2 <= currentSize; hole = childPosition){
		childPosition = hole*2;
		if (childPosition != currentSize && ((list[childPosition+1])->frequency) < (list[childNode]->frequency)){
			childPosition++;
		}
		if ((list[childPosition]->frequency) < (temp1->frequency)){
			list[hole] = list[childPosition];
		}
		else{
			break;
		}
	}

	list[hole] = temp1;
}

void heap::printPrefix(huffmanNode* n, string code){

	if (n->left == NULL && n->right == NULL) {
        cout << n->element << " " << code << endl;
        words[n->element] = code; 
    }
    else{
		printPrefix(n->left, (code + "0"));
		printPrefix(n->right, (code + "1"));
	}
}
void heap::percolate(int hole){

	childNode;
	int num;
	huffmanNode *temp1;

	for (; hole*2 <= currentSize; hole = num){
		num = hole*2;
		if (num != currentSize && ((list[num+1])->frequency) < (list[childNode]->frequency)){
			num++;
		}
		if ((list[num]->frequency) < (temp1->frequency)){
			list[hole] = list[num];
		}
		else{
			break;
		}
	}

	list[hole] = temp1;

}

void heap::createTree(){
	huffmanNode * temp;
	while (currentSize > 1){
		huffmanNode *x = deleteMinNode();
		huffmanNode *y = deleteMinNode();
		int localFreq = (x->frequency) + (y->frequency);

		//JUST COMBINED THE TWO LEAST NODES:
		temp = new huffmanNode('*', localFreq);
		temp->left = x;
		temp->right = y;


		//START AND DO IT AGAIN:
		insertNode(temp);
	}
}

//DOUBLE THE LIST SIZE:
void heap::insertTree(huffmanTree *t){
	int previousSize = list1.size();

	if (currentSize == previousSize - 1){
		list.resize(previousSize*2);
	}

	currentSize++;
	int hole = currentSize;

	//THE LOOP WILL CONTINUE WHILE hole's parent is greater than n;
	while ((hole>1) && ((*t)<(*(list1[hole/2])))){
		
	}

	list1[hole] = t;
}

void heap::insertNode(huffmanNode* n){
	int num = 0;
	int previousSize = list.size();

	if (currentSize == list.size() -1){
		list.resize(list.size()*2);
	}

	int hole = ++currentSize;

	for(; (hole > 1) && ((n->frequency) < (list[hole/2]->frequency)); hole /= 2){
		list[hole] = list[hole/2];
	} 

	list[hole] = n;

}


