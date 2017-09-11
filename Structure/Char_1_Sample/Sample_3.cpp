/*
C++递归函数
1-3 排列(permutation)
问题：从n个不同元素的所有排列确定一个最佳排列，n个元素的排列个数为n!
元素集合：E{e1,e2,e3,...en},求所有的排列情况
令Ei表示去掉E中第i个元素ei的排序集合,perm(X)是集合X的所有元素的排列集合
令ei.perm(X)表示在perm(X)中的每个排列加上前缀ei之后的排列表

这个排列有两部分：
1，基础部分，n = 1,此时E只有一个元素e，perm(E) = {e};
2，递归部分，n > 1,此时的perm(E) = {e1.perm(E1),e2.perm(E2),...,en.perm(En)};


*/
#include <iostream>
#include <iterator>
#include <algorithm>
template <typename T>
void permutation(T list[], int k, int m) {
	if (k == m) {
		copy(list, list + m + 1,
			std::ostream_iterator<T>(std::cout, ""));
		std::cout << std::endl;
	}
	else 
		for (int i = k; i <= m; ++i) {
			std::swap(list[k], list[i]);
			permutation(list, k + 1, m);
			std::swap(list[k], list[i]);
		}
}

int main()
{
	char list[]{ 'a','b','c' };
	permutation(list, 0, 2);
	int num[]{ 1,2,3 };
	permutation(num, 0, 2);
	return 0;

}