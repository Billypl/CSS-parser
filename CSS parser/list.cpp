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
	node<T>* tmp = start->next;
	do
	{
		delete start;
		start = tmp;
		tmp = start->next;
	} while (tmp->next != nullptr);

}

template<typename T>
void List<T>::add()
{
	add(new node<T>);
}
template<typename T>
void List<T>::add(node<T>* item)
{
	node<T>* tmp = item;
	if (size != 0)
	{
		end->next = tmp;
		tmp->prev = end;
	}
	else
		start = tmp;

	end = tmp;
	size++;
}


template<typename T>
T& List<T>::operator[](size_t index)
{
	node<T>* tmp = start;
	for (int i = 0; i < index; i++)
	{
		tmp = tmp->next;
		if (tmp == nullptr)
			throw "no node found!";
	}
	return tmp->item;
}

template<typename T>
void List<T>::pop()
{
	if (size == 0)
		throw "list is empty!";
	else if (size == 1)
	{
		delete end;
		end = nullptr;
		start = nullptr;
	}
	node<T>* tmp = end->prev;
	delete end;
	tmp->next = nullptr;
	end = tmp;
	size--;
}



template<typename T>
void List<T>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << (*this)[i] << " ";
	std::cout << "\n";
}



