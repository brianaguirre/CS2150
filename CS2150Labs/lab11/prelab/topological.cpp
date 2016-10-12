/**
Brian Aguirre
ba5bx
topological.cpp
12/01/2014
*/



#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <string>
#include <stack>
#include <list>


using namespace std;

//USING NODES:
class sortNode{
public:
	sortNode(string value);

	void checkNext(sortNode* n);
	void goTo(string name);
	void addLink(sortNode* n1);
	void haveVisited();
	bool isItPresent(sortNode* n1, sortNode* n2, std::vector<sortNode*> v);
	void seenIt(vector<sortNode*> v);
	vector <sortNode*> nodes;
	vector <sortNode*> visited;
	vector <sortNode*> sorted;
	vector <sortNode*> edges;

	string val;
	int edge; 
	int position;
	bool linked;
};

sortNode::sortNode(string value){
	val = value;
	position = 0;
	int edge = 0;
	bool linked = false;
}

void sortNode::addLink(sortNode* n1){
	nodes.push_back(n1);
}

bool sortNode::isItPresent(sortNode* n1, sortNode* n2, vector<sortNode*> v){
	vector<sortNode*>::iterator i = v.begin();
	int localPos = 0;
	int placeInVec = 0;
	bool foundInVec = false;
	while (i!=v.end()){
		if ((*i)->val == n1->val){
			foundInVec = true;
			n1->position = placeInVec;
		}
		else if ((*i)->val != n1->val){

		}
	}
}

//INSPIRATION FOR CODE FROM REFERENCE PAGE FOR C++
//DOCUMENTATION ON SORTING AND DUPLICATE:
void sortNode::seenIt(vector<sortNode*> v){
	int size = v.size();
	bool *seenThis = new bool[size];

	for (int i=0; i< size; i++){
		seenThis[i]; false;
	}

	for (int i=0; i<size; i++){
		if (seenThis[i]==false){

		}
	}

}

void topologicalSorting();
vector <sortNode*> temp;
int localPos1;
int localPos2;
int vecPos1;
int vecPos2;
// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }


    //Check whether state of stream is good
    //ALGORITHM FROM CS2150 LECTURE NOTES AND SLIDES
    while (file.good()){
    	// read in two strings
    	string s1, s2;
    	file >> s1;
    	file >> s2;

    	//USED TO SEE IF AS LOOPING THROUGH THE VECTOR IF ADDED ALREADY:
    	bool seen1 = false;
    	if ((s1 == "0" && s1=="0")){
    		break;
    	}
    		// output those strings
    		//cout << s1 << endl;
    		//cout << s2 << endl;
    		//LOOP THROUGH VECTOR:
    	int whereIsIt1 = 0;
    	//CHECK TO SEE IF ELEMENTS IN TEMPORARY VECTOR HAS NODES WITH THE SPECIFIC STRING
    	//IF SO THEN YOU MAKE NOTE OF WHERE IT IS AND CHANGE IT'S VALUE TO TRUE
    	//THEN MOVE ON TO MAKE SURE WE FIND THE ONE THAT ONLY HAS ONE EDGE TO ANOTHER AND NO
    	//EDGE TO IT.
    	for (std::vector<sortNode*>::iterator i = temp.begin(); i!= temp.end(); ++i){
    			if ((*i)->val == s1){
    				vecPos1 = whereIsIt1;
    				seen1 = true;
    			}
    			else{
    				whereIsIt1++;
    			}
    	}
    		int counter = 0;
    		int localItr = 0;
    		vector<sortNode*>::iterator j = temp.begin();
    		bool isItPresent = false;

    	if (seen1 == false){
    		sortNode* x = new sortNode(s1);
    		temp.push_back(x);

    		//CHANGE THE SIZE INDEX1:
    		seen1 = (temp.size())-1;
    	}
    		/**while (i != temp.end()){

    			if (isItPresent == false && counter == temp.size()){
    				temp.push_back(x);
    			}
				counter++;
    			if ((*i)->val == x->val){
    				isItPresent = true;
    			}
    			}*/
    	int whereIsIt2 = 0;
    	bool seen2 = false;
  		for (std::vector<sortNode*>::iterator i = temp.begin(); i!= temp.end(); ++i){
    		//if ((*i)->val == x->val){
    				//DO NOTHING
    		//}

  			if ((*i)->val == s2){
				seen2 = true;
				vecPos2 = whereIsIt2;
			}
			else{
				whereIsIt2++;
			}
    		/**else{
    				temp.push_back(y);
    				y->position = counter;
    				counter++;

    		}*/
    	}
    	if(seen2 == false){
    		sortNode* y = new sortNode(s2);
    		temp.push_back(y);
    		seen2 = (temp.size()) - 1;
    	}

    	temp[vecPos2]->position++;
    	temp[vecPos1]->addLink(temp[vecPos2]);




    	}


    topologicalSorting();
    	
    for(vector<sortNode*>::iterator i = temp.begin(); i!=temp.end(); ++i){
    	cout<< (*i)->val << endl;
    }



    // string comparison done with ==, but not shown here
    // close the file before exiting
    file.close();


}


//ALGORITHM FROM CS2150 LECTURE NOTES AND SLIDES
void topologicalSorting(){
	vector<sortNode*> master;
	sortNode* temp1;
	sortNode* temp2;
	for (std::vector<sortNode*>::iterator i = temp.begin(); i!= temp.end(); ++i){
		temp1 = *i;
		if (temp1->position == 0){
			master.push_back(temp1);
		}
	}


	while (!master.empty()){
		temp1 = master.back();
		master.pop_back();

		cout << temp1->val << endl;

		int countPosition = 0;
		for (std::vector<sortNode*>::iterator i = temp.begin(); i!= temp.end(); ++i){
			//RECALCULATE VECTOR:
		}
		for(int i=0; i<temp1->nodes.size(); i++){
			temp2 = temp1->nodes[i];
			int localPosition = countPosition;
			temp2->position--;

			if (temp2->position == 0){
				master.push_back(temp2);
			}
		}
	}
}
