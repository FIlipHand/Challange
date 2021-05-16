#include <iostream>

using namespace std;

class IKebab
{
public:
    virtual void zakup() = 0;
};

class Kebab : public IKebab
{
public:
    virtual void zakup()
    {
        cout << "Kupije kebaba";
    }
};

class Decorator : public IKebab
{
public:
    IKebab *m_kebab;
    Decorator(IKebab *kebab) : m_kebab(kebab) {}
    void zakup()
    {
        m_kebab->zakup();
    }
};

class zLagodnym : public Decorator
{
public:
    zLagodnym(IKebab *kebab) : Decorator(kebab) {}
    virtual void zakup()
    {
        Decorator::zakup();
        cout << " z lagodnym sosem ";
    }
};

class zOstrym : public Decorator
{
public:
    zOstrym(IKebab *kebab) : Decorator(kebab) {}
    virtual void zakup()
    {
        Decorator::zakup();
        cout << " z ostrym sosem ";
    }
};

class zMieszanym : public Decorator
{
public:
    zMieszanym(IKebab *kebab) : Decorator(kebab) {}
    virtual void zakup()
    {
        Decorator::zakup();
        cout << " z mieszanym sosem ";
    }
};

class zKurczakiem : public Decorator
{
public:
    zKurczakiem(IKebab *kebab) : Decorator(kebab) {}
    virtual void zakup()
    {
        Decorator::zakup();
        cout << " z kurczakiem ";
    }
};

class zBaranina : public Decorator
{
public:
    zBaranina(IKebab *kebab) : Decorator(kebab) {}
    virtual void zakup()
    {
        Decorator::zakup();
        cout << " z baranina ";
    }
};

int main()
{
    IKebab *kebab = new zOstrym(new zKurczakiem(new Kebab()));
    kebab->zakup();
    return 0;
}