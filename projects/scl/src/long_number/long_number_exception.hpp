#pragma once

#include <string>

namespace IBusko {
	class LongNumberException {
		private:
			std::string exception;
		public:
			LongNumberException(const std::string exception) : exception(exception) {}
			std::string get_message() const { return exception; }
	};
}
