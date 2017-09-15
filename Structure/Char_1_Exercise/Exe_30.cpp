/*****************************************************
*使用copy和next_permutation两个算法进行求取数组的排列
*在生成排列之前，把表元素按升序排列，使用sort算法
*****************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
template <typename T>
void permutation(T list[], int k, int m) {
	std::sort(list+k, list + m + 1);
	do {
		copy(list + k, list + m + 1, std::ostream_iterator<T>(std::cout, ""));
		std::cout << std::endl;
	} while (std::next_permutation(list + k, list + m + 1));
}

int main()
{
	char a[]{ 'b','c','a' };
	permutation(a, 0, sizeof(a)/sizeof(a[0])-1);
	return 0;
}