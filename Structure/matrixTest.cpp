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
//���ʶ�ά����ķ�ʽ��
//1������ά����һά��
//2������һ��ָ�������ָ�룬�����ڣ�
//int a[4][4] ;
//int (*p)[4] = a;��ʱ���Զ�Ԫ�ز�ȡ�±������p[1][2]�����з��ʣ�����*(*(p+1)+2)������ʽ���з��ʡ�
//3������һ��ָ��ָ���ָ����з���
//int a[4][4];
//int *b[4] = {a[0],a[1],a[2],a[3]}; //�˴���������һ��ָ�����飬ÿ�������ڶ����һ��ָ�롣�������p��ͬ
//�����p��һ������ָ�룬ÿ��pָ�����һ�����飬�������ͬ
//int ** c = b;��ʱcָ��b�ĵ�ַ��c[0] = a[0],c[0][1] = a[0][1];
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