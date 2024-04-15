#include "long_addition_item.hpp"

namespace IBusko {
	LongAdditionItem::LongAdditionItem(
		const char* const title, 
		const MenuItem* parent
	) : MenuItem(title, parent) {}
		
	const MenuItem* LongAdditionItem::execute() const {
		// TODO
		return parent->get_parent();
	}
}
