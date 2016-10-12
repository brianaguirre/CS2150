/**
Brian Aguirre
ListItr.cpp

**/

#include "ListItr.h"

using namespace std;

/**
ListItr();			//Constructor
    ListItr(ListNode* theNode);	// One parameter constructor
    bool isPastEnd() const;	//Returns true if past end position
    // in list, else false
    bool isPastBeginning() const;//Returns true if past first position
    // in list, else false
    void moveForward();	//Advances current to next position in list
    //(unless already past end of list)
    void moveBackward();	//Moves current back to previous position
    // in list (unless already past beginning of
    // list)
    int retrieve() const;	//Returns item in current position
**/

ListItr::ListItr(){
	//DOES NOTHING?
	current = NULL;
}

ListItr::ListItr(ListNode* theNode){
	current = theNode; //Sets the position of the itr to theNode desired:
}

bool ListItr::isPastEnd() const{
	if (current->next == NULL){
		return true;
	}
	else{
		return false;
	}
}

bool ListItr::isPastBeginning() const{
	if (current->previous == NULL){
		return true;
	}
	else{
		return false;
	}
}

void ListItr::moveForward(){
	if (isPastEnd()){
		//DO NOTHING - ALREADY AT END:
		cout << "You've reached the end of the list." << endl;
	}
	else{
		current = current->next;
	}
}

void ListItr::moveBackward(){
	if (isPastBeginning()){
		cout << "You've reached the beginning of the list." << endl;
	}
	else{
		current = current->previous;
	}
}

int ListItr::retrieve() const{
	return current->value;
}
