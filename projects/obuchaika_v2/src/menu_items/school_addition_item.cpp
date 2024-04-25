#include <iostream>
#include <random>

#include "school_addition_item.hpp"

namespace {
	int MIN_NUMBER = 5;
	int MAX_NUMBER = 99;

	std::random_device rd;
	std::mt19937 gen(rd());
}

namespace IBusko {
	SchoolAdditionItem::SchoolAdditionItem(
		const char* const title,
		const MenuItem* parent
	) : MenuItem(title, parent) {}

	const MenuItem* SchoolAdditionItem::execute() const {
		int first_value = MIN_NUMBER + (gen() % (MAX_NUMBER-MIN_NUMBER+1));
		int second_value = MIN_NUMBER + (gen() % (MAX_NUMBER-MIN_NUMBER+1));
		int result_value = first_value + second_value;

		bool answer_is_true;
		int user_input;
		do {
			std::cout << "0 - Назад" << std::endl;
			std::cout << first_value << " + " << second_value << " = ";

			std::cin >> user_input;
			answer_is_true = (user_input == result_value);

			if (user_input == 0) {
				std::cout << std::endl;
				return parent;
			}

			std::cout << ((answer_is_true) ? "Верно" : "Неверно") << std::endl << std::endl;
		} while (!answer_is_true);
		return this;
	}
}
