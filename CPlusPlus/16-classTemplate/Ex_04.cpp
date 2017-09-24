#include <iostream>
#include <string>
#include "Stack.h"
using std::string;
int main()
{
	const char* words[]{ "The","bigest","world","in","my","mind" };
	Stack<const char*> work;
	for (size_t i{}; i < sizeof(words) / sizeof(words[0]); ++i) {
		work.push(words[i]);
	}
	Stack<const char*> newStack{ work };
	while (!newStack.isEmpty()) {
		std::cout << newStack.pop() << " ";
	}
	std::cout << std::endl;
	while (!work.isEmpty()) {
		newStack.push(work.pop());
	}
	while (!newStack.isEmpty()) {
		std::cout << newStack.pop() << " ";
	}
	std::cout << std::endl;
}