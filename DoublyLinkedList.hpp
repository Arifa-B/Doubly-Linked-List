/*Arifa Baksh
This project implements a doubly linked list
This file declares the functions of the DoublyLinkedList class.
*/

#ifndef DOUBLY_LINKED_LIST_
#define DOUBLY_LINKED_LIST_
//import necessary files
#include "DoubleNode.hpp"

template<class ItemType>
class DoublyLinkedList : public DoubleNode<ItemType>
{
private:
    DoubleNode<ItemType>* headPtr; //start of the doubly linked list
    int itemCount; //how many nodes in the doubly linked list
   
public:
	DoublyLinkedList(); //default constructor
    DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); // Copy constructor
    virtual ~DoublyLinkedList();                       // Destructor
    bool insert(const ItemType& item, const int& position); //insert item at index position in the list
    bool remove(const int& position); //remove node at index position
    int getSize() const; //return number of nodes in list
    DoubleNode<ItemType>* getHeadPtr() const; //return copy of headptr
    DoubleNode<ItemType>* getAtPos(const int& pos) const; //returns pointer to node located at index pos
    bool isEmpty() const; //returns if the list is empty
    void clear(); //clears the list
    void display() const; //prints contents of list in order
    void displayBackwards() const; //prints contents of list backwards
   DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_List);  //creates list of nodes from current list and passed in list

}; // end DoublyLinkedList

#include "DoublyLinkedList.cpp"
#endif
