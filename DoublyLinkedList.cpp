/*Arifa Baksh
This project implements a doubly linked list
This file defines the functions of the DoublyLinkedList class.
*/

#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
#include <cstddef>
#include <cstdlib>
#include<iostream>
using namespace std;

template<class ItemType> //DEFAULT CONSTRUCTOR
DoublyLinkedList<ItemType>::DoublyLinkedList() : headPtr(nullptr), itemCount(0)
{
}  //end default constructor

template<class ItemType> //COPY CONSTRUCTOR
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag) : headPtr(nullptr), itemCount(0)
{
   int j = 1;
   itemCount = aBag.itemCount; //get the number of nodes in list
   DoubleNode<ItemType>* origChainPtr = aBag.headPtr; //copy headptr of passed in chain
   if(origChainPtr == nullptr) //if the bag is empty
      {
         headPtr = nullptr;
      }
   else
   {
    while (origChainPtr != nullptr) //run as many times as the number of nodes in list
      {
        this->insert(origChainPtr->getItem(), j); //use insert function; takes node's item and position
        origChainPtr = origChainPtr->getNext(); //advances headptr
        j++; //increment counter
      }
   }
}  //end copy constructor

template<class ItemType> //DESTRUCTOR
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
   clear();
}  //end destructor

template<class ItemType> //INSERTS PASSED IN ITEM IN PASSED IN POSITION
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
   if (headPtr == nullptr) //if bag is empty
		{
			DoubleNode<ItemType>* nextNodePtr = new DoubleNode<ItemType>(); //create new node pointer
			nextNodePtr->setItem(item); //put item into the node
			nextNodePtr->setNext(nullptr);	//set the pointer after nextNodePtr to nullptr to signal end of chain
         nextNodePtr->setLast(nullptr); //being the first node, it should point backwards to nullptr
			headPtr = nextNodePtr; //headptr will now point to this newly added node
		}
   else
   {
   if (position < 1 || position > itemCount + 1) //check if the position is in the index range
      {
         return false;
      }
   else if (position == 1) //if the position is 1, make a new node and call that headptr [index starts at 1]
      {
         DoubleNode<ItemType>* newFront = new DoubleNode<ItemType>; //create new node
         newFront->setLast(nullptr);
         newFront->setNext(nullptr);
         newFront->setItem(item); //put item in new node
         DoubleNode<ItemType>* start = headPtr; //copy headptr
         
         newFront->setNext(start); //have the new node point forward to headptr
         start->setLast(newFront); //have the headptr point backwards to the new node
         headPtr = newFront; //reassign headptr to point to new node
      }
   else if (position == itemCount) //if the position same as the number of nodes
      {
         DoubleNode<ItemType>* newBack = new DoubleNode<ItemType>; //create new node
         newBack->setItem(item); //put new item in
         newBack->setLast(nullptr);
         newBack->setNext(nullptr);
         DoubleNode<ItemType>* looper = headPtr; //copy headptr to loop through list
         do 
         {
            looper = looper-> getNext();
         }
         while(looper->getNext() != nullptr); //keep advancing to the next node until you reach the last node

         DoubleNode<ItemType>* Secondtolast = looper->getLast(); //copy the second-to-last node
         looper->setLast(newBack); //have the old last node point backwards to the new node
         newBack->setNext(looper); //have the new node point forwards to the old last node
         newBack->setLast(Secondtolast); //have the new node point backwards to the second-to-last node
         Secondtolast->setNext(newBack); //have the second-to-last node point forward to the new node
      }

   else //if the position is in the MIDDLE
   {
      DoubleNode<ItemType>* insertion = new DoubleNode<ItemType>; //create new node
      insertion->setItem(item); //put item into new node
      insertion->setLast(nullptr);
      insertion->setNext(nullptr);
      DoubleNode<ItemType>* foundPos = headPtr; //copy headptr to loop through list
    
      for (int i = 2; i < position; i++) //already took care of position 1 case above, so start at 2
      {
         foundPos = foundPos->getNext(); //find the node with the index position
      }
      if (foundPos->getNext() != nullptr) //if the node is not the last node
         {
            foundPos->getNext()->setLast(insertion); //connects the node one after foundPos to new node
            insertion->setNext(foundPos->getNext()); //new node will now point to the node after foundPos
         }
      foundPos->setNext(insertion); //foundPos will now point forward to inserted node
      insertion->setLast(foundPos); //have inserted node point backwards to foundPos
   }
      }
   itemCount++; //size will increase after successful insertion
   return true;
}  //end insert

