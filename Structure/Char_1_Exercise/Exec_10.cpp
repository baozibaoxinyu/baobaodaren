#include <iostream>

int abc(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) {
		throw 2;
	}
	if (a < 0 && b < 0 && c < 0) {
		throw 1;
	}
	return a*b*c;
}

int main()
{
	try { std::cout << abc(-1, -1, -1) << std::endl; }
	catch (int a) {
		if(a==1)
			std::cout << "a&b&c are all less than 0" << std::endl;
		if (a == 2)
			std::cout << "a&b&c are all equal with 0" << std::endl;
	}

}
