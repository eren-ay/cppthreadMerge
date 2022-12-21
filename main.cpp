#include <iostream>
#include <string>
#include <vector>
using namespace std;

void merge(vector<int> array, int begin, int mid, int end);
void mergeSort(int array[], int  begin, int  end);
void printArray(int *A, int size);


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

void merge(int* array, int mid, int end){
    int tempBegin=0;
    mid++;
    int tempMid=mid;
    
    int *mergedArray=new int[end+1];
    end++;
    int mergedArrayIndex=0;
    while (tempBegin < mid || tempMid < end)
    {
        if (tempBegin < mid && tempMid < end)
        {
            if (array[tempBegin]<=array[tempMid]){
                mergedArray[mergedArrayIndex]=array[tempBegin];
                tempBegin++;
            }
            else{
                mergedArray[mergedArrayIndex]=array[tempMid];
                tempMid++;
            }
            
        }else if (tempBegin < mid)
        {
            mergedArray[mergedArrayIndex]=array[tempBegin++];    
        }else if (tempMid < end)
        {
            mergedArray[mergedArrayIndex]=array[tempMid++];
        }
        mergedArrayIndex++;
    }
    for (size_t i = 0; i < end; i++)
    {
        array[i]=mergedArray[i];
    }
}


void mergeSort(int array[], int  begin, int  end)
{
    
    if (begin >= end)
        return;
    
    
    auto mid = begin + (end - begin) / 2;

    /* 2x2 thread< */
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    
    mid = mid - begin;
    end= end-begin;
    merge(&array[begin],mid,end);
    
}

void printArray(int *A, int size)
{
    
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    vector<int> arr = randomNumbers(8);
    int arr_size = arr.size();

    cout << "Given array is \n";
    printArray(&arr[0], arr_size);
    mergeSort(&arr[0], 0, arr_size-1 );
    cout << "Sorted array is \n";
    printArray(&arr[0], arr_size);
    return 0;
}