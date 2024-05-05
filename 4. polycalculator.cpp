//#ifndef __POLYCALCULATOR_CPP
//#define __POLYCALCULATOR_CPP
//
//#include "polycalculator.h"
//#include <iostream>
//#include <fstream>
//
//template <class T>
//PolyCalculator<T>::PolyCalculator():list1(),list2()
//{}
//
//template <class T>
//PolyCalculator<T>::~PolyCalculator() {
//    // no need to implement anything here
//}
//
//template <class T>
//void PolyCalculator<T>::input(PolyCalculator<int>& p1) {
//    
//    //cout << "Enter the first polynomial expression: ";
//	string str1;
//    cin >> str1;
//    while (!parse(str1, *this))
//    {
//		//cout << "Invalid input. Please enter the polynomial expression again: ";
//		cin >> str1;
//    }
//    //cout << "Enter the second polynomial expression: ";
//    string str2;
//    cin >> str2;
//    while (!parse(str2, p1))
//    {
//        //cout << "Invalid input. Please enter the polynomial expression again: ";
//        cin >> str1;
//    }
//}
//
//template <class T>
//bool PolyCalculator<T>::parse(string str, PolyCalculator<int>& p1)
//{
//    if (!str.empty())
//    {
//        int size= str.size();
//        if (str[size - 1] == '^' || str[size - 1] == '+' || str[size - 1] == '-' || str[size - 1] == '*' || str[size - 1] == '/')
//			return false;
//        else
//        {
//			int i = 0;
//            int coefficient;
//            int power =0;
//            bool signFlag = false;
//            while (i < size) 
//            {
//                bool powerIn = false;
//                if (str[i] == '-')
//                {
//                    if (str[i + 1] == '+' || str[i + 1] == '-')
//                        return false;
//                    i++;
//                    signFlag = true;
//                }
//                if (str[i + 1] == '*' || str[i + 1] == '/' || str[i]==' ')
//                    return false;
//                if (str[i] == '+')
//                {
//                    if (str[i + 1] == '+' || str[i + 1] == '-')
//                        return false;
//					i++;
//                    continue;
//				}
//                
//                coefficient = 0;
//                bool loop = false;
//                while (str[i] >= '0' && str[i] <= '9')
//                {
//                    coefficient = coefficient * 10 + (str[i] - '0');
//                    i++;
//					loop = true;
//                }
//                if (coefficient == 0 && str[i] == 'x')
//					coefficient = 1;
//                
//                if (signFlag) {
//                    coefficient = -coefficient;
//                    signFlag = false;
//                }
//
//                if (loop || coefficient)
//                {
//                    p1.list1.insertAtTail(coefficient);
//                    loop = false;
//                }
//
//                if (str[i] == 'x')
//                {
//                    if ((i + 1 != size) && (str[i + 1] >= '0' && str[i + 1] <= '9'))
//                        return false;
//                    i++;
//                    continue;
//                }
//
//                power = 0;
//                if (str[i] == '^') 
//                {
//                    powerIn = true;
//                    if (i+1==size)
//                        return false;
//                    if (str[i-1]!='x')
//						return false;
//
//                    i++; // Skip '^'
//                    if (str[i] == ' ' || str[i] == '-')
//						return false;
//                    while (str[i] >= '0' && str[i] <= '9') 
//                    {
//                        power = power * 10 + (str[i] - '0');
//                        i++;
//                        loop = true;
//                    }
//                    if (str[i] == 'x')
//                        return false;
//                }
//                else 
//                {
//                    power = 1; // If power is not specified, assume it's 1
//                }
//                p1.list2.insertAtTail(power);
//                if ((i + 1 < size) && !(str[i + 1] >= '0' && str[i + 1] <= '9') && str[i + 1] != '^' && !(str[i + 1] == '+' || str[i + 1] == '-' ))
//                {
//                    return false;
//                }
//                if (!loop)
//                    i++;
//            }
//			return true;
//        }
//        return false;
//    }
//	return false;
//}
//
//template <class T>
//void PolyCalculator<T>::display(PolyCalculator<int>& p1)
//{
//    shared_ptr<ListItem<T>> tmpC = this->list1.getHead();
//    shared_ptr<ListItem<T>> tmpP = this->list2.getHead();
//    bool first = true;
//    if (this->list1.length() < 1)
//        goto x;
//    cout << "Exp1: ";
//    while (tmpC)
//    {
//        if (!first)
//        {   
//            if (tmpC->value >= 0)
//                cout << "+" << tmpC->value << "x";
//            else 
//                cout << tmpC->value << "x";
//        }
//        else
//            cout << tmpC->value << "x";
//        if (tmpP) 
//        {
//            cout << "^" << tmpP->value;
//            tmpP = tmpP->next;
//        }
//        tmpC = tmpC->next;
//        first = false;
//    }
//    cout << endl;
//    //p1
//    x:if (p1.list1.length() < 1)
//        return;
//    cout << "Exp2: ";
//
//    tmpC = p1.list1.getHead();
//    tmpP = p1.list2.getHead();
//    first = true;
//    while (tmpC)
//    {
//        if (!first)
//        {
//            if (tmpC->value >= 0)
//                cout << "+" << tmpC->value << "x";
//            else
//                cout << tmpC->value << "x";
//        }
//        else
//            cout << tmpC->value << 'x';
//        if (tmpP) {
//            cout << "^" << tmpP->value;
//            tmpP = tmpP->next;
//        }
//        tmpC = tmpC->next;
//        first = false;
//    }
//    return;
//}
//
//template <class T>
//void PolyCalculator<T>::add(PolyCalculator<int>& p1) {
//
//    shared_ptr<ListItem<T>> t1C = this->list1.getHead();
//    shared_ptr<ListItem<T>> t2C = p1.list1.getHead();
//    shared_ptr<ListItem<T>> t1P = this->list2.getHead();
//    shared_ptr<ListItem<T>> t2P = p1.list2.getHead();
//
//    PolyCalculator<int> result; 
//
//    while (t1C && t2C && t1P && t2P) {
//        if (t1P->value == t2P->value) {
//            result.list1.insertAtTail(t1C->value + t2C->value);
//            result.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t2C = t2C->next;
//            t1P = t1P->next;
//            t2P = t2P->next;
//        }
//        else if (t1P->value > t2P->value) {
//            result.list1.insertAtTail(t1C->value);
//            result.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t1P = t1P->next;
//        }
//        else {
//            result.list1.insertAtTail(t2C->value);
//            result.list2.insertAtTail(t2P->value);
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//    }
//
//    while (t1C && t1P) {
//        result.list1.insertAtTail(t1C->value);
//        result.list2.insertAtTail(t1P->value);
//        t1C = t1C->next;
//        t1P = t1P->next;
//    }
//
//    while (t2C && t2P) {
//        result.list1.insertAtTail(t2C->value);
//        result.list2.insertAtTail(t2P->value);
//        t2C = t2C->next;
//        t2P = t2P->next;
//    }
//
//    shared_ptr<ListItem<T>> tmpC = result.list1.getHead();
//    shared_ptr<ListItem<T>> tmpP = result.list2.getHead();
//
//    bool first = true;
//    if (result.list1.length() < 1)
//        return;
//    cout << "Exp 1 + Exp 2 = ";
//    while (tmpC)
//    {
//        if (tmpC->value == 0)
//        {
//            tmpC = tmpC->next;
//            tmpP = tmpP->next;
//            continue;
//        }
//        if (!first)
//        {
//            if (tmpC->value > 0)
//                cout << "+" << tmpC->value << "x";
//            else
//                cout << tmpC->value << "x";
//        }
//        else
//            cout << tmpC->value << "x";
//        if (tmpP)
//        {
//            cout << "^" << tmpP->value;
//            tmpP = tmpP->next;
//        }
//        tmpC = tmpC->next;
//        first = false;
//    }
//}
//
//template <class T>
//LinkedList<T>& PolyCalculator<T>::getList1() {
//    return list1;
//}
//
//template <class T>
//LinkedList<T>& PolyCalculator<T>::getList2() {
//    return list2;
//}
//
//template <class T>
//void PolyCalculator<T>::sub(PolyCalculator<int>& p1) {
//    shared_ptr<ListItem<T>> t1C = this->list1.getHead();
//    shared_ptr<ListItem<T>> t2C = p1.list1.getHead();
//    shared_ptr<ListItem<T>> t1P = this->list2.getHead();
//    shared_ptr<ListItem<T>> t2P = p1.list2.getHead();
//
//    PolyCalculator<int> result;
//    while (t1C && t2C && t1P && t2P) {
//        if (t1P->value == t2P->value) {
//            result.list1.insertAtTail(t1C->value - t2C->value);
//            result.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t2C = t2C->next;
//            t1P = t1P->next;
//            t2P = t2P->next;
//        }
//        else if (t1P->value > t2P->value) {
//            result.list1.insertAtTail(t1C->value);
//            result.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t1P = t1P->next;
//        }
//        else {
//            result.list1.insertAtTail(-t2C->value);
//            result.list2.insertAtTail(t2P->value);
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//    }
//    while (t1C && t1P) {
//        result.list1.insertAtTail(t1C->value);
//        result.list2.insertAtTail(t1P->value);
//        t1C = t1C->next;
//        t1P = t1P->next;
//    }
//    while (t2C && t2P) {
//        result.list1.insertAtTail(t2C->value);
//        result.list2.insertAtTail(t2P->value);
//        t2C = t2C->next;
//        t2P = t2P->next;
//    }
//    shared_ptr<ListItem<T>> tmpC = result.list1.getHead();
//    shared_ptr<ListItem<T>> tmpP = result.list2.getHead();
//    bool first = true;
//    if (result.list1.length() < 1)
//        return;
//    cout << "Exp 1 - Exp 2 = ";
//    while (tmpC)
//    {
//        if (tmpC->value == 0)
//        {
//            tmpC = tmpC->next;
//            tmpP = tmpP->next;
//            continue;
//        }
//        if (!first)
//        {
//            if (tmpC->value >= 0)
//                cout << "+" << tmpC->value << "x";
//            else
//                cout << tmpC->value << "x";
//        }
//        else
//            cout << tmpC->value << "x";
//        if (tmpP)
//        {
//            cout << "^" << tmpP->value;
//            tmpP = tmpP->next;
//        }
//        tmpC = tmpC->next;
//        first = false;
//    }
//}
//
//template <class T>
//void PolyCalculator<T>::mul(PolyCalculator<int>& p1) {
//
//    shared_ptr<ListItem<T>> t1C = this->list1.getHead();
//    shared_ptr<ListItem<T>> t2C = p1.list1.getHead();
//    shared_ptr<ListItem<T>> t1P = this->list2.getHead();
//    shared_ptr<ListItem<T>> t2P = p1.list2.getHead();
//
//    PolyCalculator<int> result; 
//    while (t1C && t1P) {
//        while (t2C && t2P) {
//            result.list1.insertAtTail(t1C->value * t2C->value);
//            result.list2.insertAtTail(t1P->value + t2P->value);
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//        t1C = t1C->next;
//        t1P = t1P->next;
//        t2C = p1.list1.getHead();
//        t2P = p1.list2.getHead();
//    }
//    result.sorting();
//
//
//    shared_ptr<ListItem<T>> tmpC = result.list1.getHead();
//    shared_ptr<ListItem<T>> tmpP = result.list2.getHead();
//    bool first = true;
//    if (result.list1.length() < 1)
//        return;
//    cout << "Exp 1 * Exp 2 = ";
//    while (tmpC)
//    {
//        if (tmpC->value == 0)
//        {
//            tmpC = tmpC->next;
//            tmpP = tmpP->next;
//            continue;
//        }
//        if (!first)
//        {
//            if (tmpC->value >= 0)
//                cout << "+" << tmpC->value << "x";
//            else
//                cout << tmpC->value << "x";
//        }
//        else
//            cout << tmpC->value << "x";
//        if (tmpP)
//        {
//            cout << "^" << tmpP->value;
//            tmpP = tmpP->next;
//        }
//        tmpC = tmpC->next;
//        first = false;
//    }
//
//
//}
//
//template <class T>
//void PolyCalculator<T>::readData(string filename, PolyCalculator<int>& p1) {
//   
//    this->list1.nullHead();
//    p1.list1.nullHead();
//    this->list2.nullHead();
//    p1.list2.nullHead();
//    ifstream file;
//    file.open(filename);
//    if (!file.is_open())
//    {
//        cout << "File not found" << endl;
//        return;
//    }
//    else {
//        string a;
//        getline(file, a);
//        this->parse(a, *this);
//        getline(file, a);
//        p1.parse(a, p1);
//        file.close();
//    }
//}
//
//template <class T>
//void PolyCalculator<T>::writeData(string filename, PolyCalculator<int>& p1) {
//
//    ofstream file;
//    file.open(filename);
//    if (!file.is_open())
//    {
//        cout << "File not found" << endl;
//        return;
//    }
//    else {
//        shared_ptr<ListItem<T>> tmpC = this->list1.getHead();
//        shared_ptr<ListItem<T>> tmpP = this->list2.getHead();
//
//        bool first = true;
//        file << "Exp1 = ";
//        while (tmpC != NULL)
//        {
//            if (!first)
//            {
//                if (tmpC->value >= 0)
//                    file << "+" << tmpC->value << "x";
//                else
//                    file << tmpC->value << "x";
//            }
//            else
//                file << tmpC->value << "x";
//            if (tmpP)
//            {
//                file << "^" << tmpP->value;
//                tmpP = tmpP->next;
//            }
//            tmpC = tmpC->next;
//            first = false;
//        }
//        file << endl;
//        file << "Exp2 = ";
//        tmpC = p1.list1.getHead();
//        tmpP = p1.list2.getHead();
//        first = true;
//        while (tmpC)
//        {
//            if (!first)
//            {
//                if (tmpC->value >= 0)
//                    file << "+" << tmpC->value << "x";
//                else
//                    file << tmpC->value << "x";
//            }
//            else
//                file << tmpC->value << 'x';
//            if (tmpP) {
//                file << "^" << tmpP->value;
//                tmpP = tmpP->next;
//            }
//            tmpC = tmpC->next;
//            first = false;
//        }
//        file << endl;
//
//
//
//
//        shared_ptr<ListItem<T>> t1C = this->list1.getHead();
//        shared_ptr<ListItem<T>> t2C = p1.list1.getHead();
//        shared_ptr<ListItem<T>> t1P = this->list2.getHead();
//        shared_ptr<ListItem<T>> t2P = p1.list2.getHead();
//        PolyCalculator<int> result1;
//        while (t1C && t2C && t1P && t2P) {
//            if (t1P->value == t2P->value) {
//                result1.list1.insertAtTail(t1C->value + t2C->value);
//                result1.list2.insertAtTail(t1P->value);
//                t1C = t1C->next;
//                t2C = t2C->next;
//                t1P = t1P->next;
//                t2P = t2P->next;
//            }
//            else if (t1P->value > t2P->value) {
//                result1.list1.insertAtTail(t1C->value);
//                result1.list2.insertAtTail(t1P->value);
//                t1C = t1C->next;
//                t1P = t1P->next;
//            }
//            else {
//                result1.list1.insertAtTail(t2C->value);
//                result1.list2.insertAtTail(t2P->value);
//                t2C = t2C->next;
//                t2P = t2P->next;
//            }
//        }
//        while (t1C && t1P) {
//            result1.list1.insertAtTail(t1C->value);
//            result1.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t1P = t1P->next;
//        }
//        while (t2C && t2P) {
//            result1.list1.insertAtTail(t2C->value);
//            result1.list2.insertAtTail(t2P->value);
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//        tmpC = result1.list1.getHead();
//        tmpP = result1.list2.getHead();
//        first = true;
//        if (result1.list1.length() < 1)
//            return;
//        file << "Exp1 + Exp2 = ";
//        while (tmpC)
//        {
//            if (tmpC->value == 0)
//            {
//                tmpC = tmpC->next;
//                tmpP = tmpP->next;
//                continue;
//            }
//            if (!first)
//            {
//                if (tmpC->value > 0)
//                    file << "+" << tmpC->value << "x";
//                else
//                    file << tmpC->value << "x";
//            }
//            else
//                file << tmpC->value << "x";
//            if (tmpP)
//            {
//                file << "^" << tmpP->value;
//                tmpP = tmpP->next;
//            }
//            tmpC = tmpC->next;
//            first = false;
//        }
//        file << endl;
//
//
//
//
//
//        PolyCalculator<int> result2;
//
//
//        t1C = this->list1.getHead();
//        t2C = p1.list1.getHead();
//        t1P = this->list2.getHead();
//        t2P = p1.list2.getHead();
//        LinkedList<int> tmp = result2.getList1();
//        LinkedList<int> tmp2 = result2.getList2();
//        while (tmp.length() > 0)
//        {
//            tmp.deleteHead();
//            tmp2.deleteHead();
//        }
//        while (t1C && t2C && t1P && t2P) {
//            if (t1P->value == t2P->value) {
//                result2.list1.insertAtTail(t1C->value - t2C->value);
//                result2.list2.insertAtTail(t1P->value);
//                t1C = t1C->next;
//                t2C = t2C->next;
//                t1P = t1P->next;
//                t2P = t2P->next;
//            }
//            else if (t1P->value > t2P->value) {
//                result2.list1.insertAtTail(t1C->value);
//                result2.list2.insertAtTail(t1P->value);
//                t1C = t1C->next;
//                t1P = t1P->next;
//            }
//            else {
//                result2.list1.insertAtTail(-t2C->value);
//                result2.list2.insertAtTail(t2P->value);
//                t2C = t2C->next;
//                t2P = t2P->next;
//            }
//        }
//        while (t1C && t1P) {
//            result2.list1.insertAtTail(t1C->value);
//            result2.list2.insertAtTail(t1P->value);
//            t1C = t1C->next;
//            t1P = t1P->next;
//        }
//        while (t2C && t2P) {
//            result2.list1.insertAtTail(t2C->value);
//            result2.list2.insertAtTail(t2P->value);
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//        tmpC = result2.list1.getHead();
//        tmpP = result2.list2.getHead();
//        first = true;
//        if (result2.list1.length() < 1)
//            return;
//        //writing subtraction
//        file << "Exp1 - Exp2 = ";
//        while (tmpC)
//        {
//            if (tmpC->value == 0)
//            {
//                tmpC = tmpC->next;
//                tmpP = tmpP->next;
//                continue;
//            }
//            if (!first)
//            {
//                if (tmpC->value >= 0)
//                    file << "+" << tmpC->value << "x";
//                else
//                    file << tmpC->value << "x";
//            }
//            else
//                file << tmpC->value << "x";
//            if (tmpP)
//            {
//                file << "^" << tmpP->value;
//                tmpP = tmpP->next;
//            }
//            tmpC = tmpC->next;
//            first = false;
//        }
//
//
//
//
//        PolyCalculator<int> result3;
//
//
//
//
//
//
//
//        t1C = this->list1.getHead();
//        t2C = p1.list1.getHead();
//        t1P = this->list2.getHead();
//        t2P = p1.list2.getHead();
//        tmp = result3.getList1();
//        tmp2 = result3.getList2();
//        while (tmp.length() > 0)
//        {
//            tmp.deleteHead();
//            tmp2.deleteHead();
//        }
//        while (t1C && t1P) {
//            while (t2C && t2P) {
//                result3.list1.insertAtTail(t1C->value * t2C->value);
//                result3.list2.insertAtTail(t1P->value + t2P->value);
//                t2C = t2C->next;
//                t2P = t2P->next;
//            }
//            t1C = t1C->next;
//            t1P = t1P->next;
//            t2C = p1.list1.getHead();
//            t2P = p1.list2.getHead();
//        }
//        result3.sorting();
//        tmpC = result3.list1.getHead();
//        tmpP = result3.list2.getHead();
//        first = true;
//        if (result3.list1.length() < 1)
//            return;
//        file << "\nExp1 * Exp2 = ";
//        while (tmpC)
//        {
//            if (tmpC->value == 0)
//            {
//                tmpC = tmpC->next;
//                tmpP = tmpP->next;
//                continue;
//            }
//            if (!first)
//            {
//                if (tmpC->value >= 0)
//                    file << "+" << tmpC->value << "x";
//                else
//                    file << tmpC->value << "x";
//            }
//            else
//                file << tmpC->value << "x";
//            if (tmpP)
//            {
//                file << "^" << tmpP->value;
//                tmpP = tmpP->next;
//            }
//            tmpC = tmpC->next;
//            first = false;
//        }
//        file << endl;
//
//        file.close();
//    }
//}
//
//template <class T>
//void  PolyCalculator<T>::deleteElement(T coeff, T exp)
//{
//    shared_ptr<ListItem<T>> t1C = list1.getHead();
//    shared_ptr<ListItem<T>> t1P = list2.getHead();
//
//    if (!t1C || !t1P)
//        return;
//    if (t1C->value == coeff && t1P->value == exp)
//    {
//        list1.deleteHead();
//        list2.deleteHead();
//    }
//    else
//    {
//        while (t1C && t1P)
//        {
//            if (t1C->next && t1P->next && t1C->next->value == coeff && t1P->next->value == exp)
//            {
//				t1C->next = t1C->next->next;
//				t1P->next = t1P->next->next;
//				return;
//			}
//			t1C = t1C->next;
//			t1P = t1P->next;
//		}
//    }
//
//}
//
//template <class T>
//void  PolyCalculator<T>::sorting()
//{
//    shared_ptr<ListItem<T>> t1C = this->list1.getHead();
//    shared_ptr<ListItem<T>> t1P = this->list2.getHead();
//    //private members
//
//    PolyCalculator<int> result;
//    while (t1P)
//    {
//        shared_ptr<ListItem<T>> t2P = t1P->next;
//        shared_ptr<ListItem<T>> t2C = t1C->next;
//        int coeff = t1C->value;
//        while (t2P)
//        {
//            if (t1P->value == t2P->value)
//            {
//                coeff += t2C->value;
//                deleteElement(t2C->value,t2P->value);
//            }
//            t2C = t2C->next;
//            t2P = t2P->next;
//        }
//        result.getList1().insertAtTail(coeff);
//        result.getList2().insertAtTail(t1P->value);
//        
//        
//        t1P = t1P->next;
//        t1C = t1C->next;
//    }
//
//    
//    t1C = result.getList1().getHead();
//    t1P = result.getList2().getHead();
//    
//    bool swap = true;
//    int len = result.getList1().length() , i = 0;
//    while (swap || i<len)
//    {
//        swap = false;
//        if (t1C->next && t1P->next && t1P->value < t1P->next->value)
//        {
//            int a = t1C->value;
//            int b = t1P->value;
//            t1C->value = t1C->next->value;
//            t1P->value = t1P->next->value;
//            t1C->next->value = a;
//            t1P->next->value = b;
//            swap = true;
//            i = 0;
//            t1C = result.getList1().getHead();
//            t1P = result.getList2().getHead();
//        }
//        else
//        {
//			t1C = t1C->next;
//			t1P = t1P->next;
//		}
//        i++;
//    }
//    
//    
//    this->getList1().nullHead();
//    this->getList2().nullHead();
//
//    t1C = result.getList1().getHead();
//    t1P = result.getList2().getHead();
//
//    while (t1C && t1P)
//    {
//        this->list1.insertAtTail(t1C->value);
//        this->list2.insertAtTail(t1P->value);
//        t1C = t1C->next;
//        t1P = t1P->next;
//    }
//
//}
//
//#endif
