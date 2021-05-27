#include <iostream>
#include <vector>

using namespace std;

class Memento
{
public:
    Memento(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return this->state;
    }

private:
    string state;
};

class MyString
{
public:
    MyString(string str)
    {
        this->str = str;
    }
    void setString(string str)
    {
        this->str = str;
    }
    string getString()
    {
        return this->str;
    }
    Memento save()
    {
        return Memento(str);
    }
    void getFromHistory(Memento state)
    {
        str = state.getState();
    }

private:
    string str;
};

class History
{
public:
    void add(Memento state)
    {
        saved.push_back(state);
    }
    Memento get(int index)
    {
        return saved[index];
    }

private:
    vector<Memento> saved;
};

int main()
{
    History hist;
    MyString mystr = MyString("z z z z beuka");
    hist.add(mystr.save());
    mystr.setString("skurczybyku");
    hist.add(mystr.save());
    mystr.setString("ej to torreador bitow");
    hist.add(mystr.save());
    cout << "Curr. state: " << mystr.getString() << ".\n";
    mystr.getFromHistory(hist.get(1));
    cout << "Curr. state: " << mystr.getString() << ".\n";

    return 0;
}