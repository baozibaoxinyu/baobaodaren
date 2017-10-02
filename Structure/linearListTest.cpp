#include <iostream>
#include <string>
#include "bao_linearList.h"
using namespace BXY;

int main()
{
	try {
		//arrayList<int> a{0};
		arrayList<int> a;
		int* x = new int[4];
		for (int i{}; i < 4; ++i) {
			x[i] = i + 1;
		}
		arrayList<int> b{ x,4 };
		std::cout << b.getLength() << std::endl;
		std::cout << b << std::endl;
	}
	catch (illegalParameterValue ex) {
		ex.getMessage();
	}
	catch (illegalIndex ex) {
		ex.getMessage();
	}
	
}