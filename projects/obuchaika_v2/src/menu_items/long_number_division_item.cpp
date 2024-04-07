#include "long_number_division_item.hpp"

#include <cstdlib>
#include <ctime>

#include "long_number.hpp"

namespace IBusko {
	LongNumberDivisionItem::LongNumberDivisionItem(const char* const title, const MenuItem* parent)
		: MenuItem(title, parent) {}
		
	const MenuItem* LongNumberDivisionItem::execute() const {
		std::srand(time(NULL));
		
		LongNumber x = "1234567890";
		LongNumber y = "0";
		x / y;
		
		return parent->get_parent();
	}
}
