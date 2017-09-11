#include <iostream>
template <typename T>
void make2dArray(T** &x,int numberOfRaws,T rowSize[]);
template <typename T>
void delete2dArray(T** &x,int numberOfRaws);
template <typename T>
void show2dArray(T** &x,int numberOfRaws);

int main()
{
    int** a = NULL;
    int numberOfRaws = 10;
    int rowSize[10]= {1,2,3,4,5,6,7,8,9,10};
    make2dArray(a,numberOfRaws,rowSize);
    show2dArray(a,numberOfRaws);
    delete2dArray(a,numberOfRaws);
    return 0;
}
template <typename T>
void make2dArray(T** &x,int numberOfRaws,T rowSize[]){
    x = new T* [numberOfRaws];
    for(int i{};i< numberOfRaws;++i){
        x[i]= new T [rowSize[i]];
    }
}
template <typename T>
void delete2dArray(T** &x,int numberOfRaws){
    for(int i{};i< numberOfRaws;++i){
        delete [] x[i];
    }
    delete [] x;
    x = NULL;
}
template <typename T>
void show2dArray(T** &x,int numberOfRaws){
    for(int i{};i< numberOfRaws;++i){
        std::cout<< sizeof(x[i]) << std::endl;
    }
}
