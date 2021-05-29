#include <iostream>
#include <map>

using namespace std;

class User;

class Mediator
{
public:
    virtual void sendMessage(string msg, int id) = 0;
    virtual void addUser(User *user) = 0;
};

class User
{
public:
    Mediator *mediator;
    int id;
    string nick;
    Mediator *getMediator()
    {
        return this->mediator;
    }
    User(Mediator *mediator, int id, string nick)
    {
        this->mediator = mediator;
        this->id = id;
        this->nick = nick;
    }
    virtual void send(int id, string msg) = 0;
    virtual void receive(string msg) = 0;
};

class Messanger : public Mediator
{
public:
    map<int, User *> users;
    void sendMessage(string msg, int id)
    {
        User *tmp = users.at(id);
        tmp->receive(msg);
    }
    void addUser(User *user)
    {
        this->users.insert(pair<int, User *>(user->id, user));
    }
};

class MessangerUser : public User
{
public:
    MessangerUser(Mediator *mediator, int id, string nick) : User(mediator, id, nick) {}
    void send(int id, string msg)
    {
        cout << this->nick << " Sends message " << msg << '\n';
        this->getMediator()->sendMessage(msg, id);
    }
    void receive(string msg)
    {
        cout << this->nick << " Received message " << msg << '\n';
    }
};

int main()
{
    Mediator *grupa = new Messanger();
    User *u1 = new MessangerUser(grupa, 0, "mirek95");
    User *u2 = new MessangerUser(grupa, 1, "xXxmaciekxXx");
    User *u3 = new MessangerUser(grupa, 2, "czolgistaPL");

    grupa->addUser(u1);
    grupa->addUser(u2);
    grupa->addUser(u3);

    u1->send(2, "siema wariacie");
    u2->send(0, "no co tam ");

    return 0;
}