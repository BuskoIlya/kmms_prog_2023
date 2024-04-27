#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;
class FConstructor : public testing::Test {
public:
    DoublyLinkedList<int>
            a;
};


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}