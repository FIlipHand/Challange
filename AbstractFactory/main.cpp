#include <iostream>

using namespace std;

class Pizza
{
};

class PizzaHawajska : public Pizza
{
};

class PizzaMargherita : public Pizza
{
};

class Spaghetti
{
};

class SpaghettiBolognese : public Spaghetti
{
};

class SpaghettiCarbonara : public Spaghetti
{
};

class AbstractFactory
{
public:
    virtual Pizza *makePizza() = 0;
    virtual Spaghetti *makeSpaghetti() = 0;
};

class RestaurantA : public AbstractFactory
{
public:
    Pizza *makePizza()
    {
        cout << "Oto twoja Margherita\n";
        return new PizzaMargherita;
    }
    Spaghetti *makeSpaghetti()
    {
        cout << "Oto twoje Spaghetti Bolognese\n";
        return new SpaghettiBolognese;
    }
};

class RestaurantB : public AbstractFactory
{
public:
    Pizza *makePizza()
    {
        cout << "Oto twoja Pizza Hawajska psucholu\n";
        return new PizzaHawajska;
    }
    Spaghetti *makeSpaghetti()
    {
        cout << "Oto twoja Carbonara\n";
        return new SpaghettiCarbonara;
    }
};

int main()
{
    AbstractFactory *restaurant1 = new RestaurantA();
    Pizza *zamowienie1 = restaurant1->makePizza();

    AbstractFactory *restaurant2 = new RestaurantB();
    Spaghetti *zamowienie2 = restaurant2->makeSpaghetti();

    return 0;
}