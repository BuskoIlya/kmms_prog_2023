#include "menu_items.hpp"

int main() {
	const IBusko::MenuItem* current = &IBusko::MAIN;
	do {
        current = current->execute();
    } while (true);

    return 0;
}
