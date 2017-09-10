/************************************************************/
//	编写一个函数模板count 返回值是a[0:n-1]中value出现的次数  * 
/************************************************************/
#include <iostream>
template <typename T>
size_t count(const T a[],const T value, size_t number) {
	size_t counter{};
	for (size_t i{}; i < number; ++i) {
		if (a[i] == value) ++counter;
	}
	return counter;
}

int main()
{
	const int a[10] = { 1,2,3,3,4,3,3,3,4 };
	const int value = 3;
	std::cout << count(a, value, sizeof(a)/sizeof(a[0])) << std::endl;
	return 0;
}