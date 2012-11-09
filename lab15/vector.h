#include <iostream>
#include <stdio.h>
#include <initializer_list>
#include <algorithm>
using namespace std;
#include <stdexcept>

template <class Type>
class Vector{

private:
	Type* array;                                        //ARRAY FOR KEEPING THE ELEMENTS IN THE VECTOR
	size_t arraySize;                                   //UNSIGNED INTEGER FOR REPRESENTING SIZE
    static  const unsigned int steps=100;               //USED WHEN RESIZING ARRAY
    unsigned int trueSize;                              //THE DARK SECRET THAT USER MUST NOT KNOW ABOUT

public:
	Vector();                                           //CONSTRUCTOR
	explicit Vector(unsigned int);                      //CONSTRUCTOR (size input)
    Vector(unsigned int, Type);                         //CONSTRUCTOR (size,default)
	Vector(const Vector&);                              //COPY CONSTRUCTOR
	Vector(Vector&&);                                   //MOVE CONSTRUCTOR
	~Vector();                                          //DESTRUCTOR

    Vector<Type>& operator=(const Vector&);             //COPY ASSIGNMENT OPERATOR
    Vector<Type>& operator=(Vector&&);                  //MOVE ASSIGNMENT OPERATOR
    Vector<Type>& operator=(initializer_list<Type>);    //ASSGNMENT OPERATOR FOR INITIALIZER LIST
    Type& operator[](unsigned int);                     //OVERLOADING THE [] OPERATOR
    Type& operator[](unsigned int) const;               //OVERLOADING THE [] OPERATOR (const)
    
    void print() const;                                 //PRINTING ALL ELEMENTS IN array
    int size() const;                                   //RETURNS THE SIZE OF THE ARRAY (CAPACITY)
    int getTrueSize() const;                            //RETURNS THE TRUE SIZE OF THE ARRAY
    void push_back(Type);                               //ADD ELEMENT AT THE END OF ARRAY
    void insert(size_t, Type);                          //INSERTS ELEMENT AT SPECIFIED POSITION
    void erase(size_t);                                 //REMOVES ELEMENT AT i
    void clear();                                       //REMOVES ALL ELEMENTS
    void sort(bool);                                    //SORTS THE ELEMENTS ASCENDING OR DESCENDING
    bool exists(const Type&);                           //RETURNS TRUE IF ASKED ELEMENT IS IN ARRAY 
};
//size must be larger than the amount of elements to leave room for more
// REMOVE COUT, USE THAT OTHER THING INSTEAD

//CONSTRUCTOR
template <class Type>
Vector<Type>::Vector()
{
    arraySize = 0;
    trueSize = 0;
    array = new Type[arraySize];
}

//CONSTRUCTOR (size input)
template <class Type>
Vector<Type>::Vector(unsigned int sizeIn)
{
    arraySize = sizeIn;
    trueSize = sizeIn;
    array = new Type[arraySize];

    for(int i=0;i<arraySize;++i){
        array[i] = Type();
    }
}

//CONSTRUCTOR (size,default)
template <class Type>
Vector<Type>::Vector(unsigned int sizeIn, Type defaultIn)
{
    arraySize = sizeIn;
    trueSize = sizeIn;
    array = new Type[arraySize];

    for(int i=0;i<arraySize;++i){
        array[i] = defaultIn;                                       //USES COPY CONSTRUCTOR?
    }
}

//COPY CONSTRUCTOR
template <class Type>
Vector<Type>::Vector(const Vector& other)
{
    arraySize = other.arraySize;
    trueSize = other.trueSize;
    array = new Type[arraySize];     

    std::copy(other.array, other.array+arraySize, array);        //DEEP COPYING?
}

//MOVE CONSTRUCTOR
template <class Type>
Vector<Type>::Vector(Vector&& other)
{
    arraySize = other.arraySize;
    trueSize = other.trueSize;
    array = other.array;
    other.array = NULL;
}

//DESTRUCTOR
template <class Type>
Vector<Type>::~Vector()
{
    delete[] array;
    array = NULL;
}

//COPY ASSIGNMENT OPERATOR
template <class Type>
Vector<Type>& Vector<Type>::operator=(const Vector& other)
{
    if(&other != this){
        //DESTROY
        delete[] array;
        //ERASE
        array = NULL;
        //IMPROVE
        arraySize = other.arraySize;
        trueSize = other.trueSize;
        array = new Type[arraySize];

        std::copy(other.array, other.array+arraySize, array);        //DEEP COPYING?
    }
}

//MOVE ASSIGNMENT OPERATOR
template <class Type>
Vector<Type>& Vector<Type>::operator=(Vector&& other)
{
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    arraySize = other.arraySize;
    trueSize = other.trueSize;
    array = other.array;
    other.array = NULL;
}

