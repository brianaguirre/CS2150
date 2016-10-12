/**
Brian Aguirre
ba5bx
threexinput.cpp
November 15, 2014
*/

#include <string>
#include <iostream>
#include "timer.h"

using namespace std;

//GET METHOD:
extern "C" int threexplusone(int);

/**  
LOGIC OF THE X86 CODE:
int threexplusone(int x){
	if (x == 1){
		return 0;
	}
	else if (x % 2 == 0){
		return threexplusone(x/2) + 1;
	}
	else{
		return threexplusone(3*x + 1) + 1;
	}
}
*/

int main(){
	//REQUIRED VARIABLES:
	int x; //Input number by user
	int n; //Time of calculations within the loop
	double time; //Time it took for calculations to be done
	timer t; //timer object wil retreives time


	//GET INPUT:
	cout << "Please enter a number:" << endl;
	cin >> x;
	cout << "Now enter how many times to do calculations: " <<endl;
	cin >> n;

	//CALCULATES TIME:
	t.start();
	for (int i=0; i<n; i++){
		threexplusone(x);
	}	
	t.stop();

	time = t.getTime();

	//OUTPUT RESULTS:
	cout << "Number of steps to reach 1: " << threexplusone(x) << endl;
	cout << "Time: " << (time/n) << endl;

	return 0;

}


