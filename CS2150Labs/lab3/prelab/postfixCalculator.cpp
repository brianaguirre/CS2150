/**
Brian Aguirre
lab3 
prelab
**/


#include "postfixCalculator.h"

using namespace std;

bool stacks::StringToInt(string &s, int &x){
	istringstream input(s);

	if (input>>x)
		return true;
	else
		return false;

}

void stacks::push(int x){
	stk.push(x);
}

void stacks::pop(){
	stk.pop();
}

int stacks::top(){
	return stk.top();
}

void stacks::add(){
	int x, y, add;
	x = stk.top();
	stk.pop();

	y = stk.top();
	stk.pop();

	add = x + y;
	stk.push(add);
}

void stacks::subtract(){
	int x, y, sub;
	x = stk.top();
	stk.pop();

	y = stk.top();
	stk.pop();

	sub = y-x;
	stk.push(sub);
}

