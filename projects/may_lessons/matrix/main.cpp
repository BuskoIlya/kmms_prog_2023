#include <chrono>
#include <cstddef>
#include <iostream>

void multiply_matrix_as_in_math(
	int** a,
	std::size_t l,
	std::size_t m,
	int** b,
	std::size_t n,
	int** c
);

void multiply_matrix_for_cache(
	int** a,
	std::size_t l,
	std::size_t m,
	int** b,
	std::size_t n,
	int** c
);

int main() {
	const std::size_t size = 7000;
	std::cout << "Объём данных = " << size << std::endl;
	
	int** matrix_a = new int*[size];
	for (std::size_t i = 0; i < size; i++) {
		matrix_a[i] = new int[size];
	}
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            matrix_a[i][j] = i * j + j;
        }
    }
	
	int** matrix_b = new int*[size];
	for (std::size_t i = 0; i < size; i++) {
		matrix_b[i] = new int[size];
	}
    for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            matrix_b[i][j] = i * j + j;
        }
    }
	
	int** matrix_c = new int*[size];
	for (std::size_t i = 0; i < size; i++) {
		matrix_c[i] = new int[size];
	}
	
	auto start{std::chrono::steady_clock::now()};
	
	for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            matrix_c[i][j] = 0;
        }
    }
	multiply_matrix_as_in_math(matrix_a, size, size, matrix_b, size, matrix_c);
	
	auto end{std::chrono::steady_clock::now()};
	std::chrono::duration<double> elapsed_seconds{end - start};
	std::cout 
		<< "Время умножения матриц как в математике = " 
		<< elapsed_seconds.count() 
		<< " секунд." 
		<< std::endl;
	
	
	start = std::chrono::steady_clock::now();
	
	for (std::size_t i = 0; i < size; i++) {
        for (std::size_t j = 0; j < size; j++) {
            matrix_c[i][j] = 0;
        }
    }
	multiply_matrix_for_cache(matrix_a, size, size, matrix_b, size, matrix_c);
	
	end = std::chrono::steady_clock::now();
	elapsed_seconds = end - start;
	std::cout 
		<< "Время умножения матриц для кэша = " 
		<< elapsed_seconds.count() 
		<< " секунд." 
		<< std::endl;
	
	return 0;
}

void multiply_matrix_as_in_math(
	int** a,
	std::size_t l,
	std::size_t m,
	int** b,
	std::size_t n,
	int** c
) {
    for (std::size_t i = 0; i < l; i++) {
        for (std::size_t j = 0; j < n; j++) {
			int cij = 0;
            for (std::size_t k = 0; k < m; k++) {
                cij += a[i][k] * b[k][j];
			}
            c[i][j] = cij;
        }
	}
}

void multiply_matrix_for_cache(
	int** a,
	std::size_t l,
	std::size_t m,
	int** b,
	std::size_t n,
	int** c
) {
    for (std::size_t i = 0; i < l; i++) {
        for (std::size_t k = 0; k < m; k++) {
            int aik = a[i][k];
            for (std::size_t j = 0; j < n; j++) {
                c[i][j] += aik * b[k][j];
			}
        }
	}
}
