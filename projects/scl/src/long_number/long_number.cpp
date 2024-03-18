#include "long_number.hpp"

using IBusko::LongNumber;

LongNumber::LongNumber() : length(1), sign(POSITIVE) {
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	length = 0;
	delete [] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;
	
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
	
	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	return false;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return false;
}

bool LongNumber::operator > (const LongNumber& x) const {
	return false;
}

bool LongNumber::operator < (const LongNumber& x) const {
	return false;
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	return LongNumber();
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	return LongNumber();
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	return LongNumber();
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	return LongNumber();
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	return LongNumber();
}

int LongNumber::get_digits_number() const {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	// TODO OutOfBoundException
	return numbers[rank - 1];
}

bool LongNumber::is_negative() const {
	return sign == NEGATIVE;
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const {
	if (!str) return 0;
	
	int length = 0;
	while (str[length] != END) {
		length++;
	}
	
	/* Или вариант через указатель
	while (*str) {
		str++;
		length++;
	}
	*/	
	
	return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace IBusko {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == LongNumber::NEGATIVE) {
			os << LongNumber::MINUS;
		}
		for (int i = 0; i < x.length; i++) {
			os << x.numbers[x.length - i - 1];
		}
		return os;
	}
}
