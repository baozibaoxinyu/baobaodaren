#include <iostream>
#include <memory>
#include "Box.h"
#include "Carton.h"
#include "CerealPack.h"

int main()
{
	//���������Ķ��壬��̬ת���޷�ʵ��
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
	//���������û�а�����Ҫ������������������Box��Volumn���㷽ʽ
	//��̬��������һ������ָ����ָ��������ͻ���ʱ���Զ���ͬһ������
	//����ݺ�������������в�ͬ��ֵ
	//pBox->showVolumn();
	//�ڶ�̬ת���У�pBoxһ��Ҫָ��Carton���͵Ķ������ʵ�����ֶ�̬ת��
	//Carton* pCarton{ dynamic_cast<Carton*>(pBox) };
	//if (pCarton) {
	//	pCarton->showVolumn();
	//}
	//���ﲻ��ʹ��delete���ͷ��ڴ棬��Ϊ�������������ڽ����ͷţ�
	//delete pCarton;
	//delete pBox;
	return 0;
}