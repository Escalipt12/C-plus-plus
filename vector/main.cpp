#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>

void mult(std::vector<int>& v, int factor) {
	for (int& i : v) {
		i *= factor;
	}
}

int sum(const std::vector<int>& v) {
	int total = 0;

	for (auto a = v.begin(); a != v.end(); a++)
	{
		total += *a;
	}

	return total;
}

void remove_negatives(std::vector<int>& v) {
	for (auto a = v.begin(); a != v.end();)
	{
		if (*a < 0) {
			a = v.erase(a);
		}
		else {
			a++;
		}
	}
}

/*

	int n;
	std::cout << "Сколько чисел? ";
	std::cin >> n;

	std::vector<int> v(n);
	std::cout << "Введите " << n << " целых чисел, разделённых пробелами:\n";
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}

	std::cout << "Вы ввели:\n";
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << "\n";
*/

void main() {
	std::vector<int> numbers;
	
	int test = 0;
	std::cin >> test;

	numbers.push_back(test);

	mult(numbers, 5);
	std::cout << sum(numbers) << std::endl;

	remove_negatives(numbers);
	for (auto t : numbers) {
		std::cout << t << std::endl;
	}


	getchar();
}
