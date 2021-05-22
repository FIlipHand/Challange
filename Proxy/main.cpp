#include <iostream>

using namespace std;

class IObject
{
public:
    virtual void send_msg(string message) = 0;
};

class Object : public IObject
{
public:
    void send_msg(string message)
    {
        cout << message << '\n';
    }
};

class Proxy : public Object
{
private:
    Object *object;

public:
    Proxy(Object *o)
    {
        this->object = o;
    }
    void send_msg(string message)
    {
        if (message == "dupa")
            cout << "Thats a bad language word!\n";
        else
            object->send_msg(message);
    }
};

int main()
{
    Object *object = new Object();
    Proxy proxy = Proxy(object);
    proxy.send_msg("dupa");
    proxy.send_msg("siema");
}