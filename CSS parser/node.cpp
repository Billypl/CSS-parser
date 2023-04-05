#include "node.h"

template<typename T>
size_t node<T>::findLastFilledIndex()

{
	for (int i = N - 1; i >= 0; i--)
		if (filled[i] == true)
			return i;
	return -1;
}

template<typename T>
void node<T>::add(const T& item)
{
	if (size < N && findLastFilledIndex() != N - 1)
	{
		items[findLastFilledIndex() + 1] = item;
		filled[findLastFilledIndex() + 1] = true;
		size++;
	}
	else
		throw "items are full!";
}
template<typename T>
T& node<T>::operator[](size_t index)
{
	if (index < 0 || index >= N || index > size)
		throw "out of bounds!";
	size_t i = findMappedIndex(index);
	if(i == -1)
		throw "out of bounds!";
	return items[i];
}

template<typename T>
size_t node<T>::findMappedIndex(size_t index)
{
	for (int i = 0, j = -1; i < N; i++)
	{
		if (filled[i] == true)
			j++;
		if (j == index && filled[i] == true)
			return i;
	}
	return -1;
}

template<typename T>
void node<T>::pop()
{
	size--;
	filled[findLastFilledIndex()] = false;
}

template<typename T>
node<T>::node()
{
	for (int i = 0; i < N; i++)
		filled[i] = false;
}