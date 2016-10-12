/**
Brian Aguirre
ba5bx
mathfun.cpp
November 1, 2014
**/

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int); 

int main() {

    int a;
    int b;
    int prdctResult;
    int pwrResult;

    cout << "Enter your first number (base of product or first number being multiplied):" << endl;
    cin >> a;

    cout << "Enter your first number (base of product or first number being multiplied):" << endl;
    cin >> b; 

    prdctResult = product(a, b);
    pwrResult = power(a, b); 
    cout << "Produc of " << a << " and " << b << " = " << prdctResult << endl;
    cout << "The power of " << a << " to " << b << " = " << pwrResult << endl;
    
return 0;

}