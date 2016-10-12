/**
Brian Aguirre
lab3 
prelab
**/

#include "postfixCalculator.h"
#include <stack>
using namespace std;


int main(){

	int x = 2;
	int y = 4;

	stacks newStk;
	newStk.push(x);
	newStk.push(y);

	newStk.add();

	cout<< newStk.top() << endl;





	return 0;
}