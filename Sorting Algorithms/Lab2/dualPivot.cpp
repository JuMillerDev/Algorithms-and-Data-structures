#include "dualPivot.hpp"

DualPivot::DualPivot()
{
    int comparisonOperations = 0;
    int shiftOperations = 0;
    bool lessThanFourty = false;
    n = 0;
    stats = false;
}

void DualPivot::swap(int *first, int *second)
{
    auto temp = *first;

    *first = *second;
    *second = temp;
}

void DualPivot::sort(int n, int keys[])
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

    pivotSort(keys, 0, n - 1);

    if (lessThanFourty)
    {
        std::cout << std::endl;
        print_data(keys);
    }
}

void DualPivot::pivotSort(int keys[], int begin, int end)
{
    if (begin < end)
    {
        // lp - left pivot
        // rp - right pivot
        int lp, rp;
        rp = partition(keys, begin, end, &lp);
        pivotSort(keys, begin, lp - 1);
        pivotSort(keys, lp + 1, rp - 1);
        pivotSort(keys, rp + 1, end);
    }
}

int DualPivot::partition(int keys[], int begin, int end, int *lp)
{
    if (keys[begin] > keys[end])
    {
        shiftOperations++;
        swap(&keys[begin], &keys[end]);
    }

    int j = begin + 1;
    // p is left pivot, q is right pivot
    int g = end - 1, k = begin + 1, p = keys[begin], q = keys[end];

    while (k <= g)
    {
        if (keys[k] < p)
        {
            shiftOperations++;
            swap(&keys[k], &keys[j]);
            j++;
        }
        else if (keys[k] >= q)
        {
            while (keys[g] > q && k < g)
            {
                g--;
                comparisonOperations++;
            }
            swap(&keys[k], &keys[g]);
            shiftOperations++;
            g--;
            if (keys[k] < p)
            {
                comparisonOperations++;
                swap(&keys[k], &keys[j]);
                j++;
            }
        }
        k++;
        comparisonOperations++;
    }
    j--;
    g++;

    shiftOperations += 2;
    swap(&keys[begin], &keys[j]);
    swap(&keys[end], &keys[g]);

    *lp = j;

    if (lessThanFourty)
    {
        std::cout << std::endl;
        print_data(keys);
    }

    return g;
}

void DualPivot::getOperationCount()
{
    std::cout << "compares: " << comparisonOperations << std::endl;
    std::cout << "shifts:" << shiftOperations << std::endl;
}

void DualPivot::print_data(int keys[])
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d,", keys[i]);
    }

    std::cout << std::endl;
}
