/*****************************************************
*ʹ��copy��next_permutation�����㷨������ȡ���������
*����������֮ǰ���ѱ�Ԫ�ذ��������У�ʹ��sort�㷨
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