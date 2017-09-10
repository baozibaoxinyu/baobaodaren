#include <iostream>

template <class T>
size_t count(T a[], size_t n, T value) {
	size_t counter{};
	if (n < 1) {
		throw "n < 1,can't get value";
	}
	for (size_t i{}; i < n; ++i) {
		if (a[i] == value) {
			++counter;
		}
	}
	return counter;
}

int main()
{
	try {
		int a[10] = { 1,2,2,2,2,2,2,3,4,4 };
		int value = 2;
		std::cout << count(a, 0, value) << std::endl;
		return 0;
	}
	catch (char* e) {
		std::cout << e << std::endl;
	}
}