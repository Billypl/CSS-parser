#include "list.h"
#include <iostream>

template<typename T>
List<T>::List()
	: start(nullptr), end(nullptr), size(0) {}

template<typename T>
List<T>::~List()
{
	if (size == 0)
		return;
	else if (size == 1)
	{
		delete end;
		return;
	}

	node<T>* tmp = start->next;
	do
	{
		delete start;
		start = tmp;
		tmp = tmp->next;
	} while (tmp != nullptr);

}

template<typename T>
void List<T>::add()
{
	T item;
	add(item);
}
template<typename T>
void List<T>::add(const T& item)
{
	if (size == 0)
	{
		node<T>* tmp = new node<T>;
		start = tmp;
		end = tmp;
		size++;
	}

	while (true)
	{
		try {
			end->add(item);
			return;
		}
		catch (...)
		{
			node<T>* tmp = new node<T>;
			end->next = tmp;
			tmp->prev = end;

			end = tmp;
			size++;
		}
	}
}


template<typename T>
T& List<T>::operator[](size_t index)
{
	if (index > getTotalSize() - 1)
		throw "out of bounds!";
	node<T>* tmp = start;
	while (index >= 0)
	{
		if (index >= N && tmp->size == N && tmp->next != nullptr)
		{
			tmp = tmp->next;
			index -= N;
		}
		else
			return (*tmp)[index % N];
	}
}

template<typename T>
void List<T>::pop()
{
	if (size == 0 || start->size == 0)
		throw "list is empty!";
	else if (end->size == 0)
	{
		if (size == 1)
		{
			delete end;
			end = nullptr;
			start = nullptr;
		}
		else
		{
			node<T>* tmp = end->prev;
			delete end;
			tmp->next = nullptr;
			end = tmp;
		}
		size--;
	}
	end->pop();
}

template<typename T>
void List<T>::print()
{
	for (int i = 0; i < getTotalSize(); i++)
		std::cout << (*this)[i] << " ";
	std::cout << "\n";
}

template<typename T>
size_t List<T>::getTotalSize()
{
	node<T>* tmp = start;
	size_t size = 0;
	while (tmp != nullptr)
	{
		size += tmp->size;
		tmp = tmp->next;
	}
	return size;
}



