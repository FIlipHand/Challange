#include <iostream>
#include <vector>

using namespace std;

class Iterator
{
public:
    virtual int next() = 0;
    virtual bool hasNext() = 0;
};

class Iterable
{
public:
    virtual Iterator *getIterator() = 0;
};

class IntVector : public Iterable
{
public:
    Iterator *getIterator();
    vector<int> intvec;
};

class VecIterator : public Iterator
{
public:
    VecIterator(IntVector *container);
    IntVector *container;
    int next();
    bool hasNext();

private:
    int cur_index = 0;
};

Iterator *IntVector::getIterator()
{
    return new VecIterator(this);
}

int VecIterator::next()
{
    if (this->hasNext())
    {
        return this->container->intvec[this->cur_index++];
    }
    else
    {
        return -1;
    }
}

bool VecIterator::hasNext()
{
    if (this->cur_index == this->container->intvec.size())
        return false;
    else
        return true;
}

VecIterator::VecIterator(IntVector *container)
{
    this->container = container;
}

int main()
{
    IntVector vec;
    vec.intvec.push_back(1);
    vec.intvec.push_back(4);
    vec.intvec.push_back(2);

    Iterator *iter = vec.getIterator();
    while (iter->hasNext())
    {
        cout << iter->next() << '\n';
    }

    return 0;
}