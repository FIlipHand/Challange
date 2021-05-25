#include <iostream>
#include <queue>

using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class History
{
public:
    queue<Command *> commands;
    void execute()
    {
        commands.front()->execute();
        commands.pop();
    }
};

class Integer
{
public:
    int cur_value;
};

class Increment : public Command
{
public:
    Increment(Integer *operand)
    {
        this->operand = operand;
    }
    Integer *operand;
    void execute()
    {
        cout << "Incrementing...\n";
        ++operand->cur_value;
    }
};

class PowerOfTwo : public Command
{
public:
    PowerOfTwo(Integer *operand)
    {
        this->operand = operand;
    }
    Integer *operand;
    void execute()
    {
        cout << "Rising to the power of two...\n";
        operand->cur_value *= operand->cur_value;
    }
};

int main()
{
    History *history = new History;

    Integer *integer = new Integer;
    integer->cur_value = 5;
    Command *power = new PowerOfTwo(integer);
    Command *inc = new Increment(integer);

    history->commands.push(power);
    history->commands.push(inc);
    history->commands.push(inc);
    history->commands.push(power);
    history->commands.push(inc);

    while (!history->commands.empty())
    {
        history->execute();
        cout << integer->cur_value << '\n';
    }

    return 0;
}