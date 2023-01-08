#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <thread>
#include "merge.hpp"
int threadCount;
#include "threadMergeV1.hpp"
#include "threadMergeV2.hpp"
using namespace std;

void printArray(int *A, int size);



int* randomNumbers(int numberCounter)
{
    srand(time(0));
    int *numbers= new int[numberCounter];
    for (int i = 0; i < numberCounter; i++)
    {
        numbers[i]=rand();
    }

    return numbers;
}

void printArray(int *A, int size)
{

    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr_size = 100000;
    
    int *arr = randomNumbers(arr_size);
    int *arrCopy = new int[arr_size];
    int *arrCopy2 = new int[arr_size];
    for (size_t i = 0; i < arr_size; i++)
    {
        arrCopy[i] = arr[i];
        arrCopy2[i] = arr[i];
    }


    /*
    cout << "Given array is \n";
    printArray(&arr[0], arr_size);
    */

    clock_t t1, t2, t3, t4, t5, t6;
    t1 = clock();
    mergeSort(&arr[0], 0, arr_size - 1);
    t2 = clock();

    threadCount = 1;
    t3 = clock();
    mergeSortThreadV1(&arrCopy[0], 0, arr_size - 1);
    t4 = clock();
    cout << "\nThreadCount : " << threadCount << endl;
    threadCount = 1;
    t5 = clock();
    mergeSortThreadV2(&arrCopy2[0], 0, arr_size - 1);
    t6 = clock();
    cout << "\nThreadCount : " << threadCount << endl;

    /*
    cout << "Sorted array is \n";
    printArray(&arr[0], arr_size);
    */

    cout << "\nSimple merge time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
    cout << "\nThreadV1 merge time taken: " << (t4 - t3) / (double)CLOCKS_PER_SEC << endl;
    cout << "\nThreadV2 merge time taken: " << (t6 - t5) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}