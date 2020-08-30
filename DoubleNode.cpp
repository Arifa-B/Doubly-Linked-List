/*Arifa Baksh
This project implements a doubly linked list
This file defines the functions of the DoubleNode class.
*/

#include "DoubleNode.hpp"

template<class ItemType>
DoubleNode<ItemType>::DoubleNode() : behind(nullptr), forward(nullptr)
{
} // end default constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem) : entry(anItem), behind(nullptr), forward(nullptr) 
{
} // end constructor

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* lastNodePtr, DoubleNode<ItemType>* nextNodePtr) :
                entry(anItem), behind(lastNodePtr), forward(nextNodePtr)
{
} // end constructor

template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
   entry = anItem;
} // end setItem

template<class ItemType>
void DoubleNode<ItemType>::setLast(DoubleNode<ItemType>* lastNodePtr)
{
   behind = lastNodePtr;
}  //end setLast

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr)
{
   forward = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
   return entry;
} // end getItem

template<class ItemType>
DoubleNode<ItemType>* DoubleNode <ItemType>::getLast() const
{
   return behind;
} // end getLast

template<class ItemType>
DoubleNode<ItemType>* DoubleNode <ItemType>::getNext() const
{
   return forward;
} // end getNext
