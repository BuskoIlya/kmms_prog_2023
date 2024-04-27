#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() noexcept {

};
template <typename T>
void DoublyLinkedList<T>::push_back(const T &value) noexcept {};

template <typename T>
void DoublyLinkedList<T>::print() const noexcept {};

template <typename T>
bool DoublyLinkedList<T>::remove_first(const T &value) noexcept {};

template <typename T>
std::size_t DoublyLinkedList<T>::size() const noexcept {};

template <typename T>
bool DoublyLinkedList<T>::has_item(const T &value) const noexcept {};