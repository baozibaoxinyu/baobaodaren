/*
C++�ݹ麯��
1-3 ����(permutation)
���⣺��n����ͬԪ�ص���������ȷ��һ��������У�n��Ԫ�ص����и���Ϊn!
Ԫ�ؼ��ϣ�E{e1,e2,e3,...en},�����е��������
��Ei��ʾȥ��E�е�i��Ԫ��ei�����򼯺�,perm(X)�Ǽ���X������Ԫ�ص����м���
��ei.perm(X)��ʾ��perm(X)�е�ÿ�����м���ǰ׺ei֮������б�

��������������֣�
1���������֣�n = 1,��ʱEֻ��һ��Ԫ��e��perm(E) = {e};
2���ݹ鲿�֣�n > 1,��ʱ��perm(E) = {e1.perm(E1),e2.perm(E2),...,en.perm(En)};


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