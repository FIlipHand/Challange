#include <iostream>

using namespace std;

class NormalLibrary
{
public:
    virtual string getMessage()
    {
        return "Normalna wiadomosc";
    }
};

class WierdLibrary
{
public:
    string getWierdMessage()
    {
        return "Zezb waxz fkwvkfbofb miw";
    }
};

class Adapter : public NormalLibrary
{
public:
    WierdLibrary *wrdlib;
    Adapter(WierdLibrary *wrdlib)
    {
        this->wrdlib = wrdlib;
    }
    string getMessage()
    {
        string wierd_message = this->wrdlib->getWierdMessage();
        char ch;
        for (int i = 0; wierd_message[i] != '\0'; ++i)
        {
            ch = wierd_message[i];
            if (ch >= 'a' && ch <= 'z')
            {
                ch = ch + 3;
                if (ch > 'z')
                {
                    ch = ch - 'z' + 'a' - 1;
                }
                wierd_message[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + 3;
                if (ch > 'Z')
                {
                    ch = ch - 'Z' + 'A' - 1;
                }
                wierd_message[i] = ch;
            }
        }
        return wierd_message;
    }
};

int main()
{
    NormalLibrary *normlib = new NormalLibrary();
    cout << normlib->getMessage() << '\n';
    WierdLibrary *wrdlib = new WierdLibrary();
    cout << wrdlib->getWierdMessage() << '\n';
    Adapter *adapter = new Adapter(wrdlib);
    cout << adapter->getMessage() << '\n';

    return 0;
}