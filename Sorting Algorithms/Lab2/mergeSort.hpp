#pragma once

#include <iostream>

class MergeSort
{
private:
    bool lessThanFourty;
    int n;

public:
    bool stats;
    int comparisonOperations;
    int shiftOperations;
    MergeSort();
    void mergeSort(int keys[], int begin, int end);
    void merge(int keys[], int left, int mid, int right);
    void sort(int n, int keys[]);
    void print_data(int keys[]);
    void getOperationCount();
};