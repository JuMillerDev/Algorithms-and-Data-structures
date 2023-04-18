#include <iostream>
#include <array>
#include <string>
#include <chrono>
#include <fstream>
#include <utility>

/* #include "insertionSort.hpp"
#include "dualPivot.hpp"
#include "mergeSort.hpp"
#include "quickSort.hpp"
#include "generator.hpp"
#include "mergeInsertionSort.hpp" */
#include "statistics.hpp"

using namespace std;
using namespace std::chrono;

void generate(string gen, int n, int **data)
{
    if (gen.compare("rand") == 0)
    {
        *data = generateRandom(n);
    }
    else if (gen.compare("asc") == 0)
    {
        *data = generateAscending(n);
    }
    else if (gen.compare("desc") == 0)
    {
        *data = generateDescending(n);
    }
    else
    {
        cout << "wrong command" << endl;
        throw;
    }
}

int main(int argc, char *argv[])
{
    // generator_danych n program_sortujacy stats?(bool)
    if (stoi(argv[4]) == 1)
    {
        stats();
        return 0;
    }
    else if (argc != 5)
    {
        cout << "Wrong amount of elements" << endl;
        return 1;
    }

    string gen, sort;
    int n;
    high_resolution_clock::time_point start, end;
    int *data;

    gen = argv[1];
    sort = argv[3];

    try
    {
        n = stoi(argv[2]);
    }
    catch (exception)
    {
        cout << "wrong data while converting in 2 argument" << endl;
        return 1;
    }

    // generating array
    generate(gen, n, &data);

    // sorting
    if (sort.compare("insert") == 0)
    {
        cout << "Insertion sort | n = " << n << endl;
        InsertionSort sort_alg;
        start = high_resolution_clock::now();
        sort_alg.sort(n, data);
        end = high_resolution_clock::now();
        sort_alg.getOperationCount();
    }
    else if (sort.compare("merge") == 0)
    {
        cout << "Merge Sort | n = " << n << endl;
        MergeSort sort_alg;
        start = high_resolution_clock::now();
        sort_alg.sort(n, data);
        end = high_resolution_clock::now();
        sort_alg.getOperationCount();
    }
    else if (sort.compare("quick") == 0)
    {
        cout << "Quick sort | n = " << n << endl;
        QuickSort sort_alg;
        start = high_resolution_clock::now();
        sort_alg.sort(n, data);
        end = high_resolution_clock::now();
        sort_alg.getOperationCount();
    }
    else if (sort.compare("dual_pivot") == 0)
    {
        cout << "Dual pivot sort | n = " << n << endl;
        DualPivot sort_alg;
        start = high_resolution_clock::now();
        sort_alg.sort(n, data);
        end = high_resolution_clock::now();
        sort_alg.getOperationCount();
    }
    else if (sort.compare("merge_insert") == 0)
    {
        cout << "Merge-Insert sort | n = " << n << endl;
        MergeInsertSort sort_alg;
        start = high_resolution_clock::now();
        sort_alg.sort(n, data);
        end = high_resolution_clock::now();
        sort_alg.getOperationCount();
    }
    else
    {
        cout << "wrong command" << endl;
        throw;
    }

    // cout << "time: " << duration_cast<chrono::nanoseconds>(end - start).count() << endl;
    cout << "time: " << duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9 << endl;

    return 0;
}