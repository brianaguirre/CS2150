/**
Brian Aguirre
lab3 
prelab
**/

#ifndef POSTFIX_CALCULATOR
#define POSTFIX_CALCULATOR

#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

class stacks{


public:
	stack<int> stk;
	int total;

	bool StringToInt(string &s, int &x);
	void add();
	void subtract();
	void multiply();
	void divide();
	void negate();

	void placeInStack();

	//DEFAULT:
	void push(int x);
	void pop();
	int top();


};

#endif

