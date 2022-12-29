
void merge(int *array, int mid, int end)
{
    int tempBegin = 0;
    mid++;
    int tempMid = mid;

    int *mergedArray = new int[end + 1];
    end++;
    int mergedArrayIndex = 0;
    while (tempBegin < mid || tempMid < end)
    {
        if (tempBegin < mid && tempMid < end)
        {
            if (array[tempBegin] <= array[tempMid])
            {
                mergedArray[mergedArrayIndex] = array[tempBegin];
                tempBegin++;
            }
            else
            {
                mergedArray[mergedArrayIndex] = array[tempMid];
                tempMid++;
            }
        }
        else if (tempBegin < mid)
        {
            mergedArray[mergedArrayIndex] = array[tempBegin++];
        }
        else if (tempMid < end)
        {
            mergedArray[mergedArrayIndex] = array[tempMid++];
        }
        mergedArrayIndex++;
    }
    for (size_t i = 0; i < end; i++)
    {
        array[i] = mergedArray[i];
    }
}

void mergeSort(int array[], int begin, int end)
{

    if (begin >= end)
        return;

    auto mid = begin + (end - begin) / 2;

    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);

    mid = mid - begin;
    end = end - begin;
    merge(&array[begin], mid, end);
}