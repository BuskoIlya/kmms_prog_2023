#include <gtest/gtest.h>

#include "text.hpp"

using IBusko::Text;

TEST(str_constructor, lenght) {
	Text x = "Здравствуй, мир!";
	ASSERT_EQ(29, x.get_length()) << "Длина 'Здравствуй, мир!' равна 16";
}

class FConstructor : public testing::Test {
	public:
};

TEST_F(FConstructor, str_positive) {
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