template<class ItemType> //REMOVES NODE AT PASSED IN POSITION
bool DoublyLinkedList<ItemType>::remove(const int& position) //here
{
   if (headPtr == nullptr) //can't remove a node from an empty list
      {
         return false;
      }
   else
   {
      if (position < 1 || position > itemCount + 1) //is the position in the index range?
      {
         return false;
      }
   else if (position == 1) //if you have to remove the first position
      {
         DoubleNode<ItemType>* findIndex = headPtr; //copy headptr to loop through list and find position
         if(headPtr->getNext() == nullptr) //if there is only one node in the list
            {
               delete findIndex;
               findIndex = nullptr;
            }
         else
         {
            headPtr = headPtr->getNext(); //move the headpointer forward
            headPtr->setLast(nullptr);
            delete findIndex;
            findIndex = nullptr;
         }
      }

   else if (position == itemCount) //if you want to remove the last node
   {
      DoubleNode<ItemType>* remover = headPtr;
      do 
         {
            remover = remover-> getNext();
         }
         while(remover->getNext() != nullptr); //pointing to last node
      DoubleNode<ItemType>* before_remove = remover->getLast();
      before_remove->setNext(nullptr);
      remover->setLast(nullptr); 
      delete remover;
      remover = nullptr;
   }
   else //if the position is in the MIDDLE
   {
   DoubleNode<ItemType>* copyHead = headPtr; //temp head

   for (int i = 1; i < position; i++) //already took care of position 1 case above
      {
         copyHead = copyHead->getNext(); //find the node with the index position
      }
      DoubleNode<ItemType>* BeforeR = copyHead->getLast(); //get the node before the node you want to remove
      DoubleNode<ItemType>* AfterR = copyHead->getNext(); //get the node after the node you want to remove
      BeforeR->setNext(AfterR);
      AfterR->setLast(BeforeR);
      copyHead->setLast(nullptr);
      copyHead->setNext(nullptr);
      delete copyHead;
      copyHead = nullptr;
   }
   } 
   itemCount--;
   return true;
} //end remove

template<class ItemType> //RETURNS NUMBER OF NODES IN LIST
int DoublyLinkedList<ItemType>::getSize() const
{	
	int DoubleNodeAmount = 0; //create a count
	if (headPtr == nullptr) //if bag is empty, return 0
		{
			DoubleNodeAmount = 0;
			return DoubleNodeAmount;
		}	
	else     //bag is not empty, start counting
		{
		DoubleNodeAmount = 1; //start at one

	DoubleNode<ItemType>* placeholder = headPtr; //copy start of chain
	while (placeholder->getNext() != nullptr) //traverse the chain using the copy
		{
			placeholder = placeholder->getNext();
			DoubleNodeAmount++; //increment as you count untill you reach the end (nullptr)
		}
return DoubleNodeAmount++; //return the final count
		}
} //end getSize

template<class ItemType> //RETURNS COPY OF HEADPTR
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() const
{
   return headPtr;
} //end getHeadPtr

template<class ItemType> //RETURNS POINTER TO NODE LOCATED AT POS
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
   DoubleNode<ItemType>* curPtr = headPtr; //copy headPtr
   for (int m = 1; m <= pos; m++) //loop through bag until at the right pos
      {
         if (pos == 1) //return curPtr = headPtr 
            {
               return curPtr;
            }
         else if(m > 1 && m==pos) //if you find the right pos index, return the pointer
            {
               return curPtr;
            }
         else
         {
            curPtr = curPtr->getNext(); //keep advancing the node pointer until you reach pos
         }
      }
} //end getAtPos

