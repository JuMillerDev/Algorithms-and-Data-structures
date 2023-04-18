#include "statistics.hpp"

void stats()
{
    // we have 5 algorithms for testing
    // write parameters for each to csv
    string file_name = "stats_20000";
    ofstream statistic(file_name + ".csv");
    int starting_algorithm = 1;
    high_resolution_clock::time_point start, end;
    int k, shift, comp, n, expected_k = 0;
    int n_interval = 1000;
    int n_limit = 20000;
    int *data;

    if (starting_algorithm == 0)
    {
        statistic << "name,n,k,time,comparisons,swaps,comparisons/n,swaps/n" << endl;
    }

    for (int i = starting_algorithm; i < 5; i++)
    {
        n = n_interval;
        expected_k = 1;
        if (i == 0)
        {
            InsertionSort ins;
            ins.stats = true;
            while (expected_k <= 100)
            {
                comp = 0;
                shift = 0;
                for (int k = 0; k < expected_k; k++)
                {
                    data = generateRandom(n);

                    start = high_resolution_clock::now();
                    ins.sort(n, data);
                    end = high_resolution_clock::now();

                    comp += ins.comparisonOperations;
                    shift += ins.shiftOperations;
                    delete data;
                }
                double avr_comp = comp / expected_k;
                double avr_shift = shift / expected_k;
                auto time = duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9;

                statistic << "insert"
                          << "," << n << "," << expected_k << "," << time << "," << avr_comp << "," << avr_shift << "," << avr_comp / n << "," << avr_shift / n << endl;

                if (n == n_limit)
                {
                    expected_k *= 10;
                    n = n_interval;
                }
                else
                {
                    n += n_interval;
                }
            }
        }
        else if (i == 1)
        {
            MergeSort mer;
            mer.stats = true;
            while (expected_k <= 100)
            {
                comp = 0;
                shift = 0;
                for (int k = 0; k < expected_k; k++)
                {
                    data = generateRandom(n);

                    start = high_resolution_clock::now();
                    mer.sort(n, data);
                    end = high_resolution_clock::now();

                    comp += mer.comparisonOperations;
                    shift += mer.shiftOperations;
                    delete data;
                }
                double avr_comp = comp / expected_k;
                double avr_shift = shift / expected_k;
                auto time = duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9;

                statistic << "merge"
                          << "," << n << "," << expected_k << "," << time << "," << avr_comp << "," << avr_shift << "," << avr_comp / n << "," << avr_shift / n << endl;

                if (n == n_limit)
                {
                    expected_k *= 10;
                    n = n_interval;
                }
                else
                {
                    n += n_interval;
                }
            }
        }
        else if (i == 2)
        {
            QuickSort quick;
            quick.stats = true;
            while (expected_k <= 100)
            {
                comp = 0;
                shift = 0;
                for (int k = 0; k < expected_k; k++)
                {
                    data = generateRandom(n);

                    start = high_resolution_clock::now();
                    quick.sort(n, data);
                    end = high_resolution_clock::now();

                    comp += quick.comparisonOperations;
                    shift += quick.shiftOperations;
                    delete data;
                }
                double avr_comp = comp / expected_k;
                double avr_shift = shift / expected_k;
                auto time = duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9;

                statistic << "quick"
                          << "," << n << "," << expected_k << "," << time << "," << avr_comp << "," << avr_shift << "," << avr_comp / n << "," << avr_shift / n << endl;

                if (n == n_limit)
                {
                    expected_k *= 10;
                    n = n_interval;
                }
                else
                {
                    n += n_interval;
                }
            }
        }
        else if (i == 3)
        {
            DualPivot piv;
            piv.stats = true;
            while (expected_k <= 100)
            {
                comp = 0;
                shift = 0;
                for (int k = 0; k < expected_k; k++)
                {
                    data = generateRandom(n);

                    start = high_resolution_clock::now();
                    piv.sort(n, data);
                    end = high_resolution_clock::now();

                    comp += piv.comparisonOperations;
                    shift += piv.shiftOperations;
                    delete data;
                }
                double avr_comp = comp / expected_k;
                double avr_shift = shift / expected_k;
                auto time = duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9;

                statistic << "pivot"
                          << "," << n << "," << expected_k << "," << time << "," << avr_comp << "," << avr_shift << "," << avr_comp / n << "," << avr_shift / n << endl;

                if (n == n_limit)
                {
                    expected_k *= 10;
                    n = n_interval;
                }
                else
                {
                    n += n_interval;
                }
            }
        }
        else
        {
            MergeInsertSort mi;
            mi.stats = true;
            while (expected_k <= 100)
            {
                comp = 0;
                shift = 0;
                for (int k = 0; k < expected_k; k++)
                {
                    data = generateRandom(n);

                    start = high_resolution_clock::now();
                    mi.sort(n, data);
                    end = high_resolution_clock::now();

                    comp += mi.comparisonOperations;
                    shift += mi.shiftOperations;
                    delete data;
                }
                double avr_comp = comp / expected_k;
                double avr_shift = shift / expected_k;
                auto time = duration_cast<chrono::nanoseconds>(end - start).count() / 1e+9;

                statistic << "merge_ins"
                          << "," << n << "," << expected_k << "," << time << "," << avr_comp << "," << avr_shift << "," << avr_comp / n << "," << avr_shift / n << endl;

                if (n == n_limit)
                {
                    expected_k *= 10;
                    n = n_interval;
                }
                else
                {
                    n += n_interval;
                }
            }
        }
    }

    statistic.close();
}