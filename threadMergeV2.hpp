using namespace std;

void mergeThreadV2(int *array, int mid, int end)
{
    int tempBegin = 0;
    mid++;
    int tempMid = mid;

    int *mergedArray = new int[end + 1];
    end++;
    int mergedArrayIndex = 0;
    int reverseMergedArrayIndex = end - 1; // last index of merged array
    int leftMid = mid / 2;
    int rightMid = mid + leftMid;
    int tempEndLeft = mid - 1;
    int tempEndRight = end - 1;

    while (tempBegin <= tempEndLeft || tempMid <= tempEndRight)
    {
        if (array[tempEndLeft] >= array[tempEndRight])
        {
            mergedArray[reverseMergedArrayIndex] = array[tempEndLeft];
            tempEndLeft--;
        }
        else
        {
            mergedArray[reverseMergedArrayIndex] = array[tempEndRight];
            tempEndRight--;
        }
        reverseMergedArrayIndex--;
        if (tempBegin <= tempEndLeft && tempMid <= tempEndRight)
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
        else if (tempBegin <= tempEndLeft)
        {
            mergedArray[mergedArrayIndex] = array[tempBegin++];
        }
        else if (tempMid <= tempEndRight)
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

void mergeSortThreadV2(int array[], int begin, int end)
{

    if (begin >= end)
        return;

    int arrayCount = end - begin;

    auto mid = begin + (end - begin) / 2;

    int threadPower = arrayCount / threadCount;

    // if you have powerfull computer then you need to bigger count
    // at least 1000 number otherwise logical to single thread dont need multithread
    if (threadPower > 10000)
    {
        threadCount++;

        thread sortThread(mergeSortThreadV2, array, begin, mid);
        thread sortThread2(mergeSortThreadV2, array, mid + 1, end);
        mid = mid - begin;
        end = end - begin;
        sortThread.join();
        sortThread2.join();
        mergeThreadV2(&array[begin], mid, end);
    }
    else
    {
        mergeSortThreadV2(array, begin, mid);
        mergeSortThreadV2(array, mid + 1, end);

        mid = mid - begin;
        end = end - begin;
        mergeThreadV2(&array[begin], mid, end);
    }
}