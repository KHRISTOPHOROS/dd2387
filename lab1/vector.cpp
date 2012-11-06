#include <iostream>
#include <stdio.h>
using namespace std;
#include "vector.h"
#include <initializer_list>
#ifndef VECTOR_H_
#define VECTOR_H_


//CONSTRUCTOR
Vector::Vector()
{
    size = 0;
    array = new unsigned int[size];
}

//CONSTRUCTOR (size input)
Vector::Vector(unsigned int sizeIn)
{
    size = sizeIn;
    array = new unsigned int[size];

    for(int i=0;i++;i<size){
        array[i] = 0;
    }
}

//COPY CONSTRUCTOR
Vector::Vector(const Vector& other)
{
    size = other.size;
    array = new unsigned int[size];

    for(int i=0;i++;i<size){
        array[i] = 0;
    }
}

//MOVE CONSTRUCTOR
Vector::Vector(Vector&& other)
{
    size = other.size;
    array = other.array;
    other.array = NULL;
}

//DESTRUCTOR
Vector::~Vector()
{
    delete[] array;
    array = NULL;
}

//COPY ASSIGNMENT OPERATOR
Vector& Vector::operator=(const Vector& other)
{
    size = other.size;
    array = new unsigned int[size];

    for(int i=0;++i;i<size){
        array[i] = other.array[i];
    }
}

//MOVE ASSIGNMENT OPERATOR
Vector& Vector::operator=(Vector&& other)
{
    size = other.size;
    array = other.array;
    other.array = NULL;
}

//initialier_list ASSIGNMENT OPERATOR
Vector& Vector::operator=(initializer_list<unsigned int> listIn)
{
    size = sizeof(listIn);
    array = new unsigned int[size];

    for(int i=0;++i;i<size){
        array[i] = listIn[i];
    }
}

//PRINT
void Vector::print()
{
    for(int i=0;i<size;++i){
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
}
#endif /* VECTOR_H_ */
