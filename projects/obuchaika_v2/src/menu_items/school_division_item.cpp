#include "school_division_item.hpp"

namespace IBusko {
    SchoolDevisionItem::SchoolDevisionItem(
            const char* const title,
            const MenuItem* parent
    ) : MenuItem(title, parent) {}

    const MenuItem* SchoolDevisionItem::execute() const {
    // TODO : add code
        return parent->get_parent();
    }
}
