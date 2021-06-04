#include <iostream>
#include <map>

using namespace std;

class Maziak
{
public:
    virtual void rysuj() = 0;
    virtual void setKolor(string kolor) = 0;
};

class GrubyMazik : public Maziak
{
public:
    string kolor;
    void rysuj()
    {
        cout << "Pisze grubym maziakiem koluru " << kolor << '\n';
    }
    void setKolor(string kolor)
    {
        this->kolor = kolor;
    }
};

class CienkiMaziak : public Maziak
{
public:
    string kolor;
    void rysuj()
    {
        cout << "Pisze cienkim maziakiem koluru " << kolor << '\n';
    }
    void setKolor(string kolor)
    {
        this->kolor = kolor;
    }
};

class FabrykaMaziakow
{
public:
    map<string, Maziak *> mapa;
    Maziak *getGrubyMaziak(string kolor)
    {
        string key = kolor + "-gruby";
        Maziak *tmp;
        try
        {
            tmp = mapa.at(key);
        }
        catch (exception &ex)
        {
            tmp = new GrubyMazik();
            tmp->setKolor(kolor);
            mapa.insert(pair<string, Maziak *>(kolor, tmp));
            return tmp;
        }
        return tmp;
    }
    Maziak *getCienkiMaziak(string kolor)
    {
        string key = kolor + "-gruby";
        Maziak *tmp;
        try
        {
            tmp = mapa.at(key);
        }
        catch (exception &ex)
        {
            tmp = new GrubyMazik();
            tmp->setKolor(kolor);
            mapa.insert(pair<string, Maziak *>(kolor, tmp));
            return tmp;
        }
        return tmp;
    }
};
int main()
{
    FabrykaMaziakow fabryka;
    Maziak *m1 = fabryka.getCienkiMaziak("czarny");
    m1->rysuj();
    cout << m1 << '\n';
    Maziak *m2 = fabryka.getCienkiMaziak("czarny");
    m2->rysuj();
    cout << m2 << '\n';
    Maziak *m3 = fabryka.getGrubyMaziak("niebieski");
    m3->rysuj();
    cout << m3 << '\n';

    return 0;
}