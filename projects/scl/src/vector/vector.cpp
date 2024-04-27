#include "vector.hpp"

using IBusko::Vector;

template <typename T>
Vector<T>::Vector() noexcept{
    arr = new T[this->capacity];
}

template <typename T>
Vector<T>::~Vector() noexcept{
    this->capacity = 0;
    this->size = 0;
    delete[] arr;
}

template <typename T>
void Vector<T>::push_back(const T& value) noexcept{
    if(this->get_size() + 2 >= this->capacity){
        increase_of_capacity();
    }
    arr[get_size()] = value;

    this->size += 1;
}

template <typename T>
bool Vector<T>::has_item(const T& value) const noexcept{
    for(int i = 0; i < this->get_size(); i++){
        if(arr[i] == value){
            return true;
        }
    }
    return false;
}

template <typename T>
bool Vector<T>::insert(const int position, const T& value){
    if(this->get_size() + 2 >= this->capacity){
        increase_of_capacity();
    }
    T* temp = new T[this->capacity];
    int ps = (position > this->get_size()) ? this->get_size() : position;

    for(std::size_t i = 0; i < ps; i++){
        temp[i] = arr[i];
    }
    temp[ps] = value;

    for(std::size_t i = ps + 1; i <= this->get_size(); i++){
        temp[i] = arr[i - 1];
    }
    delete[] arr;

    arr = temp;
    this->size += 1;

    return true;
}

template <typename T>
void Vector<T>::print() const noexcept{
    for(std::size_t i = 0; i < this->get_size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
std::size_t Vector<T>::get_size() const noexcept{
    return this->size;
}

template <typename T>
bool Vector<T>::remove_first(const T& value) noexcept{
    T* temp = new T[this->capacity];
    bool flag = false;
    std::size_t i = 0;

    for(;i < this->get_size(); i++){
        if(arr[i] == value){
            flag = true;
            break;
        }
        temp[i] = arr[i];
    }
    if(!flag){
        return flag;
    }

    for(i++; i < this->get_size(); i++){
        temp[i - 1] = arr[i];
    }

    delete[] arr;

    arr = temp;
    this->size -= 1;

    return flag;
}

template <typename T>
void Vector<T>::increase_of_capacity() noexcept {
    T* temp = new T[this->capacity + 10];

    for(std::size_t i = 0; i < this->get_size(); i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;

    this->capacity += 10;
}