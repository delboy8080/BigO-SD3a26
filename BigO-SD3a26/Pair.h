#include <iostream>
using std::ostream;
#pragma once
template <class K, class V>
class Pair
{
	K first;
	V second;
public:
	Pair(K f, V s);
	K getFirst();
	V getSecond();
	void setFirst(K f);
	void setSecond(V s);
	template <class K, class V>
	friend ostream& operator<<(ostream& out, Pair<K, V>& p);
};
template <class K, class V>
ostream& operator<<(ostream& out, Pair<K, V>& p)
{
	return out << p.first << " -> " << p.second << std::endl;
}
template <class K, class V>
Pair<K, V>::Pair(K f, V s)
{
	first = f;
	second = s;
}

template <class K, class V>
K Pair<K, V>::getFirst()
{
	return first;
}

template <class K, class V>
V Pair<K, V>::getSecond()
{
	return second;
}
template <class K, class V>
void Pair<K, V>::setFirst(K f)
{
	first = f;
}

template <class K, class V>
void Pair<K, V>::setSecond(V s)
{
	second = s;
}