#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class Vector {
private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void resize_capacity(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data_[i]);
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {}

    explicit Vector(size_t initial_size) 
        : size_(initial_size), capacity_(initial_size) {
        data_ = (capacity_ > 0) ? new T[capacity_]() : nullptr;
    }

    ~Vector() {
        delete[] data_;
    }

    Vector(const Vector& other) : size_(other.size_), capacity_(other.capacity_) {
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        } else {
            data_ = nullptr;
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            T* new_data = (other.capacity_ > 0) ? new T[other.capacity_] : nullptr;
            for (size_t i = 0; i < other.size_; ++i) {
                new_data[i] = other.data_[i];
            }
            delete[] data_;
            data_ = new_data;
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size_ >= capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            resize_capacity(new_capacity);
        }
        data_[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0) {
            throw std::underflow_error("Vector is empty!");
        }
        --size_;
    }

    T& operator[](size_t index) {
        return data_[index];
    }

    const T& operator[](size_t index) const {
        return data_[index];
    }

    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range!");
        }
        return data_[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }

    bool operator==(const Vector& other) const {
        if (size_ != other.size_) return false;
        for (size_t i = 0; i < size_; ++i) {
            if (data_[i] != other.data_[i]) return false;
        }
        return true;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
};

#endif