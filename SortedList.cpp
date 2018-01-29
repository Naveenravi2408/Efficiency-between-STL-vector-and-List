/*

 * SortedList.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: navee
*/

#include <iostream>
#include <iterator>
#include "SortedList.h"
#include<iostream>
#include <cstdlib>

using namespace std;

/*
 * Default constructor
 * reset all the counter values
 */
SortedList::SortedList()
{
    Node::reset();
}

/*
 * Destructor
 * reset all the counter values
 */
SortedList::~SortedList()
{
    Node::reset();
}

/*
 * Returns the size of the list
 */
int SortedList::size() const { return data.size(); }

/*
 *check if all the values in the list is sorted
 *check return true if all the values are sorted in ascending order
 */
bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/*
 * Add a new node at the beginning of the list along with the given value in it
 * @param value is the new value that has to be added
 */
void SortedList::prepend(const long value)
{
    data.insert(data.begin(),Node(value)); //inserts a new node at the beginning of the list
}

/*
 * Add a new node at the end of the list along with the given value in it
 * @param value is the new value that has to be added
 */
void SortedList::append(const long value)
{
	list<Node>::iterator itr = data.end();	// point the iterator to the last NULL node
    data.insert(itr,Node(value));			// Add the new node
}

/*
 * Remove a node from the given index
 * @param index is the index value from where the node should be removed
 */
void SortedList::remove(const int index)
{
	list<Node>::iterator itr;
	bool found=false;
	int count=0;
	for(itr = data.begin(); itr!= data.end(); itr++)	// loop until the end of the list
	{
		if(count == index)	//go the needed index position
		{
			found=true;
			break;
		}
		else{
		count++;
		}
	}
	if(found)
    data.erase(itr);	// erase the required node
}

/*
 * Add a new node while keeping the list sorted according to the value
 * @param value the value to be added inside the new node
 */
void SortedList::insert(const long value)
{
	list<Node>::iterator itr;
	// update the itr pointer while comparing the new value with all the other values inside the node
	for(itr = data.begin(); (itr != data.end())&&((value > itr->get_value())); itr++)
	{}
	data.insert(itr,Node(value));
}

/*
 * get the node for the given index
 * @param index is the needed index from the list
 */
Node SortedList::at(const int index)
{
	list<Node>::iterator itr;
	itr = data.begin();
	advance(itr, index);

    return *itr;
}

