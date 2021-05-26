#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const void *a, const void *b)
{
    const int *x = (int *)a;
    const int *y = (int *)b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}

class Sort
{
public:
    virtual void _sort(vector<int> &c) = 0;
};

class InnySort : public Sort
{
public:
    void _sort(vector<int> &c)
    {
        sort(c.begin(), c.end());
    }
};

class QuickSort : public Sort
{
public:
    void _sort(vector<int> &c)
    {
        qsort(&c[0], c.size(), sizeof(int), compare);
    }
};

class IntVector
{
public:
    Sort *sort_algoryth;
    vector<int> container;
    void sort()
    {
        sort_algoryth->_sort(container);
    }
};
int main()
{
    Sort *basic = new InnySort();
    Sort *q = new QuickSort();
    IntVector vec;
    vec.container = {4, 3, 2, 5, 6, 1, 8, 0, 3};

    vec.sort_algoryth = basic;
    // vec.sort_algoryth = q;

    vec.sort();

    for (int i = 0; i < vec.container.size(); ++i)
    {
        cout << vec.container[i] << '\n';
    }

    return 0;
}