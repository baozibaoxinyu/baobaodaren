//file:Stack.h
//实现Stack的嵌套类模板
#ifndef STACK_H
#define STACK_H
#include <stdexcept>
template <typename T>
class Stack{
	//在Stack里面定义Node类，来实现Stack容量的自动增减
	//因为Node类声明为private成员，因此Node内部成员全部可以声明为public成员
private:
	class Node {
	public:
		T* pItem{};		//Pointer to object stored
		Node* pNext{};	//Pointer to next node
		Node(T& item) :pItem{ &item } {}		//Create a node from an Object
	};
	//Stack只关注顶部的节点，因此只有一个Node*类型的数据成员pHead
	//Stack私有成员copy在副本构造函数和赋值运算符内部使用
	//freeMemory是一个辅助函数，由析构函数和赋值运算符使用
	Node* pHead{};		//Pointer to the top of the Stack
	void copy(const Stack& stack);			//Helper to copy stack
	void freeMemory();
public:
	Stack() = default;	//default constructor
	Stack(const Stack& stack);				//copy constructor
	~Stack();
	Stack& operator=(const Stack& stack);	//Assignment operator
	void push(T& item);						//Push an object onto the Stack
	T& pop();								//Pop an object off the Stack
	bool isEmpty() { return !pHead; }		//Judge Stack status
};
//Stack member function template
//Copy的功能是将栈复制到假定为空的Stack对象中。
template <typename T>
void Stack<T>::copy(const Stack& stack) {
	if (stack.pHead) {
		pHead = new Node(*stack.pHead);		//Copy the top node of the original
		Node* pOldNode{ stack.pHead };		//Points to the top node of the original
		Node* pNewNode{ pHead };			//Points to the node in new Stack
		while (pOldNode = pOldNode->pNext) {	//If it's nullptr,it's the last node
			pNewNode->pNext = new Node{ *pOldNode };
			pNewNode = pNewNode->pNext;			//Move to the node just created
		}
	}
}
//删除属于当前Stack对象的所有Node对象，pHead为nullptr
template <typename T>
void Stack<T>::freeMemory() {
	Node* pTemp{};
	while (pHead) {
		pTemp = pHead->pNext;	//Get the pointer is not Null
		delete pHead;			//Delete the current node
		pHead = pTemp;			//Make the next current
	}
}
//copy constructor
template <typename T>
Stack<T>::Stack(const Stack& stack) {
	copy(stack);
}
template <typename T>
Stack<T>::~Stack() {
	freeMemory();
}
//赋值运算符与副本构造函数类似，但是需要将等号左边的对象释放空间，然后再进行复制
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& stack) {
	if (this != &stack) {
		freeMemory();
		copy(stack);
	}
	return *this;
}
template <typename T>
void Stack<T>::push(T& item) {
	Node* pNode{ new Node(item) };
	pNode->pNext = pHead;
	pHead = pNode;
}
template <typename T>
T& Stack<T>::pop() {
	T* pItem{ pHead->pItem };
	if (!pItem) {
		throw std::logic_error("Stack empty");
	}
	Node* pTemp{ pHead };
	pHead = pTemp->pNext;
	delete pTemp;
	return *pItem;
}
#endif