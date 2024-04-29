#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

TEST(initialize_list, first){
    DoublyLinkedList<int> a;

    ASSERT_EQ(a.size(), 0)
        << "Не инициализировался";
}

TEST(push_back, test){
    DoublyLinkedList<int> a;

    ASSERT_EQ(a.size(), 0)
        << "Неверный размер";

    a.push_back(1);

    ASSERT_EQ(a.size(), 1)
        << "Неверный размер";

    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    ASSERT_EQ(a.size(), 4)
        << "Неверный размер";
}
TEST(remove_first, test){
    DoublyLinkedList<int> a;

    a.push_back(1);
    a.push_back(2);

    ASSERT_EQ(a.remove_first(2), true)
        << "Ошибка удаления существующего элемента";
    ASSERT_EQ(a.remove_first(-1), false)
        << "Ошибка удаления несуществующего элемента";
    a.remove_first(1);
    ASSERT_EQ(a.size(), 0)
        << "Ошибка удаления последнего элемента";
};

TEST(has_item, test){
    DoublyLinkedList<int> a;

    a.push_back(1);
    a.push_back(2);

    ASSERT_EQ(a.has_item(2), true)
        << "Ошибка нахождения существующего элемента";
    ASSERT_EQ(a.has_item(-1), false)
        << "Ошибка нахождения несуществующего элемента";
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

