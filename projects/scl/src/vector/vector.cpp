#include "vector.hpp"

#include <iostream>
#include <stdexcept>

using IBusko::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 10;

template<typename T>
Vector<T>::Vector() {
	arr = new T[START_CAPACITY];
}

template<typename T>
Vector<T>::~Vector() {
	delete[] arr;
	arr = nullptr;
	capacity = START_CAPACITY;
	size = 0;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return true;
		}
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size) {
		return false;
	}
	
	if (size == capacity) {
		capacity *= 2;
		T* copy = new T[capacity];
		for (std::size_t i = 0; i < position; ++i) {
			copy[i] = arr[i];
		}
		copy[position] = value;
		for (std::size_t i = position; i < size; i++) {
			copy[i + 1] = arr[i];
		}
		delete[] arr;
		arr = copy;
	} else {
		for (std::size_t i = size; i > position; i--) {
			arr[i] = arr[i - 1];
		}
		arr[position] = value;
	}
	
	size++;
	
	return true;
}

template<typename T>
void Vector<T>::print() const noexcept {
	const char space = ' ';
	for (std::size_t i = 0; i < size; i++) {
		std::cout << arr[i] << space;
	}
	std::cout << std::endl;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size == capacity) {
		capacity *= 2;
		T* copy = new T[capacity];
		for (std::size_t i = 0; i < size; i++) {
			copy[i] = arr[i];
		}
		delete[] arr;
		arr = copy;
	}
	arr[size++] = value;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	std::size_t possible_capacity = 2 * size;
    if (capacity > possible_capacity) {
        capacity = 
			possible_capacity > 2 * START_CAPACITY 
			? possible_capacity : START_CAPACITY;
        T* copy = new T[capacity];
        for (std::size_t i = 0; i < size; i++) {
            copy[i] = arr[i];
        }
        delete arr;
		arr = copy;
	}
	
	for (std::size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			for (std::size_t j = i; j < size - 1; j++) {
				arr[j] = arr[j + 1];
			}
			size--;
			return true;
		}
	}
	
	return false;
}
