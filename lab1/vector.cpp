#include <iostream>
#include <stdio.h>
using namespace std;
#include "vector.h"
#include <initializer_list>
#include <stdexcept>
//size must be larger than the amount of elements to leave room for more

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

    for(int i=0;i<size;++i){
        array[i] = 0;
    }
}

//COPY CONSTRUCTOR
Vector::Vector(const Vector& other)
{
    size = other.size;
    array = new unsigned int[size];

    for(int i=0;i<size;++i){
        array[i] = other.array[i];
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
    if(&other != this){
        //DESTROY
        delete[] array;
        //ERASE
        array = NULL;
        //IMPROVE
        size = other.size;
        array = new unsigned int[size];

        for(int i=0;i<size;++i){
            array[i] = other.array[i];
        }
    }
}

//MOVE ASSIGNMENT OPERATOR
Vector& Vector::operator=(Vector&& other)
{
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    size = other.size;
    array = other.array;
    other.array = NULL;
}

//initialier_list ASSIGNMENT OPERATOR
Vector& Vector::operator=(initializer_list<unsigned int> listIn)
{
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    size = sizeof(listIn);
    array = new unsigned int[size];
    
    int i = 0;
    initializer_list<unsigned int>::iterator it;
    for(it=listIn.begin();it<listIn.end();++it){
        array[i] = *it;
        ++i;
    }
}

//OVERLOADING THE [] OPERATOR
unsigned int& Vector::operator[](const unsigned int nrIn)
{
    if(nrIn >= size){
        throw std::out_of_range ("OUT OF RANGE!!");
    }
    return array[nrIn];
}

//OVERLOADING THE [] OPERATOR (const)
unsigned int& Vector::operator[](const unsigned int nrIn) const
{
    if(nrIn >= size){
        throw std::out_of_range ("OUT OF RANGE!!");
    }
    return array[nrIn];
}

//PRINT
void Vector::print() const
{
    for(int i=0;i<size;++i){
        cout<<*(array+i)<<" ";
    }
    cout<<endl;
}
