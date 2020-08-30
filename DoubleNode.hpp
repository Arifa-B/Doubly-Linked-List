/*Arifa Baksh
This project implements a doubly linked list
This file declares the functions of the DoubleNode class.
*/

#ifndef DOUBLE_NODE_
#define DOUBLE_NODE_

template<class ItemType>
class DoubleNode
{
    private:
    ItemType entry; //item in node
    DoubleNode<ItemType>* behind; //points to the node before current node
    DoubleNode<ItemType>* forward; //points to the node after current node

    public:
        DoubleNode(); //default constructor
        DoubleNode(const ItemType& anItem); //parameterized constructor
        DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* lastNodePtr, DoubleNode<ItemType>* nextNodePtr); //parameterized constructor
        void setItem(const ItemType& anItem); //set item in node
        void setLast(DoubleNode<ItemType>* lastNodePtr);  //sets the node BEHIND current node
        void setNext(DoubleNode<ItemType>* nextNodePtr); //set the node AFTER current node
        ItemType getItem() const; //retrieves item in node
        DoubleNode<ItemType>* getLast() const; //pointer to node BEFORE current node
        DoubleNode<ItemType>* getNext() const; //pointer to node AFTER current node
};

#include "DoubleNode.cpp"
#endif