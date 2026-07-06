#include <iostream>

using namespace std;

class Calculator
{
public:
    void setStartValue(int start)
    {
        memory = start;
    }

    int calculate(int right, char op)
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

    int calculate(int left, int right, char op)
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
    int memory = 0;
};

int main()
{
    Calculator calc1;

    calc1.setStartValue(10);

    cout << calc1.calculate(5, '+') << endl;
    cout << calc1.calculate(2, '*') << endl;
    cout << calc1.calculate(8, '-') << endl;
    cout << calc1.calculate(2, '/') << endl;

    cout << "---" << endl;

    Calculator calc2;

    cout << calc2.calculate(50, 5, '/') << endl;

    return 0;
}