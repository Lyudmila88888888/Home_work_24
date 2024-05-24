#include <iostream>
#include <cstdlib>
#include <ctime>


template <typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;

}

template <typename T>
void print_arr(T arr[], const int lenght) {
	std::cout << "{ ";
	for (int i = 0; i < lenght; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

void resize_arr(int*& arr, int length, int new_length) { //Задача 2.
	
	 int* new_arr = new int[new_length];

	 int min(length < new_length ? length : new_length);
	 int length_copy = min;

	for (int i = 0; i < length_copy; i++) {
		new_arr[i] = arr[i];
	}

	for (int i = length_copy; i < new_length; i++) {
		new_arr[i] = 0; 
	}

	delete[] arr;
	arr = new_arr;
}



int main() {
	setlocale(LC_ALL, "Russian");

	// Задача 1.
	int n, m;
	std::cout << " Задача 1. \n Введите размер массива № 1 - > ";
	std::cin >> n;
	std::cout << " Введите размер массива № 2 - > ";
	std::cin >> m;
	int* A = new int[n];
	int* B = new int[m];
	fill_arr(A, n, 20, 31);
	fill_arr(B, m, 30, 41);

	std::cout << " Массив A: \n";
	print_arr(A, n);
	std::cout << " Массив B: \n";
	print_arr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];

	std::cout << "Массив C:\n";
	print_arr(C, n + m);
	delete[] A;
	delete[] B;
	

	// Задача 2. Увелечение размера массива

	int size1 = 6;
	int* arr1 = new int[size1];
	fill_arr(arr1, size1, 10, 21);
	std::cout << " Изначальный массив: \n";
	print_arr(arr1, size1);

	int size2;
	std::cout << " Введите длину нового массива - > ";
	std::cin >> size2;

	resize_arr(arr1, size1, size2);
	std::cout << " Итоговый массив:\n";
	for (int i = 0; i < size2; i++) {
		std::cout << arr1[i] << ", ";
		std::cout << "\b\b ";
	}
	std::cout << std::endl;

	delete[] arr1;
	
	return 0;
}



