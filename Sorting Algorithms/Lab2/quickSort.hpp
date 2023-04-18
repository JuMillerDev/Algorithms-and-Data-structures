#pragma once

#include <iostream>

class QuickSort
{
private:
    bool lessThanFourty;
    int n;

public:
    bool stats;
    int comparisonOperations;
    int shiftOperations;
    QuickSort();
    void swap(int *first, int *second);
    void quickSort(int keys[], int begin, int end);
    int partition(int keys[], int begin, int end);
    void sort(int n, int keys[]);
    void getOperationCount();
    void print_data(int keys[]);
};