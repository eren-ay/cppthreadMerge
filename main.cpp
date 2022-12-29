#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include "merge.hpp"
using namespace std;

void merge(vector<int> array, int begin, int mid, int end);
void mergeSort(int array[], int begin, int end);
void printArray(int *A, int size);

vector<int> randomNumbers(int numberCounter)
{
    srand(time(0));
    vector<int> numbers;
    for (int i = 0; i < numberCounter; i++)
    {
        numbers.push_back(rand() + rand() + rand() + rand() + rand());
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
    vector<int> arr = randomNumbers(10);
    int arr_size = arr.size();

    cout << "Given array is \n";
    printArray(&arr[0], arr_size);

    clock_t t1, t2;
    t1 = clock();
    mergeSort(&arr[0], 0, arr_size - 1);

    t2 = clock();

    cout << "Sorted array is \n";
    printArray(&arr[0], arr_size);

    cout << "\nSimple merge time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
    return 0;
}