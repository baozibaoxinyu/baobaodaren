#ifndef BAO_LINEARLIST_H
#define BAO_LINEARLIST_H
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <iterator>
namespace BXY {
	class illegalParameterValue {
	private:
		std::string message;
	public:
		illegalParameterValue() :message{ "illegal parameter value." } {}
		explicit illegalParameterValue(char* theMessage) :message{ theMessage } {}
		explicit illegalParameterValue(std::string theMessage) :message{ theMessage } {}
		void getMessage() {
			std::cout << message << std::endl;
		}
	};
	//define self-defined exception
	class illegalIndex {
	private:
		std::string message;
	public:
		illegalIndex() :message{ "illegalIndex." }{}
		explicit illegalIndex(char* theMessage):message{theMessage}{}
		explicit illegalIndex(std::string theMessage) :message{ theMessage } {}
		void getMessage() {
			std::cout << message << std::endl;
		}
	};
	//�޸�1ά���鳤��
	template <typename T>
	void change1DArray(T*& a, int oldLength, int newLength) {
		if (newLength < 0)
			throw illegalParameterValue("New length must be >= 0");
		T* temp = new T[newLength];
		int number = std::min(oldLength, newLength);
		std::copy(a, a + number, temp);
		//���a��ͨ��new��������пռ�������Ҫ��delete������ͷ�ԭ�пռ䡣
		delete[] a;
		a = temp;
	}
	//define abstract class linearList
	template <typename T>
	class linearList {
	public:
		//destructor function
		virtual ~linearList() {}
		//�ж����Ա��Ƿ�Ϊ��
		virtual bool isEmpty() const = 0;
		//�õ����Ա��Ԫ�ظ�������˵ʵ�ʳ���
		virtual int getLength() const = 0;
		//�õ����Ա������
		virtual int getCapacity() const = 0;
		//��ָ��λ�ò���Ԫ��
		virtual void insert(int theIndex, const T& theElement,bool isSorted) = 0;
		//�õ���ӦԪ�ص�����
		virtual int getElementIndex(const T& theElement) const = 0;
		//�õ���Ӧ������Ԫ��
		virtual T& getIndexElement(int theIndex) const = 0;
		//ɾ����Ӧ������Ԫ��
		virtual void eraseIndexElement(int theIndex) = 0;
		//�����Ա�����������
		virtual void output(std::ostream& out) const = 0;
	};
	template <typename T>
	class arrayList : public linearList<T> {
	protected:
		//ָ�룬ָ������
		T* elements = nullptr;
		//���Ա�ʵ�ʳ���
		int listSize = 0;
		//���Ա�����
		int capacity = 0;
		//�ж������Ƿ���ڣ��������׳��쳣
		void checkIndex(int theIndex) const {
			if (theIndex < 0 || theIndex >= listSize) {
				std::ostringstream s;
				s << "Index = " << theIndex << " but arrayList size = " << listSize;
				throw illegalIndex(s.str());
			}
		}
	public:
		//constructor
		arrayList() {};
		arrayList(int theCapacity);
		arrayList(T* theArray,int listLength);
		arrayList(const arrayList& theList);
		//destructor
		~arrayList() {}
		void eraseIndexElement(int theIndex) override;
		void eraseAllElement();
		void insert(int theIndex, const T& theElement, bool isSorted = false) override;
		int getElementIndex(const T& theElement) const override;
		T& getIndexElement(int theIndex) const override;
		int getLength() const override;
		int getCapacity() const override;
		bool isEmpty() const override;
		void output(std::ostream& out) const override;
		void showList() const;
		arrayList<T>& operator=(const arrayList<T>& thelist);
		template <typename T>
		friend std::ostream& operator<<(std::ostream& out, const arrayList<T>& theList);
	};
	template <typename T>
	arrayList<T>::arrayList(int theCapacity) :capacity{ theCapacity } {
		if (theCapacity < 1) {
			std::ostringstream s;
			s << "Initial capacity " << theCapacity << ".Must be > 0";
			throw illegalParameterValue(s.str());
		}
		elements = new T[theCapacity];
		listSize = 0;
	}
	template <typename T>
	arrayList<T>::arrayList(T* theList,int listLength) :listSize{ listLength },
		capacity{ listSize * 2 } {
		elements = new T[capacity];
		std::copy(theList, theList + listSize, elements);
	}
	template <typename T>
	arrayList<T>::arrayList(const arrayList<T>& theList) : listSize{ theList.listSize },
		capacity{ theList.capacity }{
		elements = new T[capacity];
		std::copy(theList, theList + listSize, elements);
	}
	template <typename T>
	void arrayList<T>::eraseIndexElement(int theIndex) {
		checkIndex(theIndex);
		for (int i = theIndex; i < listSize - 1; ++i) {
			elements[i] = elements[i + 1];//���ڻ���������˵���ԣ����Ƕ���������Ҫ���и�ֵ�����������
		}
		--listSize;
	}
	template <typename T>
	void arrayList<T>::eraseAllElement() {
		if (elements != nullptr) {
			delete[] elements;
			elements = nullptr;
		}
		listSize = 0;
	}
	//�����������в��룬����������Ϊ��ѡ�ȱʡֵΪ�����򣬿�ѡ����
	template <typename T>
	void arrayList<T>::insert(int theIndex, const T& theElement, bool isSorted = false) {
		checkIndex(theIndex);
		if (listSize == capacity && listSize != 0) {
			change1DArray<T>(elements, capacity, 2 * capacity);
			capacity *= 2;
		}
		if (!isSorted) {
			std::copy_backward(elements + theIndex, elements + listSize, elements + listSize + 1);
			elements[theIndex] = theElement;
			++listSize;
		}
		else {
			std::copy_backward(elements + theIndex, elements + listSize, elements + listSize + 1);
			elements[theIndex] = theElement;
			++listSize;
			std::sort(elements, elements + listSize);
		}
	}
	template <typename T>
	int arrayList<T>::getElementIndex(const T& theElement) const {
		int index = int(std::find(elements, elements + listSize, theElement) - elements);
		if (index == listSize)
			return -1;
		else
			return index;
	}
	template <typename T>
	T& arrayList<T>::getIndexElement(int theIndex) const {
		checkIndex(theIndex);
		return elements[theIndex];
	}
	template <typename T>
	int arrayList<T>::getLength() const {
		return listSize;
	}
	template <typename T>
	int arrayList<T>::getCapacity() const {
		return capacity;
	}
	template <typename T>
	bool arrayList<T>::isEmpty() const {
		return listSize == 0;
	}
	template <typename T>
	void arrayList<T>::output(std::ostream& out) const {
		std::copy(elements, elements + listSize, std::ostream_iterator<T>(out, " "));
	}
	template <typename T>
	arrayList<T>& arrayList<T>::operator=(const arrayList<T>& theList) {
		listSize = theList.listSize;
		capacity = theList.capacity;
		elements = new T[theList.capacity];
		std::copy(theList.elements, theList.elements + theList.listSize, elements);
		return *this;
	}
	template <typename T>
	std::ostream& operator<<(std::ostream& out, const arrayList<T>& theList) {
		theList.output(out);
		return out;
	}
	template <typename T>
	void arrayList<T>::showList() const {
		if (this->elements != nullptr)
			std::cout << "The list elements are " << *this << std::endl;
		else
			std::cout << "The list elements are null" << std::endl;
		std::cout << "The list length is " << this->listSize << std::endl;
		std::cout << "The list capacity is " << this->capacity << std::endl;
	}
}

#endif
