#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

/*
         ▄              ▄    
        ▌▒█           ▄▀▒▌   
        ▌▒▒█        ▄▀▒▒▒▐   
       ▐▄█▒▒▀▀▀▀▄▄▄▀▒▒▒▒▒▐   
     ▄▄▀▒▒▒▒▒▒▒▒▒▒▒█▒▒▄█▒▐   
   ▄▀▒▒▒░░░▒▒▒░░░▒▒▒▀██▀▒▌   
  ▐▒▒▒▄▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄▒▌  
  ▌░░▌█▀▒▒▒▒▒▄▀█▄▒▒▒▒▒▒▒█▒▐  
 ▐░░░▒▒▒▒▒▒▒▒▌██▀▒▒░░░▒▒▒▀▄▌ 
 ▌░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░▒▒▒▒▌ 
▌▒▒▒▄██▄▒▒▒▒▒▒▒▒░░░░░░░░▒▒▒▐ 
▐▒▒▐▄█▄█▌▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▒▌
▐▒▒▐▀▐▀▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒░▒▒▐ 
 ▌▒▒▀▄▄▄▄▄▄▒▒▒▒▒▒▒▒░▒░▒░▒▒▒▌ 
 ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▒▄▒▒▐  
  ▀▄▒▒▒▒▒▒▒▒▒▒▒▒▒░▒░▒▄▒▒▒▒▌  
    ▀▄▒▒▒▒▒▒▒▒▒▒▄▄▄▀▒▒▒▒▄▀   
      ▀▄▄▄▄▄▄▀▀▀▒▒▒▒▒▄▄▀     
         ▀▀▀▀▀▀▀▀▀▀▀▀   
*/
class Observer
{
public:
    virtual void update(float diff) {}
};

class Subscriber : public Observer
{
public:
    string nick;
    Subscriber(string nick)
    {
        this->nick = nick;
    }
    void update(float diff)
    {
        cout << nick << " was notified!\n";
        cout << "Doge price has change by " << (diff - 1) * 100 << " percent\n";
    }
};

class DogeNotifier
{
public:
    vector<Observer *> subscribers;
    float doge_price;
    void add_subscriber(Observer *subscriber)
    {
        subscribers.push_back(subscriber);
    }
    void remove_subscriber(Observer *subscriber);
    void notify(float diff)
    {
        for (int i = 0; i < subscribers.size(); ++i)
        {
            subscribers[i]->update(diff);
        }
    }
    void update_price(float new_price)
    {
        float ratio = new_price / doge_price;
        doge_price = new_price;
        if (ratio > 1.01 || ratio < 0.99)
        {
            notify(ratio);
        }
    }
};

int main()
{

    DogeNotifier notifier;
    notifier.doge_price = 0.4512;
    Observer *o1 = new Subscriber("Piesek1");
    Observer *o2 = new Subscriber("xXxPolakxXx");
    notifier.add_subscriber(o1);
    notifier.add_subscriber(o2);

    for (int i = 0; i < 100; ++i)
    {
        notifier.update_price(notifier.doge_price * ((rand() % 100) / 100.0) + 0.495);
        sleep(1);
    }

    return 0;
}