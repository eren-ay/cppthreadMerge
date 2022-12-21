#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<int> array, int begin, int mid, int end);
vector<int> randomNumbers(int numberCounter)
{
    srand((unsigned)time(NULL));
    vector<int> numbers;
    for (int i = 0; i < numberCounter; i++)
    {
        numbers.push_back(rand() % 100);
    }

    return numbers;
}

void merge(vector<int> array, int begin, int mid, int end)
{
    auto const subArrayOne = mid - begin + 1;
    auto const subArrayTwo = end - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[begin + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,    // Initial index of first sub-array
        indexOfSubArrayTwo = 0;     // Initial index of second sub-array
    int indexOfMergedArray = begin; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(vector<int> array, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    auto mid = (begin + (end - begin)) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int *A, int size)
{
    A[1] = 5;
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    vector<int> arr = randomNumbers(5);

    int arr_size = arr.size();

    printArray(&arr[0], arr_size);
    cout << "Given array is \n";

    mergeSort(arr, 0, arr_size - 1);

    /*
printArray(*arr, arr_size);

mergeSort(*arr, 0, arr_size - 1);

cout << "\nSorted array is \n";
printArray(*arr, arr_size);
*/

    return 0;
}