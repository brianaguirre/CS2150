/* Brian Aguirre */
/* ba5bx */
/* linkedlist.c */
/* 11/21/2014 */


#include <stdlib.h>


//CODE FROM TUTORIAL
//LIST
struct list{
	struct list_item *head;
};


//NODE VALUES AND DEFINITION:
struct list_item{
	struct list_item *prev, *next;
	int val;
};


//IMPLEMENTATION OF LIST:
int main(){

	//How many items within the list would you like?
	//Number of elements in list:
	int num; 

	printf("Enter the number of items you would like in your list: ");
	scanf("%d", &num);

	//Creates the first node within the linked list:
	struct list *myList = (struct list *) malloc(sizeof(struct list));
    myList->head = NULL;

    //VALUE THAT WILL BE PASSED ONTO LIST:
    struct list_item *temp;
    temp = myList->head;

    for(int i=1;i<=num; i++){
    	//Takes in the value input by user:
    	int tempVal;
    	printf("Please enter a value for a new element %d: ", i);
    	scanf("%d", &tempVal);

    	//Makes the new temp node the Head Node, and makes its next node
    	//the previous head;
   		temp = (struct list_item*) malloc(sizeof(struct list_item));

    	temp->val=tempVal;
    	temp->next = myList->head;
    	myList->head = temp;
    }

    //TEMP ITERATOR: Goes through the list
    struct list_item *itr = myList->head;

    //Goes one by one printing the value until end of list;
   	for (int i=0; i<num; i++){
    		printf("%d\n", itr->val);
    		itr = itr->next;
    }

    //Deallocates Data:
    free(myList);

	return 0;
}