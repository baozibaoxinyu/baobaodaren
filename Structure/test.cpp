#include <iostream>
#include <algorithm>

class A {
private:
	int a = 0;
	int* elements = nullptr;
public:
	A() {}
	A(int theA) :a{ theA }{}
	A(int* theA) :elements{ theA } {}
	int getA() { return a; }
	int* getElements() { return elements; }
	A& operator=(const A& theA) {
		a = theA.a;
		elements = theA.elements;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& out,const A& theA);
	~A() { 
		if(elements != nullptr)
		delete elements;
		std::cout << "destructor called\n";
	}
};
inline std::ostream& operator<<(std::ostream& out, const A& theA) {
	out << theA.a;
	return out;
}

int main()
{
	//A* a = new A[3]{ A(1),A(2),A(3) };
	//int* a1 = new int[4];
	//A c(a1);
	//std::cout << a[1].getA() << std::endl;
	//a[2].~A();
	//a[1] = a[2];
	//std::cout << (a[2].getElements()) << std::endl;
	//std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
	//std::cout << a[2] << std::endl;
	//delete[] a;
	//delete[] a1;
	/*
	int* a = new int[10];
	for (int i{}; i < 3; ++i) {
		a[i] = i;
	}
	std::copy_backward(a, a + 3, a + 4);
	a[0] = 1;
	for (int i{}; i < 4; ++i) {
		std::cout << *(a+i) << " ";
	}
	delete[] a;
	*/
	int* a = new int[4];
	std::cout << sizeof(a) / sizeof(a[0]) << std::endl;
	auto iter = std::find(a, a + 3, 2);
	std::cout << int(iter - a);
}