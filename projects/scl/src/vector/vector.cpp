//
// Created by Andrei Sulimov on 10.05.2024.
//
#include "vector.hpp"
#include <cstddef>
#include <stdexcept>
#include <iostream>


template <typename T>
IBusko::Vector<T>::~Vector() noexcept{
	delete[] arr;
	capacity = 0;
	size = 0;
	arr = nullptr;
}


template <typename T>
void IBusko::Vector<T>::push_back(const T& value) noexcept {
    if (capacity == size) {
        resize(2 * capacity);
    }
    arr[size] = value;
    size++;
}

template <typename T>
bool IBusko::Vector<T>::has_item(const T& value) const noexcept {
    for (std::size_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false;
}

template <typename T>
bool IBusko::Vector<T>::insert(const int position, const T& value) {
    if (position > size || position < 0) {
        throw std::out_of_range("Position out of bounds");
    }

    if (capacity == size) {
        resize(2 * capacity);
    }

    shift_right(position);
    arr[position] = value;
    size++;
    return true;
}


template <typename T>
void IBusko::Vector<T>::print() const noexcept {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
}

template <typename T>
bool IBusko::Vector<T>::remove_first(const T& value) noexcept {
    for (std::size_t i = 0; i < size; i++) {
        if (arr[i] == value) {
            shift_left(i);
            size--;
            return true;
        }
    }
    return false;
}

template <typename T>
std::size_t IBusko::Vector<T>::get_size() const noexcept{
	return size;
}