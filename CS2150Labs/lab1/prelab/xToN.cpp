/**
Brian Aguirre
ba5bx
prelab1
**/

#include <iostream>
using namespace std;

//RECURSIVE EXPONENT:
//REVIEWED **:
int xton(int x, int n){
	if (n<=0){
		return 1;
	}
	return x*xton(x, --n);
}

int main(){
	int x;
	int y;

	cout << "This program computes the power of one number to another: i.e. x ^ y." << endl;
	
	cout << "Please enter the base number:'x'" << endl;
	cin >> x;

	cout << "Now enter the exponent: 'y'" << endl;
	cin >> y;

	//CALCULATIONS:
	cout << "Total: ";
	cout << xton(x, y) << endl;

}