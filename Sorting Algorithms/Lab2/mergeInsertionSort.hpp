#pragma once

#include <iostream>

class MergeInsertSort
{
private:
    int treshold;
    bool lessThanFourty;

public:
    bool stats;
    int comparisonOperations;
    int shiftOperations;
    MergeInsertSort();
    void mergeSort(int keys[], int begin, int end);
    void insertionSort(int keys[], int begin, int end);
    void merge(int keys[], int left, int mid, int right);
    void sort(int n, int keys[]);
    void getOperationCount();
};