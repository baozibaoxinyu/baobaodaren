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

	//Ѱ������a[0,n-1]�����Ԫ��λ��
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
	//˳����ң��������д������Ҳ��ҵ�һ����x��ȵ�Ԫ�أ�����ҵ�
	//�ͷ��ص�һ�γ��ֵ�λ�ã����򷵻�-1
	template <typename T>
	int sequentialSearch(T a[], int n, const T& x) {
		int i{};
		for (; i < n&&a[i] != x; ++i);
		if (i == n) return -1;
		else return i;
	}
	//˳����ҵĵݹ��㷨,�������д������Ҳ��ҵ�һ����x��ȵ�Ԫ�أ�����ҵ�
	//�ͷ��ص�һ�γ��ֵ�λ�ã����򷵻�-1
	template <typename T>
	int rSequentialSearch(T a[], int n, const T& x) {
		if (n < 1) return -1;
		if (a[n - 1] == x) return n - 1;
		return rSequentialSearch(a, n - 1, x);	
	}
	//����ʽ���㣬����ʽP(x) = cn*x^n+...ci*x^i+...c0*x^0
	//����n�׶���ʽ��x���ֵ��ϵ��Ϊcoeff[0:n]
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
	//����Horner������ж���ʽ���㣬P(x) = (...(cn*x+c(n-1))*x+c(n-2))...)x + c0;
	template <typename T>
	T horner(T coeff[], int n, const T& x) {
		T value = coeff[n];
		for (int i{ 1 }; i <= n; ++i) {
			value = value*x + coeff[n - i];
		}
		return value;
	}
	//���μ��㡣һ��Ԫ����һ�������е�����(rank)�����б���С��Ԫ�ظ�����������
	//��߳��ֵ�������ͬԪ�صĸ���
	template <typename T>
	void rank(T a[], int n, int r[]) {
		//��a[]�����n��Ԫ��������
		//��r[]�з���
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
	//ʹ�ø������������������rank����
	template <typename T>
	void rearrange(T a[],int n, T r[]) {
		rank(a, n, r);
		T* u = new T[n];
		//��a��Ԫ���ƶ���u�еķ��϶�Ӧ���ε�λ��
		for (int i = 0; i < n; ++i) {
			u[r[i]] = a[i];
			
		}
		//��u��Ԫ���ƶ���a��
		for (int i{}; i < n; ++i)
			a[i] = u[i];
		delete[] u;
	}
	//ѡ������ ���������������ƶ�����󣬽��ڶ�����ƶ����κ�һλ�������
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
	//һ��ð�ݹ���
	template <typename T>
	bool bubble(T a[], int n) {
		bool swaped = false;	//Ŀǰ��δ����
		for (int i{1}; i < n; ++i) {
			if (a[i - 1] > a[i]) {
				std::swap(a[i - 1], a[i]);
				swaped = true;
			}
		}
		return swaped;
	}
	//ð������,���һ��ð������֮��swaped��״̬Ϊfalse��˵��û�н������������򣬿�����ǰ��ֹ����
	template <typename T>
	void bubbleSort(T a[], int n) {
		for (int i{ n }; i > 1 && bubble(a, i); --i);
	}
	//�����������в���һ���������黹�������
	template <typename T>
	void insert(T a[], int n, const T value) {
		int i;
		for (i=n - 1; i >= 0 && value < a[i]; --i) {
			a[i + 1] = a[i];
		}
		a[i + 1] = value;
	}
	//�����������������insert
	template <typename T>
	void insertSorted(T a[], int n) {
		for (int i{ 1 }; i < n; ++i)
			insert(a, i, a[i]);
	}
	//��һ�ֲ�������
	template <typename T>
	void insertionSort(T a[], int n) {
		for (int i{ 1 }; i < n; ++i) {
			T t = a[i];
			int j;
			for (j = i - 1; j >= 0 && t < a[j]; --j) {
				a[j + 1] = a[j];
			}
			a[j + 1] = t; 
		}
	}
	//ԭ����������Ԫ��,˼·��
	//���r[i]!= i,��a[i]��a[r[i]]������ͬʱ��r[i]��r[r[i]]���л�����ֱ��r[i] = i;
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
	//����ת��
	template <typename T>
	void transpose(T **a, int row) {
		for (int i{}; i < row; ++i) {
			for (int j = i + 1; j < row; ++j) {
				swap(a[i][j], a[j][i]);
			}
		}
	}
	//����ӷ�
	template <typename T>
	void matrixAdd(T **a, T **b, T **c, int numberOfRows, int numberOfColumns) {
		for (int i{}; i < numberOfRows; ++i) {
			for (int j{}; j < numberOfColumns; ++j) {
				c[i][j] = a[i][j] + b[i][j];
			}
		}
	}
	//N*N����ĳ˷�
	template <typename T>
	void squareMatrixMultiply(T** a, T** b, T** c,int n) {
		for (int i{}; i < n; ++i) {
			for (int j{}; j < n; ++j) {
				T sum = 0;
				for (int k{}; k < n; ++k) {
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum;
			}
		}
	}
	//M*N�����N*P����ĳ˷�
	template <typename T>
	void matrixMultiply(T** a, T **b, T** c, int m, int n, int p) {
		for (int i{}; i < m; ++i) {
			T sum = 0;
			for (int j{}; j < p; ++j) {
				for (int k{}; k < n; ++k) {
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum;
			}
		}
	}
	//����������СԪ��
	template <typename T>
	bool minmax(T a[], int n, int& indexOfMax, int& indexOfMin) {
		if (n < 1) return false;
		indexOfMax = indexOfMin = 0;
		for (int i{1}; i < n; ++i) {
			if (a[indexOfMax] < a[i]) indexOfMax = i;
			else if (a[indexOfMin] > a[i]) indexOfMin = i;
		}
		return true;
	}
	//�����������
	template <typename T>
	int disorderSequentialSearch(T a[], int n, const T& x) {
		int i;
		for (i = 0; a[i] != x; ++i);
		if (i == n) return -1;
		return i;
	}
}
#endif