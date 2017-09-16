/***************************************
 *在数据结构学习里的一些利用STL的相关简
 *易程序
 ***************************************/
#include <iostream>
#include <numeric>
#include <functional>
#include <iterator>
//利用accumulate()函数进行累计求和
//函数原型为accumulate(start,end,initialValue,operator)
//operator是一个函数，规定了累计的过程中的操作
template <typename T>
T sum(T a[],int n){
    T theSum = 0;
    return std::accumulate(a,a+n,theSum);
}
//利用multiplies函数进行相乘操作。
template <typename T>
T product(T a[],int n){
    T theProduct = 1;
    return std::accumulate(a,a+n,theProduct,std::multiplies<T>());
}
//使用copy和next_permutation
template <typename T>
void permutation(T list[],int k,int m){
    do{
        std::copy(list,list+m+1,
	    std::ostream_iterator<T>(std::cout,""));
        std::cout<<std::endl;
    }while(next_permutation(list,list+m+1));

}
template <typename T>
void showArrays(T a[],int n){
    for(int i{};i<n;++i){
        std::cout<<"a["<<i<<"]"<<" = " << a[i]<< " ";
        if((i+1)%5 == 0){
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}

int main()
{
    int a[10]= {1,2,3,4,5,6,7,8,9,10};
    std::cout<<"total number of array a is "<<sum(a,10)<<std::endl;
    std::cout<<"multiplies number of array a is " << product(a,10) << std::endl;
    permutation(a,0,10);
    showArrays(a,10);
    return 0;
}
