//Team 8 - (Milly Flores 50%, Seth Tourish 50%)
// Implementation file for the NumberList class
#include <iostream> // For cout
#include "NumberList.h"
using namespace std;
//**************************************************
// appendNode appends a node containing the *
// value pased into num, to the end of the list. *
//**************************************************
void NumberList::appendNode(double num)
{
	ListNode* newNode; // To point to a new node
	ListNode* nodePtr; // To move through the list
	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;
	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
	{
		// Initialize nodePtr to head of list.
		nodePtr = head;
		// Find the last node in the list.
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}
//**************************************************
// displayList shows the value *
// stored in each node of the linked list *
// pointed to by head. *
//**************************************************
void NumberList::displayList() const
{
	ListNode* nodePtr; // To move through the list
	// Position nodePtr at the head of the list.
	nodePtr = head;
	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
	{
		// Display the value in this node.
		cout << nodePtr->value << endl;
		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}
//**************************************************
// The insertNode function inserts a node with *
// num copied to its value member. *
//**************************************************
void NumberList::insertNode(double num)
{
	ListNode* newNode; // A new node
	ListNode* nodePtr; // To traverse the list
	ListNode* previousNode = nullptr; // The previous node
	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;
		// Initialize previousNode to nullptr.
		previousNode = nullptr;
		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
//**************************************************
// The deleteNode function searches for a node *
// with num as its value. The node, if found, is *
// deleted from the list and from memory. *
//**************************************************
void NumberList::deleteNode(double num)
{
	ListNode* nodePtr; // To traverse the list
	ListNode* previousNode; // To point to the previous node
	// If the list is empty, do nothing.
	if (!head)
		return;
	// Determine if the first node is the one.
	if (head->value == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;
		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		// If nodePtr is not at the end of the list,
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

//Total function to add up and display the total of all the values in the list
double NumberList::total() const
{
	ListNode* nodePtr; // List iterator
	double total = 0; // Total Variable
	//Set nodePtr to the head of the list
	nodePtr = head;
	//While nodePtr points to a node, go into while loop and add the value of the
	//node to the total, then move to next node
		while (nodePtr)
		{
			// Add the value in the current node to the total
			total += nodePtr->value;
			// Move to the next node in the list
			nodePtr = nodePtr->next;
		}
	// Return the total of all values in the list.
	return total;
}

//Search function to search and return the position of the value in the list
double NumberList::search(double val)
{
	//List iterator
	ListNode* nodePtr;
	// Position Variable
	double position = 0;
	//Set nodePtr to head
	nodePtr = head;

	//begin search of the linked list
	while (nodePtr)
	{
		//if value of current node is equal to value of search number, return position
		if (nodePtr->value == val)
		{
			return position;
		}
		//if value of current node is not equal to value of search number, increment position
		else
		{
			position++;
		}

		// Move to the next node
		nodePtr = nodePtr->next;
	}

	//If the value is not found, return -1
	return -1;

}

//**************************************************
// Destructor *
// This function deletes every node in the list. *
//**************************************************
NumberList::~NumberList()
{
	ListNode* nodePtr; // To traverse the list
	ListNode* nextNode; // To point to the next node
	// Position nodePtr at the head of the list.
	nodePtr = head;
	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		// Delete the current node.
		delete nodePtr;
		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}