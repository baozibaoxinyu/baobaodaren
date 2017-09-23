//file:Ex1_03.cpp
//Passing functions to an algorithm
#include <iostream>
#include <functional>	//for function
#include <algorithm>	//for transform
#include <iterator>		//for iterator

class Root {
public:
	double operator()(double x) { return std::sqrt(x); }
};
int main()
{
	double data[]{ 1.5,1.6,1.7,1.8,1.9 };
	//Passing a function object
	Root root;
	std::cout << "Square roots are " << std::endl;
	//using transform function and lambda expression have same result
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, "\n"), [&root](double x) {return root(x); });
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, "\n"), root);
	//Passing a lambda expression
	std::cout << "Cubes are " << std::endl;
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, "\n"), [](double x) {return x*x*x; });
	//Passing a oparator by function()
	std::function<double(double)> cube = [](double x) {return x*x*x; };
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, "\n"), cube);
	return 0;

}