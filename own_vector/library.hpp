#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <algorithm>
#include <cstddef>

//namespace template_library {

    template <typename T>
    class Vector {
    public:
        Vector()
            : data_(nullptr), size_(0), capacity_(0) {}

            explicit Vector(size_t count, const T& value = T())
            : data_(new T[count]), size_(count), capacity_(count)
        {
            std::fill(data_, data_ + size_, value);
        }

        Vector(std::initializer_list<T> init)
            : data_(new T[init.size()]), size_(init.size()), capacity_(init.size())
        {
            std::copy(init.begin(), init.end(), data_);
        }

        Vector(const Vector& other)
            : data_(new T[other.capacity_]), size_(other.size_), capacity_(other.capacity_)
        {
            std::copy(other.data_, other.data_ + other.size_, data_);
        }


        Vector& operator=(const Vector& other) {
            if (this != &other) {
                T* newData = new T[other.capacity_];
                std::copy(other.data_, other.data_ + other.size_, newData);

                delete[] data_;
                data_ = newData;
                size_ = other.size_;
                capacity_ = other.capacity_;
            }
            return *this;
        }


        ~Vector() {
            delete[] data_;
        }

        T& operator[](size_t index) {
            return data_[index];
        }

        const T& operator[](size_t index) const {
            return data_[index];
        }

        T& at(size_t index) {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        const T& at(size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        size_t size() const {
            return size_;
        }

        size_t capacity() const {
            return capacity_;
        }

        bool empty() const {
            return size_ == 0;
        }

        void resize(size_t newSize, const T& value = T()) {
            if (newSize > capacity_) {
                reserve(newSize);
            }
            if (newSize > size_) {
                std::fill(data_ + size_, data_ + newSize, value);
            }
            size_ = newSize;
        }

        void reserve(size_t newCapacity) {
            if (newCapacity > capacity_) {
                T* newData = new T[newCapacity];
                if (data_) {
                    std::copy(data_, data_ + size_, newData);
                    delete[] data_;
                }
                data_ = newData;
                capacity_ = newCapacity;
            }
        }

        void push_back(const T& value) {
            if (size_ == capacity_) {
                size_t newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
                reserve(newCapacity);
            }
            data_[size_] = value;
            size_++;
        }

        void pop_back() {
            if (size_ == 0) {
                throw std::out_of_range("Pop_back from an empty vector");
            }
            size_--;
        }

        void clear() {
            size_ = 0;
        }

    private:
        T* data_;
        size_t size_;
        size_t capacity_;
    };
//}

#endif 
