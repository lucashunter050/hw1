/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void add_to_list(Node*, Node*);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

    // base case, reached end of the list
    if (!in) {
        return;
    }
    
    split(in->next, odds, evens);
    
    // put the input node in the appropriate list
    if (in->value % 2) { // executes if odd
        in->next = odds; // add to front of list
        odds = in;
        in = nullptr;
    } else { 
        in->next = evens; // add to front of list
        evens = in;
        in = nullptr;
    }
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE