#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorting
{
public:
    virtual int compare(int a, int b) = 0;
    void _sort(vector<int> &v)
    {
        int i, j, min_idx;

        for (i = 0; i < v.size() - 1; i++)
        {
            min_idx = i;
            for (j = i + 1; j < v.size(); j++)
                if (compare(v[j], v[min_idx]))
                    min_idx = j;

            swap(v[min_idx], v[i]);
        }
    }
};

class AscendSort : public Sorting
{
public:
    int compare(int a, int b)
    {
        return b > a;
    }
};

class DescentSort : public Sorting
{
public:
    int compare(int a, int b)
    {
        return b < a;
    }
};

int main()
{
    AscendSort *sortowanko = new AscendSort();
    vector<int> vec = {4, 5, 2, 5, 1, 6, 7, 2, 4, 6, 0};
    sortowanko->_sort(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}