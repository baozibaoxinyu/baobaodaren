/***************************
 * 编写一个非递归函数计算n!
 ***************************/
#include <iostream>
int factorial(int n){
    int sum = 1;
    if(n<= 0){
        std::cout<< " the number is less than 1,you pass a wrong number" << std::endl;
        return 0;
    }
    while(n){
        sum *= n;
	--n;
    }
    return sum;
}

int main()
{
    int n;
    std::cout << "please input a positive integer :"; 
    std::cin >> n ;
    std::cout << n << "'s factorial is " << factorial(n) << std::endl;
    return 0;
}
