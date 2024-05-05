#ifndef __POLYCALCULATOR_H
#define __POLYCALCULATOR_H

#include "LinkedList.cpp" 

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

template <class T>
class PolyCalculator
{
    LinkedList<T> list1;
    LinkedList<T> list2;

    //You may add more helper variables or helper functions
public:
    
    LinkedList<T>& getList1();
    LinkedList<T>& getList2();
   
    // Constructor
    PolyCalculator();

    void sorting();

    void deleteElement(T coeff, T exp);

    // Destructor
    ~PolyCalculator();

    //Required Methods

    // Input Function
    void input(PolyCalculator<int>& p1);

    // Display Function
    void display(PolyCalculator<int>& p1);

    // Addition Function
    void add(PolyCalculator<int>& p1);

    // Subtraction Function
    void sub(PolyCalculator<int>& p1);

    // Multiplication Function
    void mul(PolyCalculator<int>& p1);

    // Read Data from File Function
    void readData(string filename, PolyCalculator<int>& p1);

    // Write Data to File Function
    void writeData(string filename, PolyCalculator<int>& p1);

    // Parse Polynomial Expression Function
    bool parse(string str, PolyCalculator<int>& p1);

    //Your defined functions here
    
};

#endif
