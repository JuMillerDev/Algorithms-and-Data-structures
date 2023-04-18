#include "insertionSort.hpp"
using namespace std;

InsertionSort::InsertionSort()
{
    comparisonOperations = 0;
    shiftOperations = 0;
    lessThanFourty = false;
    stats = false;
    n = 0;
}

void InsertionSort::print_data(int keys[])
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%02d,", keys[i]);
    }

    cout << endl;
}

void InsertionSort::sort(int n, int keys[])
{
    comparisonOperations = 0;
    shiftOperations = 0;
    this->n = n;
    copy(keys, keys + n, copied_keys);

    if (n < 40 && !stats)
    {
        lessThanFourty = true;
        print_data(keys);
    }
    else
    {
        lessThanFourty = false;
    }

    int key = 0;
    int previousKey = 0;

    for (int step = 1; step < n; step++)
    {
        key = keys[step];
        previousKey = step - 1;

        // compare the key to all previous keys

        while (key < keys[previousKey] && previousKey >= 0)
        {
            keys[previousKey + 1] = keys[previousKey];
            previousKey--;
        }

        keys[previousKey + 1] = key;
        if (lessThanFourty)
            print_data(keys);
    }

    if (lessThanFourty)
    {
        print_data(keys);
    }
    countOperations();
}

void InsertionSort::getOperationCount()
{
    cout << "compares: " << comparisonOperations << endl;
    cout << "shifts:" << shiftOperations << endl;
}

void InsertionSort::countOperations()
{
    // int key = 0;
    int previousKey = 0;

    for (int step = 1; step < n; step++)
    {
        // key = keys[step];
        previousKey = step - 1;

        // compare the key to all previous keys

        while (copied_keys[step] < copied_keys[previousKey] && previousKey >= 0)
        {
            copied_keys[previousKey + 1] = copied_keys[previousKey];
            comparisonOperations++;
            shiftOperations++;
            previousKey--;
        }

        copied_keys[previousKey + 1] = copied_keys[step];
        shiftOperations++;
    }
}
