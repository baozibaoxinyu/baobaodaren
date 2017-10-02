#ifndef BAO_LINEARLIST_H
#define BAO_LINEARLIST_H
#include "../../Char2_Exercise/Char2_Solu/bao_algorithm.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
namespace Bao {
	//����һ�����Ա�ĳ�����
	template <typename T>
	class linearList {
	public:
		virtual ~linearList() {}
		//�ж����Ա��Ƿ�Ϊ�գ�Ϊ�շ���true������Ϊfalse
		virtual bool empty() const = 0;
		//�������Ա�ĳ���
		virtual int size() const = 0;
		//�õ�ָ��������Ӧ��ֵ
		virtual T& get(int theIndex) const = 0;
		//�õ����Ա��ڵ�һ�γ���x�����������û�з���-1
		virtual int indexOf(const T& theElement) const = 0;
		//ɾ������Ϊindex��ֵ����������index��Ԫ��������-1
		virtual void erase(int theIndex) = 0;
		//��x�������Ա�������Ϊindex��λ�ã���������index��Ԫ��������+1
		virtual void insert(int theIndex, const T& theElement) = 0;
		//��������������Ա��Ԫ��
		virtual void output(std::ostream& out) const = 0;
	};
	//����arrayList
	template <typename T>
	class arrayList : public linearList<T> {
	protected:
		//��index��Ч�����׳��쳣
		void checkIndex(int theIndex) const;
		//�洢���Ա�Ԫ�ص�һά����
		T* elements;
		//һά���������
		int arrayLength;
		//���Ա��Ԫ�ظ���
		int listSize;
	public:
		//���캯��
		arrayList(int initialCapacity);
		arrayList(const arrayList<T>&);
		~arrayList() { delete[] elements; }

		bool empty() const override { return listSize == 0; }
		int size() const override { return listSize; }
		T& get(int theIndex) const override;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex, const T& theElement);
		void output(std::ostream& out) const;
		int capacity() const { return arrayLength; }
	};
	//arrayList�Ĺ��캯��
	template <typename T>
	arrayList<T>::arrayList(int initialCapacity) {
		if (initialCapacity < 0) {
			std::ostringstream s;
			s << "Initial capacity = " << initialCapacity << " Must be > 0";
			throw illegalParameterValue(s.str());
		}
		arrayLength = initialCapacity;
		elements = new T[arrayLength];
		listSize = 0;
	}
	//arrayList�ĸ������캯��
	template <typename T>
	arrayList<T>::arrayList(const arrayList<T>& theList) {
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		elements = new T[arrayLength];
		std::copy(theList.elements, theList.elements + listSize, element);
	}
	template <typename T>
	void arrayList<T>::checkIndex(int theIndex) const {
		if (theIndex < 0 || theIndex >= listSize) {
			std::ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
	}
	template <typename T>
	T& arrayList<T>::get(int theIndex) const {
		checkIndex(theIndex);
		return elements[theIndex];
	}
	template <typename T>
	int arrayList<T>::indexOf(const T& theElement) const {
		int theIndex = int(std::find(elements, elements + listSize, theElement) - elements);
		if (theIndex == listSize) return -1;
		else return theIndex;
	}
	template <typename T>
	void arrayList<T>::erase(int theIndex) {
		checkIndex(theIndex);
		std::copy(elements + theIndex + 1, elements + listSize, elements + theIndex);
		elements[--listSize].~T();
	}
	template <typename T>
	void arrayList<T>::insert(int theIndex, const T& theElement) {
		if (theIndex<0 || theIndex>listSize) {
			std::ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
		if (arrayLength == listSize) {
			changeLength1D(elements, arrayLength, 2 * arrayLength);
			arrayLength = 2 * arrayLength;
		}
		std::copy_backward(elements + theIndex, elements + listSize, elements + listSize + 1);
		elements[theIndex] = theElement;
		++listSize;
	}
	template <typename T>
	void arrayList<T>::output(std::ostream& out) const {
		std::copy(elements, elements + listSize, std::ostream_iterator<T>(out, " "));
	}
	template <typename T>
	std::ostream& operator<<(std::ostream& out, const arrayList<T>& x) {
		x.output(out);
		return out;
	}
}
#endif
