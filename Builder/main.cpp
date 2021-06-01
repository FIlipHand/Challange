#include <iostream>

using namespace std;

class Builder
{
public:
    virtual void budujPiwnice() = 0;
    virtual void budujSciany() = 0;
    virtual void budujDach() = 0;
};

class DomZCegly : public Builder
{
public:
    bool piwnica;
    string sciany;
    string dach;
    void budujPiwnice()
    {
        this->piwnica = true;
    }
    void budujSciany()
    {
        this->sciany = "sciany z cegly";
    }
    void budujDach()
    {
        this->sciany = "ceglany dach?";
    }
};

class DomZDrewna : public Builder
{
public:
    bool piwnica;
    string sciany;
    string dach;
    void budujPiwnice()
    {
        this->piwnica = false;
    }
    void budujSciany()
    {
        this->sciany = "scainy z drewna";
    }
    void budujDach()
    {
        this->dach = "dach z drewna";
    }
};

class Director
{
public:
    Builder *builder;
    void rob()
    {
        this->builder->budujPiwnice();
        this->builder->budujSciany();
        this->builder->budujDach();
    }
};

int main()
{
    DomZCegly *cegla = new DomZCegly();
    DomZDrewna *drewno = new DomZDrewna();
    Director *mirek = new Director();
    mirek->builder = cegla;
    mirek->rob();

    cout << cegla->piwnica << ' ' << cegla->sciany << ' ' << cegla->dach << '\n';

    mirek->builder = drewno;
    mirek->rob();

    cout << drewno->piwnica << ' ' << drewno->sciany << ' ' << drewno->dach << '\n';

    return 0;
}