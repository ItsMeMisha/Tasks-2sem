#include "vector.hpp"

namespace myContainers {

    template <typename T>
    Vector<T>::Vector() {}

    template <typename T>
    Vector<T>::Vector(const std::size_t size, const T& value) : curSize(size), curCapacity(size), data(new (value, size) T) {}

    template <typename T>
    Vector<T>::Vector (const Vector<T>& other) : curSize(other.size()), curCapacity(other.capacity()) {

        if (curSize > 0) {

            data = new (other[0], curSize) T;
            for (int i = 1; i < curSize; ++i)
                data[i] = other[i];
        } 
    }

    template <typename T>
    Vector<T>::Vector (Vector<T>&& other) :  curSize(other.size()), curCapacity(other.capacity()), data(other.data) {

        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    
    template <typename T>
    Vector<T>::~Vector() {
        if (data != nullptr)
            delete[] data;
    }

    template <typename T>
    void Vector<T>::push_back (const T& value) {

    }
    
    template <typename T>
    void Vector<T>::push_back (T&& value) {

    }

    template <typename T>
    void Vector<T>::pop_back() {

    }

    template <typename T>
    std::size_t Vector<T>::size () {


    }

    template <typename T>
    std::size_t Vector<T>::capacity () {


    }

    template <typename T>
    T& Vector<T>::operator[] (std::size_t indx) {

    }

    template <typename T>
    const T& Vector<T>::operator[] (std::size_t indx) const {

    }

    template <typename T>
    void Vector<T>::enlargeCapacity () {

    }

    template <typename T>
    void Vector<T>::reduceCapacity () {

    }

    template <typename T>
    void checkSizeAndCapacity () {

    }

}
