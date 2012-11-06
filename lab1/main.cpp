//============================================================================
// Name        : main.cpp
// Author      : cnagy 
// Version     :
// Copyright   :
// Description : USED FOR TESTING VECTOR CLASS
//============================================================================

#include <iostream>
#include "vector.h"
using namespace std;

int main() {


    Vector v1 = Vector(9);
    v1.print();

    Vector v2 = v1;
    v2.print();

return 0;
}
