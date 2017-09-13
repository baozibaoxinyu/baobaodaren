/********************************
 * 编写递归函数计算fibonacci数
 * 编写非递归函数计算fibonacci数
 ********************************/
#include <iostream>
static int count ;
template <typename T>
T fibonacci_recurtion(T n){
    if(n <= 2) {
        ++count;
        std::cout << count << std::endl;
	return 1;
    }
    else {
        ++count;
        return fibonacci_recurtion(n-1)+ fibonacci_recurtion(n-2);
    }
}

template <typename T>
T fibonacci_nonRecurtion(T n){
    int f1{1},f2{1};
    int temp{0};
    for(int i{2};i<n;++i){
        temp = f2;
	f2 = f1 + f2;
        f1 = temp;
        std::cout << "In non-recurtion funtion," ;
        std::cout << f2 << " is calculated once" <<std::endl;
    }
    return f2 ;
}

int main ()
{
    int n ;
    std::cout<< "please input a number you want to calculate :"; 
    std::cin >> n;
    std::cout << "In recurtion function,the calculation number is " << count << std::endl;//这里的count输出为0，我想半天不理解。 
    std::cout << n << "'s fibonacci number is " << fibonacci_recurtion(n) << std::endl;
    std::cout << n << "'s fibonacci number that use non-recurtion funtion is "<< fibonacci_nonRecurtion(n) << std::endl;
    return 0;
}
