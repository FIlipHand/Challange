#include <iostream>
#include <vector>

using namespace std;

class Nexus
{
public:
    int energy;
    void chronoboost()
    {
        if (energy < 50)
        {
            cout << "You require more energy.\n";
        }
        else
        {
            cout << "Used chronoboost.\n";
            energy -= 50;
        }
    }
    void make_prob()
    {
        cout << "Probe created.\n";
    }
};

class Iterator
{
public:
    virtual Nexus *next() = 0;
    virtual bool hasNext() = 0;
};

class NexusIterator : public Iterator
{
public:
    Nexus *next()
    {
        ++cur_index;
        return container[cur_index];
    }
    bool hasNext()
    {
        if (container.size() - 1 == cur_index)
        {
            return false;
        }
        return true;
    }
    vector<Nexus *> container;

private:
    int cur_index = -1;
};

int main()
{
    Nexus *n1 = new Nexus();
    n1->energy = 100;
    Nexus *n2 = new Nexus();
    n2->energy = 20;
    Nexus *n3 = new Nexus();
    n3->energy = 200;

    NexusIterator iter;
    iter.container.push_back(n1);
    iter.container.push_back(n2);
    iter.container.push_back(n3);

    iter.next()->chronoboost();
    iter.next()->chronoboost();
    iter.next()->chronoboost();
    cout << iter.hasNext() << '\n';

    return 0;
}