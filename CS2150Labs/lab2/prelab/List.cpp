/**
Brian Aguirre
list.cpp

**/

#include "List.h"

using namespace std;
/**
    List();				//Constructor
    List(const List& source);	//Copy Constructor
    ~List();			//Destructor
    List& operator=(const List& source);	//Equals Operator
    bool isEmpty() const;		//Returns true if empty; else false
    void makeEmpty();	//Removes all items except blank head and tail
    ListItr first(); 		//Returns an iterator that points to
    //the ListNode in the first position
    ListItr last();			//Returns an iterator that points to
    //the ListNode in the last position
    void insertAfter(int x, ListItr position);
    //Inserts x after current iterator position p
    void insertBefore(int x, ListItr position);
    //Inserts x before current iterator position p
    void insertAtTail(int x);	//Insert x at tail of list
    void remove(int x);		//Removes the first occurrence of x
    ListItr find(int x);		//Returns an iterator that points to
    // the first occurrence of x, else return a iterator to the dummy tail node

    int size() const; //Returns the number of elements in the list
**/

List::List(){
	//VALUES ARE IN PRIVATE:
	head = new ListNode();
	tail = new ListNode();
	count = 0;

	head->next = tail;
	tail->previous = head;
}

//GIVEN METHOD:
List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


List::~List(){
	//Use a new temp itr:
	delete head;
	delete tail;
}

//GIVEN METHOD:
List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const{
	if (count == 0){
		return true;
	}
	else{
		return false;
	}
}

void List::makeEmpty(){
	ListItr itr = first();
	while (itr.current != tail){ //COULD ALSO WORD IT AS: isPastEnd();
		itr.moveForward();
		delete itr.current->previous;
		count--;	
	}
}

ListItr List::first(){
	return (ListItr(head->next));

}

ListItr List::last(){

	return (ListItr(tail->previous));
}

void List::insertAfter(int x, ListItr position){

	ListNode* newNode = new ListNode();
	newNode->value = x;


	newNode->next = position.current->next;
	newNode->previous = position.current;

	position.current->next->previous = newNode;
	position.current->next = newNode;

	count++;
}

void List::insertBefore(int x, ListItr position){

	ListNode* newNode = new ListNode();
	newNode->value = x;

	newNode->next = position.current;
	newNode->previous = position.current->previous;

	position.current->previous->next = newNode;
	position.current->previous = newNode;

	count++;

}

void List::insertAtTail(int x){

	ListNode* newNode = new ListNode();
	newNode->value = x;

	newNode->next = tail;
	newNode->previous = tail->previous;

	tail->previous->next = newNode;
	tail->previous = newNode;

	count++;
}


void List::remove(int x){
	//FIX THE FACT THAT ITERATOR STAYS IN DELETE NODE:
	ListItr iter = first();

	while (!iter.isPastEnd()){
		if (iter.current->value == x){
			iter.current->next->previous = iter.current->previous;
			iter.current->previous->next = iter.current->next;
			iter.current = iter.current->previous;

			
		}
		else{
			iter.moveForward();
		}
	}
}

ListItr List::find(int x){
	ListItr iter = first();
	while (!iter.isPastEnd()){
		if (iter.current->value == x){
			return iter;
			break;
		}
		else{
			iter.moveForward();
		}
	}
}

int List::size() const{
	return count;
}

void printList(List& source, bool direction){
	if (direction == true){
		ListItr temp = source.first();

		while (!temp.isPastEnd()){
			cout << " " << temp.retrieve();
			temp.moveForward();
		}

		cout << "" << endl;
	}
	else{
		ListItr temp = source.last();
		while (!temp.isPastBeginning()){
			cout << " " << temp.retrieve();
			temp.moveBackward();
		}

		cout << "" << endl;
	}
}
