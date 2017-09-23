//file:Solu_1.cpp
//define a standard array,use your words to initialize the string object
//and use iterator to list the content
#include <iostream>
#include <string>
int main()
{
	std::string words[]{ "Alen","Bob","Celin","David" };
	for(auto iter = std::begin(words);iter!= std::end(words);++iter){
		std::cout << *iter << std::endl;
	}
	std::cout << words[1][2] << std::endl;
	return 0;
}