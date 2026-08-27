#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t N>
class StaticArray {
private:
    T data_[N]{};

public:
    StaticArray() = default;

    StaticArray(std::initializer_list<T> list) {
        size_t index = 0;
        for (const auto& item : list) {
            if (index < N) {
                data_[index++] = item;
            }
        }
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    T& at(size_t index) {
        if (index >= N) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= N) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    constexpr size_t size() const { return N; }

    bool operator==(const StaticArray& other) const {
        for (size_t i = 0; i < N; ++i) {
            if (data_[i] != other.data_[i]) return false;
        }
        return true;
    }

    bool operator!=(const StaticArray& other) const {
        return !(*this == other);
    }
};

#endif