#include <iostream>
#include "hashchain.hpp"
using namespace std;

HashChain::HashChain(int bsize)
{
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = NULL;
    }
}

node* HashChain::createNode(int key, node* next)
{
    node* n = new node;
    n->key = key;
    n->next = next;
    return n;
}

unsigned int HashChain::hashFunction(int key)
{
    return (key % tableSize);
}

node* HashChain::searchItem(int key)
{
    int index = hashFunction(key);
    node* n = table[index];
    while(n != NULL)
    {
        if(n->key == key)
        {
            return n;
        }
        n = n->next; // traverse within that index found with hash function
        numCollisionSearch++;
    }
}

bool HashChain::insertItem(int key)
{
    int index = hashFunction(key);
    node* n = createNode(key, NULL);

    // if(searchItem(key) != NULL && searchItem(key)->key == key) // duplicate 
    // {
    //     return false;
    // }
	if(table[index] == NULL) // if spot is empty
    {
		table[index] = n;
    }
    else // there's other stuff in that bucket
    {
        n->next = table[index]; // add to front
        table[index] = n;
        numCollision++;
    }
    return true;
}

void HashChain::printTable()
{
    for (int i = 0; i < tableSize; i++) 
    {
        cout << "bucket " << i << ": ";
        node* n = table[i];
        while(n != NULL)
        {
            cout << n->key << "->";
            n = n->next;
        }
        cout << "NULL" << endl;
    }   
}

int HashChain::getNumOfCollision()
{
    // cout << "number of collisions insert: " << numCollision << endl;
    return numCollision;
}
int HashChain::getNumOfCollisionSearch()
{
    // cout << "number of collisions search: " << numCollisionSearch << endl;
    return numCollisionSearch;
}