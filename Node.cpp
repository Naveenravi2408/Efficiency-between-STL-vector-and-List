/*
 * Node.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: navee
 */

#include <iostream>
#include "Node.h"

using namespace std;

/*
 * Static member variables
 */
long Node::constructor_count;	// constructor count
long Node::copy_count;			// copy constructor count
long Node::destructor_count;	// destructor count

/*
 * Constructor
 * @param the_value is the initial data
 * Constructor_count to count the number of times this constructor is called
 */
Node::Node(const long the_value)
{
	value = the_value;
	constructor_count++;
}

/*
 * Copy constructor
 * @param other is the node object to copy
 * Copy_count to count the number of times this copy constructor is called
 */
Node::Node(const Node& other)
{
	value = other.value;
	copy_count++;
}

/*
 * Destructor
 * destructor_count to count how many times this destructor is called
 */
Node::~Node ()
{
	destructor_count++;
}

/*
 * Getter
 * returns the value
 */
long Node::get_value() const
{
	return value;
}

/*
 * Getter
 * returns the constructor count value
 */
long Node::get_constructor_count()
{
	return constructor_count;
}

/*
 * Getter
 * returns the copy constructor count value
 */
long Node::get_copy_count()
{
	return copy_count;
}

/*
 * Getter
 * returns the destructor count value
 */
long Node::get_destructor_count()
{
	return destructor_count;
}

/*
 * Reset the values of all the counters
 */
void Node::reset()
{
	constructor_count = 0;
	copy_count = 0;
	destructor_count = 0;
}

/*
 * Overloaded comparator operator
 * compares the new value with the other node value for equality
 * and returns true if same
 */
bool Node::operator ==(const Node& other) const
{
	if(value == other.value)
	{
		return true;
	}
	else{
		return false;
	}
}

/*
 * overloaded > operator
 * compares the new value with the other node value
 * and returns true if value is greater
 */
bool Node::operator >(const Node& other) const
{
	if(value > other.value)
	{
		return true;
	}
	else{
		return false;
	}
}