template<class ItemType> //RETURNS BOOL VALUE OF WHETHER OR NOT THE LIST IS EMPTY
bool DoublyLinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0; //compares the list's itemCount to zero
} //end isEmpty

template<class ItemType> //CLEARS LIST
void DoublyLinkedList<ItemType>::clear()
{
   DoubleNode<ItemType>* nodeToDeletePtr = headPtr; //copy headptr
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext(); //move headptr to the next node
      delete nodeToDeletePtr; //delete copy of headptr
      nodeToDeletePtr = headPtr; //reassign copy of headptr to headptr of chain
   }
   delete nodeToDeletePtr;
   nodeToDeletePtr = nullptr;
	itemCount = 0; //list is now empty
} //end clear

template<class ItemType> //PRINTS CONTENTS OF LIST IN ORDER
void DoublyLinkedList<ItemType>::display() const
{
   DoubleNode<ItemType>* run = headPtr; //copy start of chain
   for (int c = 1; c <=itemCount; c++) //repeat as many times as there are nodes in the list
   {
      if(run-> getNext() == nullptr) //if you are at the last node
      {
         cout << run->getItem() << endl; //print the node
         return;
      }
      else
      {
      cout << run->getItem() << " "; //print out the item in the current node
      run = run->getNext(); //advance the headptr
      }
   }
} //end display

template<class ItemType> //PRINTS CONTENTS OF LIST BACKWARDS
void DoublyLinkedList<ItemType>::displayBackwards() const
{
   DoubleNode<ItemType>* backwards = headPtr; //copy headptr
   while(backwards->getNext() != nullptr)
   {
      backwards = backwards->getNext(); //will end up pointing to last node 
   }
   for(int z = 1; z <= itemCount; z++)
   {
      if(backwards->getLast() == nullptr) //when you reach the end of the list
      {
         cout << backwards->getItem() << endl;
      }
      else
      {
      cout << backwards->getItem() << " "; //print the item in current node
      backwards = backwards->getLast(); //move to previous node  
      }
   }
} //end displayBackwards

template<class ItemType> //ALTERS CALLING LIST TO INCLUDE ITEMS OF A SECOND LIST
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_List)
{
int totalCount = itemCount + a_List.itemCount; //what the final itemCount should be
DoubleNode<ItemType>* curList = headPtr; //copy start of calling list
DoubleNode<ItemType>* passedinList = a_List.getHeadPtr(); //copy start of parameter list

  int amount1 = itemCount; //the number of nodes in calling list
  int amount2 = a_List.itemCount; //number of nodes in parameter list
  int location = 1; //start index for insertion at one 

  while(!( (curList == nullptr) && (passedinList == nullptr))) //keep going until you run out of nodes in both lists
  {
     if(curList != nullptr) //enter as long as there are nodes in calling list
     {
        this->insert(curList->getItem(), location); //insert
        location++; //increment index
        curList = curList->getNext(); //adance to next node in calling list
     }
   
     if (passedinList != nullptr) //enter as long as there are nodes in parameter list
     {
        this->insert(passedinList->getItem(), location); //insert
        location++; //increment index
        passedinList = passedinList->getNext(); //advance to next node in parameter list
     }
  }
  
  if ((curList == nullptr) || (passedinList == nullptr)) //you enter when you have run out of nodes in both lists
   {
      if(amount1 > amount2) //do this if the calling list was longer than parameter list
      {
      for (int m = amount2; m <(amount1 + amount2); m++) //all original nodes in calling list have been push forward in the list
         {                                        //these nodes are repeated and must be removed
      this->remove((amount1+amount2)+1);
         }
      }
      else //enter if parameter list was longer
      {
         for (int m = amount2; m <(amount1+amount2); m++) //will also remove repeated nodes
         {
      this->remove((amount1+amount2)+1);
         }
      }

   }
   
   itemCount = totalCount;
   return *this;
} //end interleave

 