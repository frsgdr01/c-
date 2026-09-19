#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iterator>

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
    class Iterator {
    private:
        T* ptr_;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        Iterator(T* ptr = nullptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++ptr_;
            return temp;
        }

        Iterator& operator--() {
            --ptr_;
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            --ptr_;
            return temp;
        }

        Iterator& operator+=(difference_type n) {
            ptr_ += n;
            return *this;
        }

        Iterator& operator-=(difference_type n) {
            ptr_ -= n;
            return *this;
        }

        Iterator operator+(difference_type n) const {
            return Iterator(ptr_ + n);
        }

        Iterator operator-(difference_type n) const {
            return Iterator(ptr_ - n);
        }

        difference_type operator-(const Iterator& other) const {
            return ptr_ - other.ptr_;
        }

        reference operator[](difference_type n) const {
            return ptr_[n];
        }

        bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) const { return ptr_ != other.ptr_; }
        bool operator<(const Iterator& other) const  { return ptr_ < other.ptr_; }
        bool operator>(const Iterator& other) const  { return ptr_ > other.ptr_; }
        bool operator<=(const Iterator& other) const { return ptr_ <= other.ptr_; }
        bool operator>=(const Iterator& other) const { return ptr_ >= other.ptr_; }
    };

    class ConstIterator {
    private:
        const T* ptr_;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = const T*;
        using reference         = const T&;

        ConstIterator(const T* ptr = nullptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() const { return ptr_; }

        ConstIterator& operator++() {
            ++ptr_;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++ptr_;
            return temp;
        }

        ConstIterator& operator--() {
            --ptr_;
            return *this;
        }

        ConstIterator operator--(int) {
            ConstIterator temp = *this;
            --ptr_;
            return temp;
        }

        ConstIterator& operator+=(difference_type n) {
            ptr_ += n;
            return *this;
        }

        ConstIterator& operator-=(difference_type n) {
            ptr_ -= n;
            return *this;
        }

        ConstIterator operator+(difference_type n) const {
            return ConstIterator(ptr_ + n);
        }

        ConstIterator operator-(difference_type n) const {
            return ConstIterator(ptr_ - n);
        }

        difference_type operator-(const ConstIterator& other) const {
            return ptr_ - other.ptr_;
        }

        reference operator[](difference_type n) const {
            return ptr_[n];
        }

        bool operator==(const ConstIterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const ConstIterator& other) const { return ptr_ != other.ptr_; }
        bool operator<(const ConstIterator& other) const  { return ptr_ < other.ptr_; }
        bool operator>(const ConstIterator& other) const  { return ptr_ > other.ptr_; }
        bool operator<=(const ConstIterator& other) const { return ptr_ <= other.ptr_; }
        bool operator>=(const ConstIterator& other) const { return ptr_ >= other.ptr_; }
    };

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

    Iterator begin() { return Iterator(data_); }
    Iterator end()   { return Iterator(data_ + size_); }

    ConstIterator begin() const { return ConstIterator(data_); }
    ConstIterator end()   const { return ConstIterator(data_ + size_); }

    ConstIterator cbegin() const { return ConstIterator(data_); }
    ConstIterator cend()   const { return ConstIterator(data_ + size_); }

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

    friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vector) {
        out << "[ ";
        for (size_t i = 0; i < vector.size_; ++i) {
            out << vector.data_[i] << (i + 1 < vector.size_ ? ", " : " ");
        }
        out << "]";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector<T>& vector) {
        T value;
        if (in >> value) {
            vector.push_back(value);
        }
        return in;
    }
};

template <typename T>
void insertion_sort(Vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        T value = arr[i];
        int j = static_cast<int>(i) - 1;

        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}

#endif