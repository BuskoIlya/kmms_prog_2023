#include <iostream>
#include <random>
#include <string>

#include "long_subtraction_item.hpp"
#include "long_number.hpp"

namespace IBusko {
    const char END = '\0';
    const char ZERO = '0';

    const short MIN_LENGTH = 1;
    const short MAX_LENGTH = 18;

    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution<short> length_dist(MIN_LENGTH, MAX_LENGTH);

    LongNumber get_random_unsigned_long_number() {
        short length = length_dist(mt);
        char number[MAX_LENGTH + 1];
        if (length == 1) {
            number[0] = ZERO + mt() % 10;
        }
        else {
            number[0] = ZERO + 1 + mt() % 9;
            for (int i = 1; i < length; ++i) {
                number[i] = ZERO + mt() % 10;
            }
        }
        number[length] = END;

        return LongNumber(number);
    }

    LongSubtractionItem::LongSubtractionItem(const char* const title, const MenuItem* parent)
        : MenuItem(title, parent) {}

    const MenuItem* LongSubtractionItem::execute() const {
        LongNumber first_value = get_random_unsigned_long_number();
        LongNumber second_value = get_random_unsigned_long_number();
        LongNumber result_value = first_value - second_value;

        bool answer_is_true = false;
        std::string user_answer;

        std::cout << "q - Назад" << std::endl;
        std::cout << first_value << " - " << second_value << " = ";

        while (true) {
            std::getline(std::cin, user_answer);

            if (user_answer == "q") {
                std::cout << std::endl;
                return parent;
            }
            else if (user_answer.empty()) {
                continue;
            }

            answer_is_true = LongNumber(user_answer.c_str()) == result_value;

            if (answer_is_true) {
                std::cout << "Верно" << std::endl << std::endl;
                break;
            }
            else {
                std::cout << "Неверно" << std::endl << std::endl;
            }
        }

        return this;
    }
}
