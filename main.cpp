#include <iostream>
#include <string>
#include <algorithm>
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

    std::cout << "\nRange-based for loop: ";
    for (const auto& val : numbers) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    Vector<std::string> words;
    words.push_back("banana");
    words.push_back("apple");
    words.push_back("cherry");

    std::cout << "\nWords before std::sort: " << words << std::endl;
    std::sort(words.begin(), words.end());
    std::cout << "Words after std::sort:  " << words << std::endl;

    std::cout << "\nExplicit Iterator: ";
    for (Vector<int>::Iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}