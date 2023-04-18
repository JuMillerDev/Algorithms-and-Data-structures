#include "mergeInsertionSort.hpp"

MergeInsertSort::MergeInsertSort()
{
    treshold = 10;
    stats = false;
}

void MergeInsertSort::sort(int n, int keys[])
{
    auto begin = 0;
    auto end = n - 1;

    comparisonOperations = 0;
    shiftOperations = 0;

    if (n < 40 && !stats)
    {
        lessThanFourty = true;
    }
    else
    {
        lessThanFourty = false;
    }

    mergeSort(keys, begin, end);
}

void MergeInsertSort::getOperationCount()
{
    std::cout << "compares: " << comparisonOperations << std::endl;
    std::cout << "shifts:" << shiftOperations << std::endl;
}

void MergeInsertSort::mergeSort(int keys[], int begin, int end)
{
    if ((end - begin) > treshold)
    {
        auto mid = begin + (end - begin) / 2;
        mergeSort(keys, begin, mid);
        mergeSort(keys, mid + 1, end);
        merge(keys, begin, mid, end);
    }
    else
    {
        insertionSort(keys, begin, end);
    }
}

void MergeInsertSort::insertionSort(int keys[], int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int tmp = keys[i];
        int j = i - 1;
        while ((j >= begin) && (keys[j] > tmp))
        {
            keys[j + 1] = keys[j];
            j--;
            comparisonOperations++;
            shiftOperations++;
        }
        keys[j + 1] = tmp;
        shiftOperations++;
    }
}

void MergeInsertSort::merge(int keys[], int left, int mid, int right)
{
    auto const firstSubarray = mid - left + 1;
    auto const secondSubarray = right - mid;

    auto *leftArray = new int[firstSubarray],
         *rightArray = new int[secondSubarray];

    for (auto i = 0; i < firstSubarray; i++)
        leftArray[i] = keys[left + i];
    for (auto j = 0; j < secondSubarray; j++)
        rightArray[j] = keys[mid + 1 + j];

    auto indexOfFirstSubarray = 0,
         indexOfSecondSubarray = 0;
    int indexOfMergedArray = left;

    while (indexOfFirstSubarray < firstSubarray && indexOfSecondSubarray < secondSubarray)
    {
        comparisonOperations++;
        if (leftArray[indexOfFirstSubarray] <= rightArray[indexOfSecondSubarray])
        {
            keys[indexOfMergedArray] = leftArray[indexOfFirstSubarray];
            indexOfFirstSubarray++;
            shiftOperations++;
        }
        else
        {
            keys[indexOfMergedArray] = rightArray[indexOfSecondSubarray];
            indexOfSecondSubarray++;
            shiftOperations++;
        }
        indexOfMergedArray++;
    }

    while (indexOfFirstSubarray < firstSubarray)
    {
        keys[indexOfMergedArray] = leftArray[indexOfFirstSubarray];
        indexOfFirstSubarray++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSecondSubarray < secondSubarray)
    {
        keys[indexOfMergedArray] = rightArray[indexOfSecondSubarray];
        indexOfSecondSubarray++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
