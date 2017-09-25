#ifndef BAO_ALGORITHM_H
#define BAO_ALGORITHM_H
#include <iostream>
#include <algorithm>
#include <string>
namespace Bao {
	class illegalParameterValue {
	private:
		std::string message;
	public:
		illegalParameterValue() :message{ "Illegal parameter value." } {}
		illegalParameterValue(char* theMessgae) :message{ theMessgae } {}
		void outputMessage() { std::cout << message << std::endl; }
	};

	//寻找数组a[0,n-1]的最大元素位置
	template <typename T>
	int indexOfMax(T a[], int n) {
		if (n <= 0) throw illegalParameterValue("n must be > 0");
		int indexOfMax = 0;
		for (int i{ 1 }; i < n; ++i) {
			if (a[indexOfMax] < a[i])
				indexOfMax = i;
		}
		return indexOfMax;
	}
	//顺序查找，在数组中从左至右查找第一个与x相等的元素，如果找到
	//就返回第一次出现的位置，否则返回-1
	template <typename T>
	int sequentialSearch(T a[], int n, const T& x) {
		int i{};
		for (; i < n&&a[i] != x; ++i);
		if (i == n) return -1;
		else return i;
	}
	//顺序查找的递归算法,在数组中从左至右查找第一个与x相等的元素，如果找到
	//就返回第一次出现的位置，否则返回-1
	template <typename T>
	int rSequentialSearch(T a[], int n, const T& x) {
		if (n < 1) return -1;
		if (a[n - 1] == x) return n - 1;
		return rSequentialSearch(a, n - 1, x);	
	}
	//多项式计算，多项式P(x) = cn*x^n+...ci*x^i+...c0*x^0
	//计算n阶多项式在x点的值，系数为coeff[0:n]
	template <typename T>
	T polyEval(T coeff[], int n, const T& x) {
		T y = 1;
		T value = coeff[0];
		for (int i{ 1 }; i <= n; ++i) {
			y *= x;
			value += y*coeff[i];
		}
		return value;
	}
	//利用Horner法则进行多项式计算，P(x) = (...(cn*x+c(n-1))*x+c(n-2))...)x + c0;
	template <typename T>
	T horner(T coeff[], int n, const T& x) {
		T value = coeff[n];
		for (int i{ 1 }; i <= n; ++i) {
			value = value*x + coeff[n - i];
		}
		return value;
	}
	//名次计算。一个元素在一个序列中的名次(rank)是所有比他小的元素个数加上在他
	//左边出现的与他相同元素的个数
	template <typename T>
	void rank(T a[], int n, int r[]) {
		//给a[]数组的n个元素排名次
		//在r[]中返回
		for (int i{}; i < n; ++i) {
			r[i] = 0;
		}
		for (int i{ 1 }; i < n; ++i) {
			for (int j{}; j < i; ++j) {
				if (a[j] <= a[i]) ++r[i];
				else ++r[j];
			}
		}
	}
	//使用附加数组进行排序，利用rank函数
	template <typename T>
	void rearrange(T a[],int n, T r[]) {
		rank(a, n, r);
		T* u = new T[n];
		//将a的元素移动到u中的符合对应名次的位置
		for (int i = 0; i < n; ++i) {
			u[r[i]] = a[i];
			
		}
		//将u中元素移动至a中
		for (int i{}; i < n; ++i)
			a[i] = u[i];
		delete[] u;
	}
	//选择排序法 将数组中最大的数移动至最后，将第二大的移动至次后一位如此往复
	template <typename T>
	void selectSort(T a[], int n) {
		bool sorted = false;
		for (int i = n; i > 1 && !sorted; --i) {
			int indexOfMax = 0;
			sorted = true;
			for (int j = 1; j < i; j++)
				if (a[indexOfMax] <= a[j]) indexOfMax = j;
				else sorted = false;
			std::swap(a[i-1], a[indexOfMax]);
		}
	}
	//一次冒泡过程
	template <typename T>
	void bubble(T a[], int n) {
		for (int i{1}; i < n; ++i) {
			if (a[i - 1] > a[i])
				std::swap(a[i - 1],a[i]);
		}
	}
	//冒泡排序
	template <typename T>
	void bubbleSort(T a[], int n) {
		for (int i{ n }; i > 1; --i) {
			bubble(a, i);
		}
	}
	//在有序数组中插入一个数，数组还是有序的
	template <typename T>
	void insert(T a[], int n, const T value) {
		int i;
		for (i=n - 1; i >= 0 && value < a[i]; --i) {
			a[i + 1] = a[i];
		}
		a[i + 1] = value;
	}
	//原地重排数组元素,思路：
	//如果r[i]!= i,让a[i]和a[r[i]]互换，同时让r[i]和r[r[i]]进行互换，直到r[i] = i;
	template <typename T>
	void rearrangeArray(T a[], int n, T r[]) {
		for (int i{}; i < n; ++i) {
			while (r[i] != i) {
				int t = r[i];
				std::swap(a[i], a[t]);
				std::swap(r[i], r[t]);
			}
		}
	}
}
#endif