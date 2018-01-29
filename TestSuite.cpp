/*
 * TestSuite.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: navee
 */

#include <string>
#include "SortedVector.h"
#include "SortedList.h"
#include "Node.h"

using namespace std;

// How many times to do gets.
const int GETS_COUNT = 10000;

/*
 * Insert new node at the beginning of the vector
 * @param sv the sorted vector object
 * @param size is the size of the vector
 */
void vector_prepends(SortedVector& sv, const int size)
{
    for (int i = size-1; i>=0; i--)
    {
    	sv.prepend(i);
    }
}

/*
 * Insert new node at the beginning of the list
 * @param sl the sorted list object
 * @param size is the size of the list
 */
void list_prepends(SortedList& sl, const int size)
{
    for (int i = size-1; i>=0; i--)
    {
    	sl.prepend(i);
    }
}

/*
 * Insert new node at the end of the vector
 * @param sv the sorted vector object
 * @param size is the size of the vector
 */
void vector_appends(SortedVector& sv, const int size)
{
    for (int i =0; i<size; i++)
    {
    	sv.append(i);
    }
}

/*
 * Insert new node at the end of the list
 * @param sl the sorted list object
 * @param size is the size of the list
 */
void list_appends(SortedList& sl, const int size)
{
	 for (int i =0; i<size; i++)
	    {
	    	sl.append(i);
	    }
}

/*
 * get the nodes from the vector
 * @param sv is the sorted vector object
 * @param size is tthe size of the vector
 * @throw is to throw an exception if any error occurs
 */
void vector_gets(SortedVector& sv, const int size) throw (string)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        long value = sv.at(index).get_value();
        Node::reset();	// to reset the count of unnecessary copy constructor call for each of the get_count in the loop
        // Make sure we got the correct node.
        if (index != value) throw string("Vector data mismatch!");
    }
}

/*
 * get the nodes from the list
 * @param sl is the sorted list object
 * @param size is the size of the list
 * @throw is to throw an exception if any error occurs
 */
void list_gets(SortedList& sl, const int size) throw (string)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    // Loop to access nodes at random positions.
    for (int i = 0; i < GETS_COUNT; i++)
    {
        int index = rand()%size;
        long value = sl.at(index).get_value();
        Node::reset();		// to reset the count of unnecessary copy constructor call for each of the get_count in the loop
        // Make sure we got the correct node.
        if (index != value) throw string("List data mismatch!");
    }
}

/*
 * Removes the nodes from the sorted vector
 * @param sv is the sorted vector object
 * @param size is the size of the vector
 */
void vector_removes(SortedVector& sv, const int size)
{
    // First fill the vector data.
    vector_appends(sv, size);
    Node::reset();

    // Loop to remove a node at a random position
    // one at a time until the nodes are all gone.
    while (sv.size() > 0)
    {
        int index = rand()%size;
        sv.remove(index);
    }
}

/*
 * Removes the nodes from the sorted list
 * @param sl is the sorted list object
 * @param size is the size of the list
 */
void list_removes(SortedList& sl, const int size)
{
    // First fill the list data.
    list_appends(sl, size);
    Node::reset();

    while (sl.size() > 0)
    {
        int index = rand()%size;
        sl.remove(index);
    }
}

/*
 * Add randomly generated values to the sorted vector
 * @param sv is the sorted vector object
 * @param size is the size of the vector
 */
void vector_inserts(SortedVector& sv, const int size)
{
        for(int i=0; i<size; i++)
        {
        	sv.insert(rand());
        }
}

/*
 * Add randomly generated values to the sorted list
 * @param sl is the sorted list object
 * @param size is the size of the list
 */
void list_inserts(SortedList& sl, const int size)
{
    for(int i=0; i<size; i++)
    {
    	sl.insert(rand());
    }
}


