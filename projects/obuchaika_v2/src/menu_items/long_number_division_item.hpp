#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class LongNumberDivisionItem : public MenuItem {
		public:
			LongNumberDivisionItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}
