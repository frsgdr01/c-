#include <iostream>
#include <string>
#include "Vector.hpp"
#include "StaticArray.hpp"

int main() {
    Vector<int> int_vec;
    int_vec.push_back(10);
    int_vec.push_back(20);
    int_vec.push_back(30);

    for (size_t i = 0; i < int_vec.size(); ++i) {
        std::cout << int_vec[i] << " ";
    }
    std::cout << std::endl;

    Vector<double> double_vec;
    double_vec.push_back(3.14);
    double_vec.push_back(2.718);

    for (size_t i = 0; i < double_vec.size(); ++i) {
        std::cout << double_vec[i] << " ";
    }
    std::cout << std::endl;

    StaticArray<int, 5> arr_int = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < arr_int.size(); ++i) {
        std::cout << arr_int[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}