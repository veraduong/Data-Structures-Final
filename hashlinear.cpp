#include <iostream>
#include "hashlinear.hpp"
using namespace std;

HashLinear::HashLinear(int bsize)
{
    tableSize = bsize;
    table = new int[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1; // initialize so that there's nothing in the table
    }
}

unsigned int HashLinear::hashFunction(int key)
{
    return (key % tableSize);
}

int HashLinear::searchItem(int key)
{
    int index = hashFunction(key);
    int startIndex = index;
    if(table[index] == key) // if initial index has key then return the index
    {
        return index;
    }
    else
    {
        numCollisionSearch++; // increment collisions for search for the first time seeing it
        int startIndex = index;
        while(table[index] != key)
        {
            index++; // go to next index
            if(startIndex = index) // this will break loop if key isn't table
            {
                break;
            }
            if(index == tableSize - 1) // circular
            {
                index = 0;
            }
        }
        if(table[index] == key) // if key is found in new index
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
}

bool HashLinear::insertItem(int key)
{
    int index = hashFunction(key); // original pos where key is supposed to go

    if(table[index] == -1) // insert if nothing there and return true
    {
        table[index] = key;
        return true;
    }
    else
    {
        int originIndex = index;
        while(table[index] != -1)
        {
            if(index == tableSize) // circle around
            {
                index = 0;
            }
            else // increment index
            {
                index++;
            }
            if(index == originIndex) // break if the index is the initial index 
            {
                break;
            }
        }
        numCollision++;
        table[index] = key;
        return true;
    }
    return false;
}

void HashLinear::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << "bucket " << i << ": " << table[i] << endl;
    }
}

int HashLinear::getNumOfCollision()
{
    // cout << "number of collisions insert: " << numCollision << endl;
    return numCollision;
}
int HashLinear::getNumOfCollisionSearch()
{
    // cout << "number of collisions search: " << numCollisionSearch << endl;
    return numCollisionSearch;
}