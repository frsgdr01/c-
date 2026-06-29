#include <iostream>
#include <windows.h>

int calculate(char op, int first, int second) {
    if (op == '/') {
        if (!second) {
            std::cout << "You cannot divide by 0\n";
            return 0;
        }
        return first / second;
    }
    if (op == '+') return first + second;
    if (op == '-') return first - second;
    if (op == '*') return first * second;
    return 0;
}

float calculate(char op, float first, float second) {
    if (op == '/') {
        if (second == 0.0f) {
            std::cout << "You cannot divide by 0\n";
            return 0.0f;
        }
        return first / second;
    }
    if (op == '+') return first + second;
    if (op == '-') return first - second;
    if (op == '*') return first * second;
    return 0.0f;
}

int calculate(const char* op, const int* first, const int* second) {
    if (op && first && second) {
        return calculate(*op, *first, *second);
    }
    return 0;
}

int& processFirstBy(int& first, const int by, const char op) {
    first = calculate(op, first, by);
    return first;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int* firstPtr = new int;
    int* secondPtr = new int;
    char* opPtr = new char;

    std::cout << "Enter first number: ";
    std::cin >> *firstPtr;

    std::cout << "Enter op: ";
    std::cin >> *opPtr;

    std::cout << "Enter second number: ";
    std::cin >> *secondPtr;

    int result = calculate(opPtr, firstPtr, secondPtr);
    std::cout << "Result: " << result << "\n";

    delete firstPtr;
    delete secondPtr;
    delete opPtr;
    firstPtr = nullptr;
    secondPtr = nullptr;
    opPtr = nullptr;

    int f = 10;
    processFirstBy(f, 5, '+');

    return 0;
}