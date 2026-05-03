/*

Queue Overview

A queue is a FIFO (first-in, first-out) data structure. 
Like the stack, it generally supports a limited set of operations:

clear()	        removes all elements from the queue
dequeue()	    removes and returns the frontmost element in the queue
enqueue(value)	adds value to the back of the queue
equals()	    returns true if the two queues contain the same elements in the same order, false otherwise
isEmpty()	    returns true if the queue contains no elements, false otherwise
peek()	        returns the frontmost element in the queue without removing it
size()	        returns the number of values in the queue

*/

#include <iostream>
#include "console.h"
#include "queue.h"
using namespace std;

int main()
{
    Queue<int> q;

    for (int i = 0; i <= 6; i++)
    {
        q.enQueue(i);
    }

    while(!q.isEmpty())
    {
        cout << q.deQueue() << endl;
    }

    return 0;
}

void queueIdiom()
{
    Queue<int> q;
    
    for (int i = 0; i <= 6; i++)
    {
        q.enQueue(i);
    }

    // Keep track of original queue size. This loop will only do 6 iterations now,
    // even though we're adding some elements back into the queue as we go.
    int ogSize = q.size();

    for (int i = 0; i < ogSize; i++)
    {
        int val = q.deQueue();
        cout << val << endl;

        // Even values get added back to the queue.
        if (val % 2 == 0)
        {
            q.enQueue(val);
        }
    }

    cout << "Final queue contents: " << q << endl;

    return 0;
}

/*
Queues come up all over the place in real-world applications. A few examples from today:

    1. Purchase queues for online ticket sales, gaming consoles, graphics cards -- you name it!
    2. Login queues for online games.
    3. Printer queues for processing multiple print jobs.
    4. The LaIR queue for processing help requests in CS106A/B!
    
    There's at least one very common application of queues on graph theory; they can be used to implement 
    an algorithm called breadth-first search. A related algorithm, called depth-first search, can actually 
    be implemented with a stack.
*/