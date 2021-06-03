#include <iostream>

using namespace std;

class Telewizor
{
public:
    virtual void wlacz() = 0;
    virtual void ustawGlosnosc(int n) = 0;
    virtual void zmienProgram(int n) = 0;
};

class Plazma : public Telewizor
{
public:
    int cur_program = 0;
    int cur_volume = 0;
    void wlacz()
    {
        cout << "Włączam telewizor\n";
    }
    void ustawGlosnosc(int n)
    {
        this->cur_volume = n;
        cout << "Glosnows = " << n << '\n';
    }
    void zmienProgram(int n)
    {
        this->cur_program = n;
        cout << "Program = " << n << '\n';
    }
};

class Pilot
{
public:
    Telewizor *tv;
    void zmienProgram(int n)
    {
        tv->zmienProgram(n);
    }
    void zmienGlosnosc(int n)
    {
        tv->ustawGlosnosc(n);
    }
    void wlacz()
    {
        tv->wlacz();
    }
};

class SuperPilot : public Pilot
{
public:
    void mute()
    {
        this->tv->ustawGlosnosc(0);
    }
};

int main()
{
    Telewizor *p = new Plazma();
    SuperPilot pilot;
    pilot.tv = p;
    pilot.wlacz();
    pilot.zmienGlosnosc(10);
    pilot.zmienProgram(42);
    pilot.mute();

    return 0;
}