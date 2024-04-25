#pragma once

#include "menu_item.hpp"

namespace IBusko {
	class SchoolAdditionItem : public MenuItem {
		public:
			SchoolAdditionItem(const char* const title, const MenuItem* parent);
			const MenuItem* execute() const;
	};
}