//initialier_list ASSIGNMENT OPERATOR
template <class Type>
Vector<Type>& Vector<Type>::operator=(initializer_list<Type> listIn)
{
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    arraySize = listIn.size();
    trueSize = listIn.size();
    array = new Type[arraySize];
    
    int i = 0;
    //initializer_list<Type>::iterator it;
    for(auto it=listIn.begin();it<listIn.end();++it){
        array[i] = *it;                                                  //DEEP COPYING?
        ++i;
    }
}

//OVERLOADING THE [] OPERATOR
template <class Type>
Type& Vector<Type>::operator[](const unsigned int nrIn)
{
    if(nrIn >= arraySize){
        throw std::out_of_range ("OUT OF RANGE!!");
    }
    return array[nrIn];
}

//OVERLOADING THE [] OPERATOR (const)
template <class Type>
Type& Vector<Type>::operator[](const unsigned int nrIn) const
{
    if(nrIn >= arraySize){
        throw std::out_of_range ("OUT OF RANGE!!");
    }
    return array[nrIn];
}

//PRINT
template <class Type>
void Vector<Type>::print() const
{
    for(int i=0;i<arraySize;++i){
        cout<<&array[i]<<" ";
    }cout<<endl;
}

//SIZE
template <class Type>
int Vector<Type>::size() const
{
    return arraySize;
}

//GETTRUESIZE
template <class Type>
int Vector<Type>::getTrueSize() const
{
    return trueSize;
}

//PUSH_BACK
template <class Type>
void Vector<Type>::push_back(Type input)
{
    if(arraySize >= trueSize){                               //IF NEEDED - INCREASE SIZE OF ARRAY
       Type* temparray = new Type[arraySize +steps];         //CREATE TEMPORARY ARRAY WITH NEW SIZE
       std::copy(array,array+arraySize,temparray);           //COPY ARRAY TO TEMPORARY ARRAY
       
       //DESTROY
       delete[] array;
       //ERASE
       array = NULL;
       //IMPROVE
       array = new Type[arraySize+steps];                    //RESIZE ARRAY
       trueSize = arraySize+steps;                           //UPDATE THE ARRAY SIZE
       std::copy(temparray,temparray+arraySize,array);       //ARRAY IS NOW AS BEFORE BUT LARGER SIZE

       //DESTROY
       delete[] temparray;
       //ERASE
       temparray = NULL;
    }
    array[arraySize] = input;                                //ADDS THE NEW ELEMENT
    ++arraySize;

}

//INSERT
template <class Type>                                      //MAKE SURE INSERTION OUTSIDE THROWS EXCEPTION
void Vector<Type>::insert(size_t i, Type input)
{
    if(i > arraySize){                                       //IF TRYING TO INSERT OUTSIDE ARRAY
        throw std::out_of_range ("OUT OF RANGE!!");
    }

    if(i == arraySize){                                      //IF INSERTION IS AT THE END
        push_back(input);
        return;
    }

    if(arraySize==trueSize){                                 //RESIZE IF NEEDED
        trueSize = trueSize +steps;    
    }
    Type* temparray = new Type[trueSize];                    //TEMPORARY ARRAY
    std::copy(array,array+i,temparray);                      //COPIES THE PART BEFORE X (INCLUDING X)
    std::copy(array+(i-1),array+arraySize,temparray+i);      //COPIES THE PART AFTER X (INCLUDING X)
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    array = new Type[trueSize];
    std::copy(temparray,temparray+(arraySize+1),array);      //COPIES THE EXPANDED TEMPARRA INTO ARRAY
    array[i] = input;                                        //INSERTS X
    ++arraySize;

    //DESTROY
    delete[] temparray;
    //ERASE
    temparray = NULL;
    
}

//ERASE
template <class Type>
void Vector<Type>::erase(size_t i)
{                                                            //MEMORY LEAK?
    if(i >= arraySize){throw std::out_of_range ("TRYING TO REMOVE OUTSIDE ARRAY");}

    std::copy(array+i+1,array+arraySize,array+i);            //USE STD::MOVE?
    --arraySize;
}

//CLEAR
template <class Type>
void Vector<Type>::clear()
{
    //DESTROY
    delete[] array;
    //ERASE
    array = NULL;
    //IMPROVE
    arraySize = 0;
    trueSize = 0;
    array = new Type(arraySize);
}

//SORT
template <class Type>
void Vector<Type>::sort(bool ascending)
{
    if(ascending){
        std::sort(array,array+arraySize);
    }
    if(!ascending){
        std::sort(array,array+arraySize);
        std::reverse(array,array+arraySize);
    }
}

//EXISTS
template <class Type>
bool Vector<Type>::exists(const Type& objectIn)
{
    Type* objectPointer;
    objectPointer = std::find(array,array+arraySize,objectIn);
    if(*objectPointer == objectIn){
        return true;
    }
    else{
        return false;
    }
}



