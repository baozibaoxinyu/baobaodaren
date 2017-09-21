//file:use_weak_ptr.cpp
//���ｨ����һ����A��������һ��shared_ptr<A>�ĳ�Ա������ָ��A���͵Ķ���
//��main�����ﶨ����ABCD�ĸ�A���͵�shared_ptrָ�룬ͬʱ����A���͵�ÿ������
//���ڲ�shared_ptr��Աָ����һ�����󣬳���A->B->C->D->A�������
//����������£����ɾ����ABCD�ĸ�ָ�룬��������Ϊ�գ�����ָ��Ķ�����ڴ�
//Ҳ�޷��ͷţ����Ϊ�˷�ֹ����������֣�ʹ��weak_ptrָ����Խ��
#include <iostream>
#include <memory>
#include <string>
using std::string;
class A{
private:
	string name = nullptr;
	int member = 0;
	//���ڲ���shared_ptrָ���滻��weak_ptrָ�룬������ɾ��ָ�������ͷ���Դ��
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