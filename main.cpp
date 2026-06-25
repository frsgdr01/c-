#include <iostream>
#include <windows.h>

int calculate(int first, int second, char op) {
    int result = 0;
    if (op == '+') {
        result = first + second;
    } else if (op == '-') {
        result = first - second;
    } else if (op == '*') {
        result = first * second;
    } else if (op == '/') {
        if (second != 0) {
            result = first / second;
        } else {
            std::cout << "Помилка: ділення на нуль!\n";
        }
    }
    return result;
}

float calculate(float first, float second, char op) {
    float result = 0.0f;
    if (op == '+') {
        result = first + second;
    } else if (op == '-') {
        result = first - second;
    } else if (op == '*') {
        result = first * second;
    } else if (op == '/') {
        if (second != 0.0f) {
            result = first / second;
        } else {
            std::cout << "Помилка: ділення на нуль!\n";
        }
    }
    return result;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int num1 = 0;
    int num2 = 0;
    char op = 0;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the operation (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int userResult = calculate(num1, num2, op);
    std::cout << "Result: " << userResult << "\n\n";

    std::cout << "--- Перевірка перевантаження функцій (Hardcoded) ---\n";
    
    float resFloat = calculate(1.2f, 3.4f, '+');
    std::cout << "calculate(1.2f, 3.4f, '+') = " << resFloat << "\n";

    int resInt = calculate(1, 2, '/');
    std::cout << "calculate(1, 2, '/') = " << resInt << "\n";

    return 0;
}