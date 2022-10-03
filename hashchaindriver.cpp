#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "hashchain.hpp"
using namespace std;

int main()
{
    //------------------------ [ TEST IF HASH CHAINING WORKS ] ---------------------

    // HashChain hc(7);
    HashChain hc(40009);

    ifstream infile;
    // string filename = "test.csv";
    string filename = "dataSetA.csv";

    infile.open(filename);

    string line;

    if(infile.fail())
    {
        return 0;
    }
    else // if the file opens
    {
        while(getline(infile, line)) 
        {
            stringstream ss(line);
            string num_infile;
            while(getline(ss, num_infile, ',')) 
            {
                int num = stoi(num_infile);
                hc.insertItem(num);              // test insertItem()
            }
        }
        hc.printTable();                         // test printTable()
        // hc.getNumOfCollision();               // test getNumOfCollision()
    }
    
        /*------------------------------------------- [ TIMING EXPERIMENT: A ] ------------------------------------------------*/

    // for outfile
    ofstream outfileA;
    string filenameA = "insert_search_performance_hash_chain_dataSetA.csv";
    outfileA.open(filenameA);

    // arrays to record time + data
    int testData_A[10000];
    float insertA[100];
    float searchA[100];
    int collisionsInsertA[100];
    int collisionsSearchA[100];

    int countA = 0;

    HashChain hcA(40009);

    ifstream fileA;
    string file_nameA = "dataSetA.csv";
    fileA.open(file_nameA);

    string strA;

    if(fileA.fail())
    {
        return 0;
    }
    else // if the file opens
    {
        while(getline(fileA, strA)) 
        {
            stringstream strStreamA(strA);
            string num_fileA;
            while(getline(strStreamA, num_fileA, ',')) 
            {
                int numInt_A = stoi(num_fileA);
                testData_A[countA] = numInt_A;                // put data.csv into testData_A[]
                countA++;
            }
        }
    }

    // ------------------------------------------ [ insert A ] ------------------------------------------------

    /* variables for insertA experiment */
    int currIndexA = 0;
    int a = currIndexA;
    int upperA = 100;
    int insertDataA = 0; 
    int counterA = 0;

    /* variables for search experiment */
    int indexA; 
    int patientID_A; 
    int searchDataA = 0; 
    int intervalA = 100;

    /* variables for putting collision data */
    int insColA = 0; 
    int prevInsColA = 0;
    int searchColA = 0;
    int prevSearchColA = 0;

    while(currIndexA < 10000)
    {
        auto start_insertA = chrono::steady_clock::now(); 

        for(a = currIndexA; a < upperA; a++) 
        {
            hcA.insertItem(testData_A[a]);
        }
        currIndexA += 100;
        upperA += 100;

        auto end_insertA = chrono::steady_clock::now();

        cout << " (INSERT A) Elapsed time in nanoseconds : " << " [ " << counterA << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_insertA - start_insertA).count()) / 100.0
            << " ns" << endl;

        insertA[insertDataA] = (chrono::duration_cast<chrono::nanoseconds>(end_insertA - start_insertA).count()) / 100.0;
        insertDataA++;

        collisionsInsertA[insColA] = hcA.getNumOfCollision() - prevInsColA;
        prevInsColA = hcA.getNumOfCollision();
        insColA++;

        // ------------------------------------------ [ SEARCH A ] ------------------------------------------------

        auto start_searchA = chrono::steady_clock::now();
        for(int j = 0; j < 100; j++)
        {
            indexA = rand() % intervalA;
            patientID_A = testData_A[indexA];
            hcA.searchItem(patientID_A);
        }
        intervalA += 100;
        auto end_searchA = chrono::steady_clock::now();

        cout << " (SEARCH A) Elapsed time in nanoseconds : " << " [ " << counterA << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_searchA - start_searchA).count()) / 100.0
            << " ns" << endl;
    
        searchA[searchDataA] = (chrono::duration_cast<chrono::nanoseconds>(end_searchA - start_searchA).count()) / 100.0;
        searchDataA++;
        counterA++;

        collisionsSearchA[searchColA] = hcA.getNumOfCollisionSearch() - prevSearchColA;
        prevSearchColA = hcA.getNumOfCollisionSearch();
        searchColA++;

    } // end while for timing experiment A

    for(int a = 0; a < 100; a++) // outfile insert array
    {
        outfileA << insertA[a] << endl;
    }
    for(int a = 0; a < 100; a++) // outfile search array
    {
        outfileA << searchA[a] << endl;
    }
    for(int a = 0; a < 100; a++) // outfile insert collisions array
    {
        outfileA << collisionsInsertA[a] << endl;
    }
    for(int a = 0; a < 100; a++) // outfile search collisions array
    {
        outfileA << collisionsSearchA[a] << endl;
    }

    /*------------------------------------------- [ TIMING EXPERIMENT: B ] ------------------------------------------------*/

    // for outfile
    ofstream outfileB;
    string filenameB = "insert_search_performance_hash_chain_dataSetB.csv";
    outfileB.open(filenameB);

    // arrays to record time + data
    int testData_B[10000];
    float insertB[100];
    float searchB[100];
    int collisionsInsertB[100];
    int collisionsSearchB[100];

    int countB = 0;

    HashChain hcB(40009);

    ifstream fileB;
    string file_nameB = "dataSetB.csv";
    fileB.open(file_nameB);

    string strB;

    if(fileB.fail())
    {
        return 0;
    }
    else // if the file opens
    {
        while(getline(fileB, strB)) 
        {
            stringstream strStreamB(strB);
            string num_fileB;
            while(getline(strStreamB, num_fileB, ',')) 
            {
                int numInt_B = stoi(num_fileB);
                testData_B[countB] = numInt_B;                // put data.csv into testData_B[]
                countB++;
            }
        }
    }

    // ------------------------------------------ [ insert B ] ------------------------------------------------

    /* variables for insertB experiment */

    int currIndexB = 0;
    int b = currIndexB;
    int upperB = 100;
    int insertDataB = 0; 
    int counterB = 0;

    /* variables for searchB experiment */

    int indexB; 
    int patientID_B; 
    int searchDataB = 0; 
    int intervalB = 100;

    /* variables for putting collision data */
    int insColB = 0; 
    int prevInsColB = 0;
    int searchColB = 0;
    int prevSearchColB = 0;

    while(currIndexB < 10000)
    {
        auto start_insertB = chrono::steady_clock::now(); 

        for(b = currIndexB; b < upperB; b++) 
        {
            hcB.insertItem(testData_B[b]);
        }
        currIndexB += 100;
        upperB += 100;

        auto end_insertB = chrono::steady_clock::now();

        cout << " (INSERT B) Elapsed time in nanoseconds : " << " [ " << counterB << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_insertB - start_insertB).count()) / 100.0
            << " ns" << endl;

        insertB[insertDataB] = (chrono::duration_cast<chrono::nanoseconds>(end_insertB - start_insertB).count()) / 100.0;
        insertDataB++;

        collisionsInsertB[insColB] = hcB.getNumOfCollision() - prevInsColB;
        prevInsColB = hcB.getNumOfCollision();
        insColB++;

        // ------------------------------------------ [ SEARCH B ] ------------------------------------------------

        auto start_searchB = chrono::steady_clock::now();
        for(int j = 0; j < 100; j++)
        {
            indexB = rand() % intervalB;
            patientID_B = testData_B[indexB];
            hcB.searchItem(patientID_B);
        }
        intervalB += 100;
        auto end_searchB = chrono::steady_clock::now();

        cout << " (SEARCH B) Elapsed time in nanoseconds : " << " [ " << counterB << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_searchB - start_searchB).count()) / 100.0
            << " ns" << endl;
    
        searchB[searchDataB] = (chrono::duration_cast<chrono::nanoseconds>(end_searchB - start_searchB).count()) / 100.0;
        searchDataB++;
        counterB++;

        collisionsSearchB[searchColB] = hcB.getNumOfCollisionSearch() - prevSearchColB;
        prevSearchColB = hcB.getNumOfCollisionSearch();
        searchColB++;

    } // end while for timing experiment B

    for(int b = 0; b < 100; b++) // outfile insert array
    {
        outfileB << insertB[b] << endl;
    }
    for(int b = 0; b < 100; b++) // outfile search array
    {
        outfileB << searchB[b] << endl;
    }
    for(int b = 0; b < 100; b++) // outfile insert collisions array
    {
        outfileB << collisionsInsertB[b] << endl;
    }
    for(int b = 0; b < 100; b++) // outfile search collisions array
    {
        outfileB << collisionsSearchB[b] << endl;
    }

} // end main