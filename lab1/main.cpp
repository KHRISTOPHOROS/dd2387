//============================================================================
// Name        : main.cpp
// Author      : cnagy 
// Version     :
// Copyright   :
// Description : USED FOR TESTING VECTOR CLASS
//============================================================================

#include <iostream>
#include "vector.h"
#include <list>
using namespace std;

int main() {
    Vector A = Vector(3);
    A[2] = 7;

    Vector B = A;
    A[0] = 7;
    B.print();
    A.print();

    Vector a = Vector(2);
    a[0] = 88;
    a.print();
    a = a;
    a.print();

    Vector v1 = Vector(9);
    v1[0] = 7;
    v1.print();

    Vector v2 = v1;
    v2.print();

    int array[] = {1,2,3,4,5};
    cout<<array[1]<<endl;
    v2 = {7,7,7,8};
    v2[0] = 1;
    int x = v2[0];


return 0;}
