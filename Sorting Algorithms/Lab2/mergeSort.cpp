#include "mergeSort.hpp"

using namespace std;

MergeSort::MergeSort()
{
    comparisonOperations = 0;
    shiftOperations = 0;
    lessThanFourty = false;
    n = 0;
    stats = false;
}

void MergeSort::merge(int keys[], int const left, int const mid, int const right)
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
        comparisonOperations++;
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

    if (lessThanFourty)
        print_data(keys);
}

void MergeSort::mergeSort(int keys[], int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(keys, begin, mid);
    mergeSort(keys, mid + 1, end);
    merge(keys, begin, mid, end);
}

void MergeSort::sort(int n, int keys[])
{
    auto begin = 0;
    auto end = n - 1;
    this->n = n;

    comparisonOperations = 0;
    shiftOperations = 0;

    if (n < 40 && !stats)
    {
        lessThanFourty = true;
        print_data(keys);
        std::cout << std::endl;
    }
    else
    {
        lessThanFourty = false;
    }

    mergeSort(keys, begin, end);

    if (lessThanFourty)
    {
        std::cout << std::endl;
        print_data(keys);
    }
}

void MergeSort::print_data(int keys[])
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d,", keys[i]);
    }

    cout << endl;
}

void MergeSort::getOperationCount()
{
    cout << "compares: " << comparisonOperations << endl;
    cout << "shifts:" << shiftOperations << endl;
}