#include <iostream>
#include "dll.hpp"
using namespace std;

doublyLL::doublyLL()
{
    head = NULL;
    tail = NULL;
}

void doublyLL::insertEnd(int value) 
{
    Node* temp = new Node(value);
 
    if (head == NULL) // nothing in the list 
    {
        head = tail = temp;
    }
    else // inserts at the tail
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

bool doublyLL::isEmpty()
{
    if(head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void doublyLL::display()
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* doublyLL::search(int value)
{
    if(!isEmpty()) 
    {
        Node* temp = head;
        
        while(temp != NULL)
        {
            if(temp->data == value) // return temp if it contains the value
            {
                // cout << "Searched value: " << temp->data << endl;
                return temp;
                break;
            }
            temp = temp->next; // traverse
        }
        if(temp->data != value) //if value isn't found
        {
            return NULL;
        }
    }
}