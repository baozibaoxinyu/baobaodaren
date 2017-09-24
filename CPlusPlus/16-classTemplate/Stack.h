//file:Stack.h
//ʵ��Stack��Ƕ����ģ��
#ifndef STACK_H
#define STACK_H
#include <stdexcept>
template <typename T>
class Stack{
	//��Stack���涨��Node�࣬��ʵ��Stack�������Զ�����
	//��ΪNode������Ϊprivate��Ա�����Node�ڲ���Աȫ����������Ϊpublic��Ա
private:
	class Node {
	public:
		T* pItem{};		//Pointer to object stored
		Node* pNext{};	//Pointer to next node
		Node(T& item) :pItem{ &item } {}		//Create a node from an Object
	};
	//Stackֻ��ע�����Ľڵ㣬���ֻ��һ��Node*���͵����ݳ�ԱpHead
	//Stack˽�г�Աcopy�ڸ������캯���͸�ֵ������ڲ�ʹ��
	//freeMemory��һ�����������������������͸�ֵ�����ʹ��
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
//Copy�Ĺ����ǽ�ջ���Ƶ��ٶ�Ϊ�յ�Stack�����С�
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
//ɾ�����ڵ�ǰStack���������Node����pHeadΪnullptr
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
//��ֵ������븱�����캯�����ƣ�������Ҫ���Ⱥ���ߵĶ����ͷſռ䣬Ȼ���ٽ��и���
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