#include <iostream>
#include "bao_algorithm.h"
const int row1 = 4, column1 = 5;
const int row2 = column1, column2 = 3;
using namespace std;
using namespace Bao;
template <typename T>
void getFirstPointer(T a[][column1],T *b[]) {
	for (int i{}; i < row1; ++i) {
		b[i] = a[i];
	}
}
template <typename T>
void getSecondPointer(T a[][column2], T *b[]) {
	for (int i{}; i < row2; ++i) {
		b[i] = a[i];
	}
}
template <typename T>
void getThirdPointer(T a[][column2], T *b[]) {
	for (int i{}; i < row1; ++i) {
		b[i] = a[i];
	}
}
template <typename T>
void showMatrix(T **a,int theRow,int theColumn) {
	for (int i{}; i < theRow; ++i) {
		for (int j{}; j < theColumn; ++j) {
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
	/*
	int a[4][4] = { 1,2,3,4,2,2,3,4,3,2,3,4,4,2,3,4 };
	int b[4][4] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int c[4][4] = { 0 };
	int *pA[4] = { a[0],a[1],a[2],a[3] };
	int *pB[4];
	for (int i{}; i < row1; ++i) {
		pB[i] = b[i];
	}
	int* pC[4];
	getPointer(c, pC);
	//cout << *(a + 1) << *(*(a + 1));
	cout << "Matrix A\n";
	showMatrix(pA, 4, 4);
	cout << "Matrix B\n";
	showMatrix(pB, 4, 4);
	cout << "Matrix C\n";
	showMatrix(pC, 4, 4);
	//cout << endl;
	//transpose(pA, 4);
	//showMatrix(ppA, 4, 4);
	//std::cout << std::endl;
	matrixAdd(pA, pB, pC, 4, 4);
	cout << "Matrix A + Matrix B\n";
	showMatrix(pC, 4, 4);
	squareMatrixMultiply(pA, pB, pC, 4);
	cout << "Matrix A * Matrxi B\n";
	showMatrix(pC, row1, column1);
	*/
	//M*N�����N*P�������
	/*
	int a[row1][column1]{ 1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4 };
	int b[row2][column2]{ 1,1,1,2,2,2,3,3,3,4,4,4,5,5,5 };
	int *pA[row1];
	int *pB[row2];
	getFirstPointer(a, pA);
	getSecondPointer(b, pB);
	//int *pA[row1] = { a[0],a[1],a[2],a[3] };
	//int *pB[row2] = { b[0],b[1],b[2],b[3],b[4] };
	int c[row1][column2] = { 0 };
	int *pC[row1];
	getThirdPointer(c, pC);
	//int *pC[row1] = { c[0],c[1],c[2],c[3] };
	cout << "Matrix A\n";
	showMatrix(pA, row1, column1);
	cout << "Matrix B\n";
	showMatrix(pB, row2, column2);
	cout << "Matrix C\n";
	showMatrix(pC, row1, column2);
	matrixMultiply(pA, pB, pC, row1, column1, column2);
	cout << "Matrix A * Matrix B\n";
	showMatrix(pC, row1, column2);
	*/
	int a[] = { 1,3,2,5,1,6,2 };
	int indexOfMax{};
	int indexOfMin{};
	minmax(a, sizeof(a) / sizeof(a[0]), indexOfMax, indexOfMin);
	cout << "the indexOfMax is " << indexOfMax << endl;
	cout << "the indexOfMin is " << indexOfMin << endl;
	int x = 2;
	int index = disorderSequentialSearch(a, sizeof(a) / sizeof(a[0]),x);
	cout << index;
}