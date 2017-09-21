//unique_ptr<T>拥有自己的地址，不能和unique_ptr<T>指针拥有同一个地址
//可以使用utility头文件中的move()函数进行unique_ptr<T>指针地址的移除
//进行此操作后，之前的unique_ptr<T>指针失效

#include <iostream>
#include <memory>
#include <string>
using std::string;

int main()
{
    //using unique_ptr<T> pointer
    std::unique_ptr<string> pName { new string{"Baozi"}};
    std::cout<< "Using construct to creat a string:"<< *pName << std::endl;
    auto pname = std::make_unique<string>("Baoxinyu");
    std::cout << "Using template in memory head file to creat a string:"
	     << *pname << std::endl;
    //using unique_ptr<T> pointer to creat an array
    int len = 10;
    std::unique_ptr<int> pArray{ new int[len]};
    for(int i{};i<len;++i){
	pArray[i] = i*i;
    }
    //Using index to output array number
    for(int i{};i<len;++i){
	std::cout<< pArray[i] <<std::endl;
    }
    //不能通过传值的方式将一个unique_ptr对象传入函数中，因为不支持copy，只能
    //通过引用的方式进行传值。可以作为一个函数的返回值，但是必须以隐式移动运
    //算的方式返回
    //example还在考虑
    //get a normal pointer in unique_ptr<T> pointer
    auto unique_p = std::make_unique<string>(6,'*');
    string ptr {unique_p.get()}
    std::cout << "unique_ptr pointer value is " << *unique_p << std::endl;
    std::cout << "normal pointer value is " << str << std::endl;

    //reset unique_ptr obiect
    pName.reset();//release memory for string object,and pName is still exist
    pname.reset(new string{"Baobao"};//release memory and pass a new value
    //release unique_ptr object
    auto up_name = std::make::unique<string>("Bao");
    std::unique_ptr<string> up_new_ptr { up_name.release()};
    std::cout << "up new name is " << *up_new_name <<std::endl;
    return 0;
    
}
