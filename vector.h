#include <iostream>
#include <stdio.h>
using namespace std;
#ifndef VECTOR_H_
#define VECTOR_H_

class Vector{

private:
	unsigned int* array;
	size_t size;

public:
	Vector();
	Vector(unsigned int);
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();

	&Vector operator=(const &Vector);
