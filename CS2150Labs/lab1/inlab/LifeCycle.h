/**
Brian Aguirre
prelab1
LifeCycle.h
**/

//H FILE CONTAINS CLASS DEFINITION
//VARIABLE AND FUNCTOON DEFINITION 

#ifndef LIFE_CYCLE
#define LIFE_CYCLE

#include <iostream>
#include <string>
using namespace std;

// ---------------------------------------------------  class definition
class MyObject {
public:
    static int numObjs;
    MyObject(const char *n = "--default--");      // default constructor
    MyObject(const MyObject& rhs);                // copy constructor
    ~MyObject();                                  // destructor
    string getName() const {
        return name;
    }
    void setName(const string newName) {
        name = newName;
    }
    friend ostream& operator<<(ostream& output, const MyObject& obj);
private:
    string name;
    int id;
};

#endif