#include <iostream>
#include <string>
#include "Vector.hpp"

int main() {
    Vector<int> numbers;
    numbers.push_back(42);
    numbers.push_back(15);
    numbers.push_back(8);
    numbers.push_back(23);
    numbers.push_back(4);

    std::cout << "Before sort: " << numbers << std::endl;
    insertion_sort(numbers);
    std::cout << "After sort:  " << numbers << std::endl;

    return 0;
}