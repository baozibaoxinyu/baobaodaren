#include <iostream>
#include <memory>
#include "Box.h"
#include "Carton.h"
#include "CerealPack.h"

int main()
{
	//如果是下面的定义，动态转换无法实现
	//Box* pBox = new Box(1.2, 1.4, 1.5);
	Box box(1.4, 1.5, 1.6);
	std::shared_ptr<Box> spBox = std::make_shared<Box>(box);
	std::shared_ptr<Box> spBox1 = std::make_shared<Box>(box);
	spBox->showVolumn();
	spBox1->showVolumn();
	//Box* pBox = new Box(1.2, 1.4, 1.5);
	//Carton* pCarton = new Carton(1,1,1);
	//CerealPack* pCer = new CerealPack(2.3,2.5,2.6);
	//pBox->showVolumn();
	//pBox = pCarton;
	//pBox->showVolumn();
	//pBox = pCer;
	//pBox->showVolumn();
	//delete pCarton;
	//delete pBox;
	//delete pCarton;
	//delete pCer;
	//std::cout << "Box volumn is " << pBox->volumn() << std::endl;
	//pBox = pCarton;
	//pBox->showVolumn();
	//pBox = pCer;
	//这里输出的没有按照想要的体积输出，还是利用Box的Volumn计算方式
	//多态性体现在一个基类指针在指向派生类和基类时可以对于同一个函数
	//会根据函数所处的类而有不同的值
	//pBox->showVolumn();
	//在动态转换中，pBox一定要指向Carton类型的对象才能实现这种动态转换
	//Carton* pCarton{ dynamic_cast<Carton*>(pBox) };
	//if (pCarton) {
	//	pCarton->showVolumn();
	//}
	//这里不能使用delete来释放内存，因为会在析构函数内进行释放；
	//delete pCarton;
	//delete pBox;
	return 0;
}