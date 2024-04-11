#pragma once

#include <string>

namespace IBusko {
	class LongNumberException: public std::exception {
		private:
			std::string message;
		public:
			LongNumberException(const std::string& message) : message(message) {}
			const char* what() const noexcept override { return message.c_str(); }
	};
}
