#pragma once
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
};