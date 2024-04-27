#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() noexcept {

};
template <typename T>
void DoublyLinkedList<T>::push_back(const T &value) noexcept {
    Node* ptr = new Node(value);
    ptr->prev = end;

    if(end != nullptr){
        end->next = ptr;
    }
    if(begin == nullptr){
        begin = ptr;
    }
    end = ptr;
};

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {
    Node* i = begin;

    for(; i != nullptr; i=i->next){
        std::cout << i->value << " ";
    }
    std::cout << "\n";
};

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T &value) noexcept {
    Node* i = begin;

    for(; i != nullptr; i=i->next){
        if(i->value == value){
            if(begin == end){
                begin = nullptr;
                end = nullptr;
            }
            else if(i == begin){
                i->next->prev = nullptr;
                begin = i->next;
            }else if(i == end){
                i->prev->next = nullptr;
                end = i->prev;
            }else{
                if(i->prev != nullptr)
                    i->prev->next = i->next;
                if(i->next != nullptr)
                    i->next->prev = i->prev;
            }
            delete i;

            return true;
        }
    }
    return false;
};

template <typename T>
std::size_t DoublyLinkedList<T>::size() const noexcept {
    int len = 0;
    Node* i = begin;

    for(;i != nullptr; i = i->next){
        len++;
    }
    return len;
};

template <typename T>
bool DoublyLinkedList<T>::has_item(const T &value) const noexcept {
    Node* i = begin;

    for(;i != nullptr; i = i->next){
        if(i->value == value){
            return true;
        }
    }

    return false;
};