using namespace std;

void mergeThreadV1(int *array, int mid, int end)
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
            tempMid++;
            continue;
        }
        mergedArrayIndex++;
    }
    for (size_t i = 0; i < mergedArrayIndex; i++)
    {
        array[i] = mergedArray[i];
    }
}

void mergeSortThreadV1(int array[], int begin, int end)
{

    if (begin >= end)
        return;

    int arrayCount = end - begin;

    auto mid = begin + (end - begin) / 2;

    int threadPower = arrayCount / threadCount;

    // if you have powerfull computer then you need to bigger count
    // at least 1000 number otherwise logical to single thread dont need multithread
    if (threadPower > 11000)
    {
        threadCount++;

        thread sortThread(mergeSortThreadV1, array, begin, mid);
        thread sortThread2(mergeSortThreadV1, array, mid + 1, end);
        mid = mid - begin;
        end = end - begin;
        sortThread.join();
        sortThread2.join();
        mergeThreadV1(&array[begin], mid, end);
    }
    else
    {
        mergeSortThreadV1(array, begin, mid);
        mergeSortThreadV1(array, mid + 1, end);

        mid = mid - begin;
        end = end - begin;
        mergeThreadV1(&array[begin], mid, end);
    }
}
