#pragma once
#include <iostream>
using namespace std;
template <class T>
class DynamicArray
{
	T* arr;
	int m_size;
	int m_capacity;
	void grow();
public:
	DynamicArray(int initialCap = 10);
	int size();
	T get(int index);
	void add(T item);
	void insert(T item, int index);
	void remove(int index);
	T& operator[](int index);

	template <class T>
	friend ostream& operator<<(ostream& out, DynamicArray<T>& array);
};
template <class T>
ostream& operator<<(ostream& out, DynamicArray<T>& array)
{
	out << "[";
	for (int i = 0; i < array.m_size; i++)
	{
		if (i != 0)
			out << ", ";
		out << array.arr[i];
	}
	return out << "]\n";
}

template <class T>
DynamicArray<T>::DynamicArray(int initialCap)
{
	arr = new T[initialCap];
	m_capacity = initialCap;
	m_size = 0;
}
template <class T>
int DynamicArray<T>::size()
{
	return m_size;
}

template <class T>
T DynamicArray<T>::get(int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::logic_error("Array index out of bounds");
	}
	return arr[index];
}

template <class T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::logic_error("Array out of bounds");
		
	}
	return arr[index];
}

template <class T>
void DynamicArray<T>::grow()
{
	cout << "Growing from " << m_capacity;
	T* newArr = new T[m_capacity * 2];
	for (int i = 0; i < m_size;i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	m_capacity *= 2;
	cout << " to " << m_capacity << endl;
}

template <class T>
void DynamicArray<T>::add(T item)
{
	if (m_size == m_capacity)
	{
		grow();
	}
	arr[m_size] = item;
	m_size++;
}

template <class T>
void DynamicArray<T>::remove(int index)
{
	if (index < 0 || index >= m_size)
	{
		throw logic_error("Index out of bounds");
	}
	for (int i = index; i < m_size;i++)
	{
		arr[i] = arr[i+1];
	}
	m_size--;
}