#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sorting
{
public:
    virtual int compare(const void *a, const void *b) = 0;
    void _sort(vector<int> &v)
    {
        sort(v.begin(), v.end(), compare);
    }
};

class AscendSort : public Sorting
{
public:
    int compare(void *a, void *b)
    {
        return (*(const int *)b - *(const int *)a);
    }
};

class DescentSort : public Sorting
{
public:
    int compare(const void *a, const void *b)
    {
        return (*(const int *)b - *(const int *)a);
    }
};

int main()
{
    DescentSort *sortowanko;
    vector<int> vec = {4, 5, 2, 5, 1, 6, 7, 2, 4, 6, 0};
    sortowanko->_sort(vec);
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}