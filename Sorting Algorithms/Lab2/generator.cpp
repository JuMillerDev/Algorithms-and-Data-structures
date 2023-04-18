#include "generator.hpp"

using namespace std;

int *generateRandom(int n)
{
    int *generated = new int[n];

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist(0, 2 * n - 1);

    for (size_t i = 0; i < n; i++)
    {
        generated[i] = dist(rng);
    }

    int *pointer = generated;
    return pointer;
}

int *generateAscending(int n)
{
    int *generated = new int[n];
    int adder = 0 + (rand() % (n - 1));

    for (size_t i = 0; i < n; i++)
    {
        generated[i] = i + adder;
    }

    int *pointer1 = generated;
    return pointer1;
}

int *generateDescending(int n)
{
    int *generated = new int[n];
    int adder = 0 + (rand() % (n - 1));

    int counter = n;
    for (size_t i = 0; i < n; i++)
    {
        generated[i] = counter + adder;
        counter--;
    }

    int *pointer = generated;
    return pointer;
}