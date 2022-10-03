#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int v, Node* n = NULL, Node* p = NULL)
   {
       data = v;
       next = n;
       prev = p;
   }
};
 
class doublyLL
{
    private:
        Node* head;
        Node* tail;

    public:
        doublyLL();
        void insertEnd(int);
        bool isEmpty();
        void display();
        Node* search(int);
};