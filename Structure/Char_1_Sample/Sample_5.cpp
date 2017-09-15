/*****************************************************
使用copy和next_permutation两个算法进行求取数组的排列
copy的STL函数定义如下：
template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter __first, _InputIter __last,
                        _OutputIter __result)
{
  return __copy(__first, __last, __result,
                __ITERATOR_CATEGORY(__first),
                __DISTANCE_TYPE(__first));
}

template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_InputIter __first, _InputIter __last,
_OutputIter __result,
input_iterator_tag, _Distance*)
{
	for ( ; __first != __last; ++__result, ++__first)
		*__result = *__first;
	return __result;
}
*****************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
template <typename T>
void permutation(T list[], int k, int m) {
	do {
		copy(list+k, list + m + 1, std::ostream_iterator<T>(std::cout, ""));
		std::cout << std::endl;
	} while (std::next_permutation(list+k, list + m + 1));
}

int main()
{
	char a[]{ 'b','a','c' ,'d' };
	permutation(a, 0, 3);
	return 0;
}