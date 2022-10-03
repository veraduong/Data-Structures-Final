#include <iostream>
#include <cmath>
#include "hashquad.hpp"
using namespace std;


HashQuad::HashQuad(int bsize)
{
    tableSize = bsize;
    table = new int[tableSize];
    for(int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }
}

unsigned int HashQuad::hashFunction(int key)
{
    return (key % tableSize);
}

int HashQuad::searchItem(int key)
{
    int index = hashFunction(key);
    int startIndex = index;
    if(table[index] == key) // return index if key is found in initial index
    {
        return index;
    }
    else
    {
        numCollisionSearch++; // increment search collisions 
        int startIndex = index;
        while(table[index] != key)
        {
            index++;
            if(startIndex = index) // break if the index is the initial index
            {
                break;
            }
            if(index == tableSize - 1) // circle around
            {
                index = 0;
            }
        }
        if(table[index] == key) // return index if key is found after lp
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
}

bool HashQuad::insertItem(int key)
{
    int index = hashFunction(key); // original pos where key is supposed to go

    if(table[index] == -1) // if bucket is empty then add key into the table 
    {
        table[index] = key;
        return true;
    }
    else
    {
        int i = 1; // index to start incrementing i
        int originIndex = index;
        while(table[index] != -1)
        {
            if(index == tableSize) // circle around
            {
                index = 0;
            }
            else
            {
                // int i = 1;
                // index = index + pow(i,2);
                index = (int)(index + pow(i,2)) % tableSize; // quadratic probing formula
                i++;
                // cout << index << endl;
            }
            if(index == originIndex) // break if index is initial index
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

void HashQuad::printTable()
{
    for(int i = 0; i < tableSize; i++)
    {
        cout << "bucket " << i << ": " << table[i] << endl;
    }
}

int HashQuad::getNumOfCollision()
{
    // cout << "number of collisions insert: " << numCollision << endl;
    return numCollision;
}
int HashQuad::getNumOfCollisionSearch()
{
    // cout << "number of collisions search: " << numCollisionSearch << endl;
    return numCollisionSearch;
}