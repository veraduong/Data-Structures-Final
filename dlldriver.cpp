#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <unistd.h>
#include <thread>
#include "dll.hpp"
using namespace std;

int main()
{
    //------------------------ [ TEST IF DOUBLY LINKED LIST WORKS ] ---------------------

    doublyLL dll;

    ifstream infile;
    string filename = "dataSetA.csv";
    // string filename = "test.csv";
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
                dll.insertEnd(num);              
            }
        }
        dll.display();                           
        // dll.search(3);                           
    }

    /*------------------------------------------- [ TIMING EXPERIMENT: A ] ------------------------------------------------*/

    // for outfile
    ofstream outfileA;
    string filenameA = "insert_search_performance_dll__dataSetA.csv";
    outfileA.open(filenameA);

    // arrays to record time + data
    int testData_A[10000];
    float insertA[100];
    float searchA[100];

    int countA = 0;

    doublyLL dllA;

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

    while(currIndexA < 10000) // continues until end of test array data
    {
        auto start_insertA = chrono::steady_clock::now(); // timing insert

        for(a = currIndexA; a < upperA; a++) 
        {
            dllA.insertEnd(testData_A[a]);
        }
        currIndexA += 100;
        upperA += 100;

        auto end_insertA = chrono::steady_clock::now();

        cout << " (INSERT A) Elapsed time in nanoseconds : " << " [ " << counterA << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_insertA - start_insertA).count()) / 100.0
            << " ns" << endl;

        // put average into insert array
        insertA[insertDataA] = (chrono::duration_cast<chrono::nanoseconds>(end_insertA - start_insertA).count()) / 100.0;
        insertDataA++;

        // ------------------------------------------ [ SEARCH A ] ------------------------------------------------

        auto start_searchA = chrono::steady_clock::now();
        for(int j = 0; j < 100; j++)
        {
            indexA = rand() % intervalA;
            patientID_A = testData_A[indexA];
            dllA.search(patientID_A);
        }
        intervalA += 100;
        auto end_searchA = chrono::steady_clock::now();

        cout << " (SEARCH A) Elapsed time in nanoseconds : " << " [ " << counterA << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_searchA - start_searchA).count()) / 100.0
            << " ns" << endl;
    
        searchA[searchDataA] = (chrono::duration_cast<chrono::nanoseconds>(end_searchA - start_searchA).count()) / 100.0;
        searchDataA++;

        counterA++;

    } // end while for timing experiment A

    /* write to outfile for insert and search data */
    for(int a = 0; a < 100; a++) 
    {
        outfileA << insertA[a] << endl;
    }
    for(int a = 0; a < 100; a++) 
    {
        outfileA << searchA[a] << endl;
    }

    /*------------------------------------------- [ TIMING EXPERIMENT: B ] ------------------------------------------------*/

    // for outfile
    ofstream outfileB;
    string filenameB = "insert_search_performance_dll__dataSetB.csv";
    outfileB.open(filenameB);

    // arrays to record time + data
    int testData_B[10000];
    float insertB[100];
    float searchB[100];

    int countB = 0;

    doublyLL dllB;

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

    while(currIndexB < 10000)
    {
        auto start_insertB = chrono::steady_clock::now(); 

        for(b = currIndexB; b < upperB; b++) 
        {
            dllB.insertEnd(testData_B[b]);
        }
        currIndexB += 100;
        upperB += 100;

        auto end_insertB = chrono::steady_clock::now();

        cout << " (INSERT B) Elapsed time in nanoseconds : " << " [ " << counterB << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_insertB - start_insertB).count()) / 100.0
            << " ns" << endl;

        insertB[insertDataB] = (chrono::duration_cast<chrono::nanoseconds>(end_insertB - start_insertB).count()) / 100.0;
        insertDataB++;

        // ------------------------------------------ [ SEARCH B ] ------------------------------------------------

        auto start_searchB = chrono::steady_clock::now();
        for(int j = 0; j < 100; j++)
        {
            indexB = rand() % intervalB;
            patientID_B = testData_B[indexB];
            dllB.search(patientID_B);
        }
        intervalB += 100;
        auto end_searchB = chrono::steady_clock::now();

        cout << " (SEARCH B) Elapsed time in nanoseconds : " << " [ " << counterB << " ] "
            << (chrono::duration_cast<chrono::nanoseconds>(end_searchB - start_searchB).count()) / 100.0
            << " ns" << endl;
    
        searchB[searchDataB] = (chrono::duration_cast<chrono::nanoseconds>(end_searchB - start_searchB).count()) / 100.0;
        searchDataB++;

        counterB++;

    } // end while for timing experiment B

    /* write to outfile for insert and search data */
    for(int b = 0; b < 100; b++) 
    {
        outfileB << insertB[b] << endl;
    }
    for(int b = 0; b < 100; b++) 
    {
        outfileB << searchB[b] << endl;
    }

}