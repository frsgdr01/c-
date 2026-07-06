#include <iostream>

using namespace std;

int memory = 0;

void setStartValue(int value)
{
    memory = value;
}

int calculate(char operation, int value)
{
    switch (operation)
    {
        case '+':
            memory += value;
            break;
        case '-':
            memory -= value;
            break;
        case '*':
            memory *= value;
            break;
        case '/':
            if (value != 0)
            {
                memory /= value;
            }
            break;
        default:
            break;
    }
    return memory;
}

int main()
{
    setStartValue(10);

    cout << calculate('+', 5) << endl;
    cout << calculate('*', 2) << endl;
    cout << calculate('-', 8) << endl;
    cout << calculate('/', 2) << endl;

    return 0;
}