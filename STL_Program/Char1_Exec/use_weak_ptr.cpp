//file:use_weak_ptr.cpp
//这里建立了一个类A，里面有一个shared_ptr<A>的成员，用来指向A类型的对象
//在main函数里定义了ABCD四个A类型的shared_ptr指针，同时设置A类型的每个对象
//的内部shared_ptr成员指向另一个对象，出现A->B->C->D->A的情况。
//在这种情况下，如果删除了ABCD四个指针，或者设置为空，他们指向的对象的内存
//也无法释放，因此为了防止这种情况出现，使用weak_ptr指针可以解决
#include <iostream>
#include <memory>
#include <string>
using std::string;
class A{
private:
	string name = nullptr;
	int member = 0;
	//将内部的shared_ptr指针替换成weak_ptr指针，可以在删除指针的情况释放资源。
	std::weak_ptr<A> mem;
public:
	A(int theMem, string theName) :member{ theMem }, name{ theName } {}
	void setMem(std::shared_ptr<A> theMem) {
		mem = theMem;
	}
	void showMem() {
		std::cout << "the member " << member << " name is " << name << std::endl;
		std::cout << "object " << name << " is point to " << mem.lock()->name << std::endl;
	}
	std::weak_ptr<A> getMem() {
		return mem;
	}
};

int main()
{
	std::shared_ptr<A> pA{ new A(10,"baba") };
	std::shared_ptr<A> pB{ new A(11,"Baby") };
	std::shared_ptr<A> pC{ new A(12,"Cicy") };
	std::shared_ptr<A> pD{ new A(13,"Dady") };
	pA->setMem(pB);
	pB->setMem(pC);
	pC->setMem(pD);
	pD->setMem(pA);
	pA.reset();
	if (!pA)
		std::cout << "Object A is reset.\n";
	else
		pA->showMem();
	pB->showMem();
	pC->showMem();
	if (pD->getMem().expired())
		std::cout << "Object A no longer exist.\n";
	else
		pD->showMem();
	return 0;
}