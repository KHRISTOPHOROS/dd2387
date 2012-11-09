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
#include <algorithm>
using namespace std;

void printVector(Vector<int>& vectorIn){
    int size = vectorIn.size();
    int trueSize = vectorIn.getTrueSize();
    cout<<"size: "<<size<<endl;
    cout<<"trueSize: "<<trueSize<<endl;
    cout<<"vector: ";
    for(int i=0;i<size;++i){
        cout<<vectorIn[i]<<" ";
    }cout<<endl;
}

void printArray(int* arrayIn,int sizeIn){
    int size = sizeIn/sizeof(arrayIn[0]);
    for(int i=0;i<size;++i){
        cout<<arrayIn[i]<<" ";
    }cout<<endl;

}

int main() {
    Vector<int> A = Vector<int>(3);
    A[2] = 7;

    Vector<int> B = A;
    A[0] = 7;
    B.print();
    A.print();

    Vector<int> a = Vector<int>(2);
    a[0] = 88;
    a.print();
    a = a;
    a.print();

    Vector<int> v1 = Vector<int>(9);
    v1[0] = 7;
    v1.print();
    Vector<int> v2 = v1;
    v2.print();
    int array[] = {1,2,3,4,5};
    cout<<array[1]<<endl;
    cout<<"v2 ? {7,7,7,8};"<<endl;
    v2 = {7,7,7,8};
    v2[0] = 1;
    int x = v2[0];

    cout<<A[2]<<endl;
    cout<<A[1]<<endl;

    Vector<string> s = Vector<string>(10);
    cout<<s[0]<<endl;
    s[0] = "NOTHING";
    cout<<s[0]<<endl;

    //TESTING DEEP COPYING
    cout<<"########## COPYING ##########"<<endl;
    Vector<Vector<int>> vv = Vector<Vector<int>>(10);
    Vector<int> ww = Vector<int>(10,7);
    Vector<Vector<int>> xx = Vector<Vector<int>>(10,Vector<int>(10,7));

    cout<<"xx[0][0]: "<<xx[0][0]<<endl<<"xx[0][1]: "<<xx[0][1]<<endl;
    vv[0] = Vector<int>(10,1);
    cout<<vv[0][0]<<endl;
    vv = xx;

    cout<<vv[0][0]<<endl;
    vv[0][0] = 8;
    cout<<vv[0][0]<<endl;
    cout<<xx[0][0]<<endl;

    //TESTING PUSH_BACK
    cout<<"########## PUSH_BACK ##########"<<endl;
    Vector<int> integers = Vector<int>(0,7);
    printVector(integers);

    for(int i=0;i<10;++i){
        integers.push_back(3);
        printVector(integers);
    }

    integers[9] = 8;
    printVector(integers);
    integers.push_back(99);
    printVector(integers);
//    integers[11] = 1;


//TESTING INSERT 
    cout<<"########## INSERT ##########"<<endl;
    cout<<"INSERT"<<endl;
    Vector<int> viktor = Vector<int>(10);
    for(int i=0;i<10;++i){
        viktor[i] = i;
    }
    printVector(viktor);
    viktor.insert(0,77);
    printVector(viktor);
    viktor.insert(11,77);
    printVector(viktor);
    viktor.insert(11,88);
    printVector(viktor);
    //viktor.insert(33,33);

//TESTING ERASE
    cout<<"########## ERASE ##########"<<endl;
    Vector<int> vaktor; vaktor = {0,1,2,3,4,5,6,7,8,9};
    printVector(vaktor);
    vaktor.erase(4);
    printVector(vaktor);
    vaktor.erase(8);
    printVector(vaktor);
    vaktor.erase(0);
    printVector(vaktor);

//TESTING CLEAR
    cout<<"########## CLEAR ##########"<<endl;
    Vector<int> vektor = Vector<int>(10,8);
    printVector(vektor);
    vektor.clear();
    vektor.clear();
    printVector(vektor);
    vektor.push_back(7);
    printVector(vektor);
    vektor.insert(0,3);
    printVector(vektor);

//TESTING SORT
    Vector<int> voktor = Vector<int>(100,0); voktor = {1,5,3,6,0,8,7,9,2,4};
    printVector(voktor);
    voktor.sort(true);
    printVector(voktor);
    voktor = {1,5,3,6,0,8,7,9,2,4};
    printVector(voktor);
    voktor.sort(false);
    printVector(voktor);

//TESTING EXISTS
cout<<"########## SORT ##########"<<endl;
int mario = 78;
int* luigi = &mario;

cout<<"mario: "<<mario<<endl;
cout<<"&mario: "<<&mario<<endl;
cout<<"luigi: "<<luigi<<endl;
cout<<"*luigi: "<<*luigi<<endl;
cout<<"&luigi: "<<&luigi<<endl;
cout<<endl;

cout<<"sizeof(int): "<<sizeof(3)<<endl;
int holder[] = {1,2,7,4,5};
int* bolder = std::find(holder,holder+5,7);
cout<<"holder: \t"<<holder<<endl;
cout<<"bolder: \t"<<bolder<<endl;
cout<<"holder+5:\t"<<holder+5<<endl;
cout<<"*bolder:\t"<<*bolder<<endl;
cout<<"&bolder:\t"<<&bolder<<endl;
    
    Vector<int> vaktar = Vector<int>(10,0);
    vaktar = {0,1,2,3,4,5,6,7,8,9};
    printVector(vaktar);
    if(vaktar.exists(7)){ cout<<"FOUND"<<endl; }
    else{ cout<<"NOT FOUND"<<endl; }

//TESTING CONST
cout<<"########## CONST ##########"<<endl;
const Vector<int> constantine = Vector<int>(10,7);
Vector<int> cop = constantine;
cout<<constantine[0]<<endl;
//constantine[0] = 3; //GIVES COMPILE ERROR AS WANTED
cop[0] = 3;
cop[1] = constantine[3];

cop.clear();

int tre = 3;
int ett = 1;
Vector<int> bag = Vector<int>(2);
cout<<"hej"<<endl;
bag[0] = tre;
bag[1] = ett;
printVector(bag);
bag.clear();
printVector(bag);
cout<<ett<<endl;











return 0;}


















