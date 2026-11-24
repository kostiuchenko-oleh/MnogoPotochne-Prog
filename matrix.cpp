#include <iostream>
#include <vector>

// Вивід матриці 4x4

void printMatrix(const std::vector<int>& mat) {
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			std::cout << mat[row * 4 + col] << "\t";
		}
		std::cout << "\n";
	}
}

std::vector<int> transpose(const std::vector<int>& mat) {
	std::vector<int> mat_T(4 * 4);
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			mat_T[col * 4 + row] = mat[row * 4 + col];
		}
	}

	return mat_T;
}


int main() {
	std::vector<int> mat(4 * 4);

	int value = 1;
	for (int row = 0; row < 4; ++row) {
		for (int col = 0; col < 4; ++col) {
			mat[row * 4 + col] = value++;
		}
	}

	std::cout << "4x4 Matrix:" << std::endl;
	printMatrix(mat);

	std::cout << "4x4 Transposed Matrix:" << std::endl;
	printMatrix(transpose(mat));
}
