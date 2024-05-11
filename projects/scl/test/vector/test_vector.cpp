#include <gtest/gtest.h>

#include "vector.hpp"

using IBusko::Vector;

TEST(default_constructor, size) {
	Vector<int> v;
	ASSERT_EQ(0, v.get_size());
}

TEST(push_back, full) {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	ASSERT_EQ(3, v.get_size());
	EXPECT_TRUE(v.has_item(1));
	EXPECT_FALSE(v.has_item(4));
}

TEST(insert, full) {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.insert(2, 4);
	ASSERT_EQ(4, v.get_size());
	EXPECT_TRUE(v.has_item(4));
}

TEST(remove_first, full) {
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	ASSERT_EQ(4, v.get_size());
	
	v.remove_first(3);
	ASSERT_EQ(3, v.get_size());
	EXPECT_TRUE(v.has_item(3));
	
	v.remove_first(3);
	ASSERT_EQ(2, v.get_size());
	EXPECT_FALSE(v.has_item(3));
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
