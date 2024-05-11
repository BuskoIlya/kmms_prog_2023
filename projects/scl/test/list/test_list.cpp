#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

using IBusko::DoublyLinkedList;

TEST(default_constructor, size) {
	DoublyLinkedList<int> l;
	ASSERT_EQ(0, l.get_size());
}

TEST(push_back, many) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	ASSERT_EQ(3, l.get_size());
	EXPECT_TRUE(l.has_item(1));
	EXPECT_FALSE(l.has_item(4));
}

TEST(remove_first, one) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	ASSERT_EQ(1, l.get_size());
	
	l.remove_first(1);
	ASSERT_EQ(0, l.get_size());
	EXPECT_FALSE(l.has_item(1));
}

TEST(remove_first, two_begin) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	ASSERT_EQ(2, l.get_size());
	
	l.remove_first(1);
	ASSERT_EQ(1, l.get_size());
	EXPECT_FALSE(l.has_item(1));
	EXPECT_TRUE(l.has_item(2));
	
	l.remove_first(2);
	ASSERT_EQ(0, l.get_size());
}

TEST(remove_first, two_end) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	ASSERT_EQ(2, l.get_size());
	
	l.remove_first(2);
	ASSERT_EQ(1, l.get_size());
	EXPECT_TRUE(l.has_item(1));
	EXPECT_FALSE(l.has_item(2));
	
	l.remove_first(1);
	ASSERT_EQ(0, l.get_size());
}

TEST(remove_first, many_any) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(3);
	ASSERT_EQ(4, l.get_size());
	
	l.remove_first(3);
	ASSERT_EQ(3, l.get_size());
	EXPECT_TRUE(l.has_item(3));
	
	l.remove_first(3);
	ASSERT_EQ(2, l.get_size());
	EXPECT_FALSE(l.has_item(3));
}

TEST(remove_first, three_from_begin_to_end) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	ASSERT_EQ(3, l.get_size());
	
	l.remove_first(1);
	ASSERT_EQ(2, l.get_size());
	
	l.remove_first(2);
	ASSERT_EQ(1, l.get_size());
	
	l.remove_first(3);
	ASSERT_EQ(0, l.get_size());
}

TEST(remove_first, three_from_end_to_begin) {
	DoublyLinkedList<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	ASSERT_EQ(3, l.get_size());
	
	l.remove_first(3);
	ASSERT_EQ(2, l.get_size());
	
	l.remove_first(2);
	ASSERT_EQ(1, l.get_size());
	
	l.remove_first(1);
	ASSERT_EQ(0, l.get_size());
}

int main(int argc, char **argl) {
	::testing::InitGoogleTest(&argc, argl);
	return RUN_ALL_TESTS();
}
