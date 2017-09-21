//file:use_shared_ptr.cpp
//using shared_ptr<T> pointer
#include <iostream>
#include <memory>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main()
{
	//define a shared_ptr object
	//std::shared_ptr<string> str = new string{ "1234" };这种赋值方式是错误的
	//std::shared_ptr<string> pstr{ new string{"baoxinyu"} };
	//cout << "the string is " << *pstr << endl;
	//another method to define a shared_ptr object,this method is more efficient
	auto pnum = std::make_shared<double>(123.0);
	cout << "the number is " << *pnum << endl;
	//you can use a defined smart pointer to initialize other smart pointer
	std::shared_ptr<double> pdata{ pnum };
	cout << "the data is " << *pdata << endl;
	std::shared_ptr<double> pdata1;
	pdata1 = pdata;
	cout << "the copy data is " << *pdata1 << endl;
	//get a normal pointer by get() function
	auto pvalue = pdata.get();
	cout << "the value is " << *pvalue << endl;
	//reset shared_ptr pointer
	pnum = nullptr;
	cout << "the shared_ptr counts are " << pdata1.use_count() << endl;
	pdata.reset();//this method is equal with above expression
	cout << "the shared_ptr counts are " << pdata1.use_count() << endl;
	pdata1.reset(new double{25.3});
	cout << "the shared_ptr counts are " << pdata.use_count() << endl;
	cout << "the shared_ptr counts are " << pdata1.use_count() << endl;
	//check shared_ptr pointer has a copy
	if (pdata1.unique()) cout << "there is only one" << endl;
	else cout << "there is more than one." << pdata1.use_count() << endl;
	return 0;
}