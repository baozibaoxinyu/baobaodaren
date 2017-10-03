#include <iostream>
#include <string>
#include "bao_linearList.h"
using namespace BXY;

int main()
{
	try {
		//arrayList<int> a{0};会抛出异常
		arrayList<int> a;
		int* x = new int[4];
		for (int i{}; i < 4; ++i) {
			x[i] = i + 1;
		}
		arrayList<int> b{ x,4 };
		b.showList();
		//这边由于之前没有重载赋值运算符，导致使用默认的赋值运算符，会出现当a的元素释放时，b的元素也清空
		a = b;
		a.showList();
		a.insert(2, 6, 1);
		a.showList();
		a.eraseIndexElement(2);
		//a.eraseAllElement();
		a.showList();
		b.showList();
		std::cout << "The element of index 3 is " << a.getIndexElement(3)
			<< " and the index of elements 4 is " << a.getElementIndex(4) << std::endl;
	}
	catch (illegalParameterValue ex) {
		ex.getMessage();
	}
	catch (illegalIndex ex) {
		ex.getMessage();
	}
	
}