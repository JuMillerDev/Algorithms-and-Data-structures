#include "quickSort.hpp"

QuickSort::QuickSort()
{
    int comparisonOperations = 0;
    int shiftOperations = 0;
    bool lessThanFourty = false;
    n = 0;
    stats = false;
}

void QuickSort::quickSort(int keys[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int p = partition(keys, begin, end);

    quickSort(keys, begin, p - 1);
    quickSort(keys, p + 1, end);
}

int QuickSort::partition(int keys[], int begin, int end)
{
    int pivot = keys[begin];

    int count = 0;
    for (int i = begin + 1; i <= end; i++)
    {
        comparisonOperations++;
        if (keys[i] <= pivot)
        {
            count++;
        }
    }

    int pivotIndex = begin + count;
    swap(&keys[pivotIndex], &keys[begin]);
    shiftOperations++;

    int i = begin, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (keys[i] <= pivot)
        {
            comparisonOperations++;
            i++;
        }
        while (keys[j] > pivot)
        {
            comparisonOperations++;
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            shiftOperations++;
            swap(&keys[i++], &keys[j--]);
        }
    }

    if (lessThanFourty)
    {
        std::cout << std::endl;
        print_data(keys);
    }

    return pivotIndex;
}

void QuickSort::swap(int *first, int *second)
{
    auto temp = *first;

    *first = *second;
    *second = temp;
}

void QuickSort::sort(int n, int keys[])
{
    comparisonOperations = 0;
    shiftOperations = 0;
    this->n = n;

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

    quickSort(keys, 0, n - 1);
    if (lessThanFourty)
    {
        std::cout << std::endl;
        print_data(keys);
    }
}

void QuickSort::getOperationCount()
{
    std::cout << "compares: " << comparisonOperations << std::endl;
    std::cout << "shifts:" << shiftOperations << std::endl;
}

void QuickSort::print_data(int keys[])
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d,", keys[i]);
    }

    std::cout << std::endl;
}
