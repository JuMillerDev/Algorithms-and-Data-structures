#pragma once

#include <iostream>
#include <algorithm>
#include <utility>

class InsertionSort
{
private:
    bool lessThanFourty;
    int n;
    int *copied_keys;

public:
    bool stats;
    int comparisonOperations;
    int shiftOperations;
    InsertionSort();
    void print_data(int keys[]);
    void sort(int n, int keys[]);
    void getOperationCount();
    void countOperations();
};
