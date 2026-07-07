#include <iostream>

using namespace std;

class Calculator
{
public:
    Calculator()
    {
        memory = 0;
    }

    Calculator(int startValue)
    {
        memory = startValue;
    }

    void setStartValue(int start)
    {
        memory = start;
    }

    int calculate(char op, int right)
    {
        switch (op)
        {
        case '+':
            memory += right;
            break;
        case '-':
            memory -= right;
            break;
        case '*':
            memory *= right;
            break;
        case '/':
            if (right != 0)
                memory /= right;
            break;
        }
        return memory;
    }

    int calculate(int left, char op, int right)
    {
        switch (op)
        {
        case '+':
            memory = left + right;
            break;
        case '-':
            memory = left - right;
            break;
        case '*':
            memory = left * right;
            break;
        case '/':
            if (right != 0)
                memory = left / right;
            else
                memory = 0;
            break;
        }
        return memory;
    }

private:
    int memory;
};

int main()
{
    Calculator calc1 = 10;
    cout << calc1.calculate('-', 10) << endl;

    cout << "---" << endl;

    Calculator calc2;
    cout << calc2.calculate(50, '/', 5) << endl;

    return 0;
}