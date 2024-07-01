#include <iostream>

using namespace std;

class Calc
{
public:
    int a, b, c;
    char op;

    void getValue1();
    void getValue2();
    void getOperator();
    void add();
    void sub();
    void mul();
    void div();
};

int main()
{

    Calc obj;
    obj.getValue1();

    while (1)
    {
        obj.getOperator();
        if (obj.op == '=')
        {
            cout << "Final Answer : " << obj.a<<"\n";
            break;
        }

        obj.getValue2();

        if (obj.op == '+')
        {
            obj.add();
        }
        else if (obj.op == '-')
        {
            obj.sub();
        }
        else if (obj.op == '*')
        {
            obj.mul();
        }
        else if (obj.op == '/')
        {
            obj.div();
        }
        else
        {
            cout << "This Operation is not available"<<"\n";
        }
    }

    return 0;
}

void Calc ::getValue1()
{
    cout << "Enter the Value : ";
    cin >> a;
}

void Calc ::getValue2()
{
    cout << "Enter the Value : ";
    cin >> b;
}

void Calc ::getOperator()
{
    cout << "Enter the Operator : ";
    cin >> op;
}

void Calc ::add()
{
    c = a + b;
    cout << a << "+" << b << " = " << c<<"\n";
    a = c;
    b = 0;
}

void Calc ::sub()
{
    c = a - b;
    cout << a << "-" << b << " = " << c<<"\n";
    a = c;
    b = 0;
}

void Calc ::mul()
{
    c = a * b;
    cout << a << "*" << b << " = " << c<<"\n";
    a = c;
    b = 0;
}

void Calc ::div()
{
    c = a / b;
    cout << a << "/" << b << " = " << c<<"\n";
    a = c;
    b = 0;
}