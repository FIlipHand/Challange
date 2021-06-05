#include <iostream>
#include <vector>

using namespace std;

class ClassA;
class ClassB;

class Visitor
{
public:
    virtual void visit(ClassA *a) = 0;
    virtual void visit(ClassB *b) = 0;
};

class Element
{
public:
    virtual void accept(Visitor *v) = 0;
};
class ClassA : public Element
{
public:
    void sth_a()
    {
        cout << "ClassA::sth_a()\n";
    }
    void accept(Visitor *v);
};

class ClassB : public Element
{
public:
    void sth_b()
    {
        cout << "ClassB::sth_b()\n";
    }
    void accept(Visitor *v);
};

class DoSthVisitor : public Visitor
{
public:
    void visit(ClassA *a)
    {
        a->sth_a();
    }
    void visit(ClassB *b)
    {
        b->sth_b();
    }
};

void ClassA::accept(Visitor *v)
{
    v->visit(this);
}

void ClassB::accept(Visitor *v)
{
    v->visit(this);
}

int main()
{
    Visitor *visitor = new DoSthVisitor();
    vector<Element *> vec = {new ClassA(), new ClassB(), new ClassB(), new ClassA()};
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i]->accept(visitor);
    }

    return 0;
}