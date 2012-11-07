#include <iostream>
#include <stdio.h>
#include <initializer_list>
using namespace std;

class Vector{

private:
	unsigned int* array;                                //ARRAY FOR KEEPING THE ELEMENTS IN THE VECTOR
	size_t size;                                        //UNSIGNED INTEGER RETURNED BY sizeof

public:
	Vector();                                           //CONSTRUCTOR
	explicit Vector(unsigned int);                      //CONSTRUCTOR (size input)
	Vector(const Vector&);                              //COPY CONSTRUCTOR
	Vector(Vector&&);                                   //MOVE CONSTRUCTOR
	~Vector();                                          //DESTRUCTOR

    Vector& operator=(const Vector&);                   //COPY ASSIGNMENT OPERATOR
    Vector& operator=(Vector&&);                        //MOVE ASSIGNMENT OPERATOR
    Vector& operator=(initializer_list<unsigned int>);  //ASSGNMENT OPERATOR FOR INITIALIZER LIST
    unsigned int& operator[](const unsigned int);       //OVERLOADING THE [] OPERATOR
    unsigned int& operator[](const unsigned int) const; //OVERLOADING THE [] OPERATOR (const)
    void print() const;                                 //PRINTING ALL ELEMENTS IN array
};

