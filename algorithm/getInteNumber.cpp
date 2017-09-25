#include <iostream>
using namespace std;

size_t getInteNumber(size_t bytes,size_t n){
	return ((bytes+n-1) & ~(n-1));
}

int main()
{
	size_t bytes = 23;
	size_t multiple = 4;
	cout << !true << endl;
	cout << getInteNumber(bytes,multiple) << endl;
}
