#ifndef HASHLINEAR_HPP
#define HASHLINEAR_HPP
#include <string>
using namespace std;

class HashLinear
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int* table;
    int numCollision = 0;
    int numCollisionSearch = 0;
    
    public:
        HashLinear(int bsize);  // Constructor

        // hash function to map values to key
        unsigned int hashFunction(int key);

        int searchItem(int key);

        // inserts a key into hash table
        bool insertItem(int key);

        void printTable();
        
        int getNumOfCollision();
        int getNumOfCollisionSearch();
};

#endif
