#ifndef HASHCHAIN_HPP
#define HASHCHAIN_HPP
#include <string>
using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashChain
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    node* *table;
    int numCollision = 0;
    int numCollisionSearch = 0;
    
    node* createNode(int key, node* next); 

    public:
        HashChain(int bsize);  // Constructor

        // inserts a key into hash table
        bool insertItem(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);

        void printTable();
        int getNumOfCollision();
        int getNumOfCollisionSearch();

        node* searchItem(int key);
};

#endif
