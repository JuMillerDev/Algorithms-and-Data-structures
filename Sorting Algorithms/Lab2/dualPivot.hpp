#pragma once

#include <iostream>

class DualPivot
{
private:
    bool lessThanFourty;
    int n;

public:
    bool stats;
    int comparisonOperations;
    int shiftOperations;
    DualPivot();
    void swap(int *first, int *second);
    void pivotSort(int keys[], int begin, int end);
    int partition(int keys[], int begin, int end, int *lp);
    void sort(int n, int keys[]);
    void getOperationCount();
    void print_data(int keys[]);
};