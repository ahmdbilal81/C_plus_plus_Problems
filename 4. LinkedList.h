#ifndef __LIST_H
#define __LIST_H
#include <cstdlib>
using namespace std;

/* This class just holds a single data item. */
template <class T>
struct ListItem
{
    T value;
    //T pow;//to save power 
    shared_ptr<ListItem<T>> next;
    shared_ptr<ListItem<T>> prev;

    ListItem(T theVal)
    {
        this->value = theVal;
        //pow = 1;
        this->next = NULL;
        this->prev = NULL;
    }
    /*ListItem(T theVal,T pow)
    {
        this->value = theVal;
        this->pow = pow;
        pow = 1;
        this->next = NULL;
        this->prev = NULL;
    }*/
};

/* This is the generic List class */
template <class T>
class LinkedList
{
    shared_ptr<ListItem<T>> head;
    shared_ptr<ListItem<T>> tail;
    int size;

public:

    // Constructor
    LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList<T>& otherList);

    // Insertion Functions
    void insertAtHead(T item);
    void insertAtTail(T item);


    void nullHead();

    void insertAfter(T toInsert, T afterWhat);

    // Lookup Functions
    shared_ptr<ListItem<T>> getHead();
    shared_ptr<ListItem<T>> getTail();
    shared_ptr<ListItem<T>> searchFor(T item);

    // Deletion Functions
    void deleteHead();
    void deleteElement(T item);

    void deleteTail();

    // Utility Functions
    int length();

    void setHead(shared_ptr<ListItem<T>>& pt);
};

#endif
