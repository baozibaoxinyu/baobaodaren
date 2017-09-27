#include <iostream>
#include "bao_algorithm.h"
using namespace std;
using namespace Bao;
template <typename T>
void showMatrix(T **a,int column,int row) {
	for (int i{}; i < column; ++i) {
		for (int j{}; j < row; ++j) {
			cout << a[i][j] << " ";
		}
		cout << endl;
		}	
}
//访问二维数组的方式：
//1，将二维数组一维化
//2，建立一个指向数组的指针，类似于：
//int a[4][4] ;
//int (*p)[4] = a;此时可以对元素采取下标运算符p[1][2]来进行访问，或者*(*(p+1)+2)这种形式进行访问。
//3，建立一个指向指针的指针进行访问
//int a[4][4];
//int *b[4] = {a[0],a[1],a[2],a[3]}; //此处建立的是一个指针数组，每个数组内都存放一个指针。与上面的p不同
//上面的p是一个数组指针，每个p指向的是一个数组，两个概念不同
//int ** c = b;此时c指向b的地址，c[0] = a[0],c[0][1] = a[0][1];
int main() 
{
	int a[4][4] = { 1,2,3,4,2,2,3,4,3,2,3,4,4,2,3,4 };
	int *p[4] = { a[0],a[1],a[2],a[3] };
	int(*d)[4] = a;
	cout << d[1][2] << *(*(d+1)+2) << endl;
	int** c = p;
	//cout << *(a + 1) << *(*(a + 1));
	showMatrix(p, 4, 4);
	cout << endl;
	transpose(p, 4);
	showMatrix(c, 4, 4);
	//std::cout << std::endl;
	
}