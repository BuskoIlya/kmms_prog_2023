#include "logger.hpp"
#include "long_number_exception.hpp"
#include "menu_items.hpp"

int main() {
	IBusko::Logger& logger = IBusko::Logger::get_instance();
	try {
		const IBusko::MenuItem* current = &IBusko::MAIN;
		do {
			current = current->execute();
		} while (true);
		
	} catch (const IBusko::LongNumberException& e) {
		logger.log(e.get_message().c_str());
		std::cout << e.get_message() << std::endl;
	}

    return 0;
}
