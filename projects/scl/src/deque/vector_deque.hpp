#pragma once

namespace IBusko {
	template<typename T>
	class VectorStack {
		private:
			T* arr;
			std::size_t capacity = 10;
			std::size_t size = 0;
		public:
			VectorStack() noexcept;
			VectorStack(const VectorStack&) = delete;
			VectorStack& operator = (const VectorStack&) = delete;
			~VectorStack() noexcept;
			
			bool empty() const noexcept;
			void pop_back() noexcept;
			void pop_front() noexcept;
			void push_back(const T& value) noexcept;
			void push_front(const T& value) noexcept;
			std::size_t get_size() const noexcept;
			T back() const noexcept;
			T front() const noexcept;
	};
}
