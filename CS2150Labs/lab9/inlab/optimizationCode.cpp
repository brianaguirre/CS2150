/**
Brian Aguirre
ba5bx
optimizationCode.cpp
11/19/2014
*/

#include <iostream>
using namespace std;

int addTwo(int x, int y){
	return x+y;
}

int main (){
	for (int i=0; i<10; i++){
		cout << addTwo(i, i+1) << endl;
	}

}