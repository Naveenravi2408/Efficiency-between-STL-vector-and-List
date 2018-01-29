/*
 * SortedVector.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: navee
 */

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

/*
 * Default constructor
 * reset all the counter values
 */
SortedVector::SortedVector()
{
    Node::reset();
}

/*
 * Destructor
 * reset all the counter values
 */
SortedVector::~SortedVector()
{
    Node::reset();
}

/*
 * Returns the size of the vector
 */
int SortedVector::size() const { return data.size(); }

/*
 *check if all the values in the vector is sorted
 *check return true if all the values are sorted in ascending order
 */
bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

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
 * Add a new node at the beginning of the vector along with the given value in it
 * @param value is the new value that has to be added
 */
void SortedVector::prepend(const long value)
{
	 data.insert(data.begin(),Node(value));	//inserts a new node at the beginning of the list
}

/*
 * Add a new node at the end of the vector along with the given value in it
 * @param value is the new value that has to be added
 */
void SortedVector::append(const long value)
{
	data.push_back(Node(value));	//push back the new node to the end of the vector
}

/*
 * Remove a node from the given index
 * @param index is the index value from where the node should be removed
 */
void SortedVector::remove(const int index)
{
	 data.erase(data.begin()+index);	//erase the node of the given index
}

/*
 * Add a new node while keeping the vector sorted according to the value
 * @param value the value to be added inside the new node
 */
void SortedVector::insert(const long value)
{
	vector<Node>::iterator itr;
	// update the itr pointer while comparing the new value with all the other values inside the node
	for(itr = data.begin(); (itr != data.end())&&(value > itr->get_value()); itr++)
	{}
	data.insert(itr,Node(value));
}

/*
 * get the node for the given index
 * @param index is the needed index from the vector
 */
Node SortedVector::at(const int index) const
{
	    return data[index];
}


