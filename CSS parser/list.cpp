#include "list.h"
#include <iostream>

template<typename T>
List<T>::List()
	: start(nullptr), end(nullptr), blocksCount(0) {}

template<typename T>
List<T>::~List()
{
	if (blocksCount == 0)
		return;
	else if (blocksCount == 1)
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
	if (blocksCount == 0)
	{
		node<T>* tmp = new node<T>;
		start = tmp;
		end = tmp;
		blocksCount++;
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
			blocksCount++;
		}
	}
}


template<typename T>
T& List<T>::operator[](size_t index)
{
	if (index < 0 || index > getSize() - 1)
		throw "out of bounds!";
	node<T>* tmp = start;
	while (index >= 0)
	{
		if (tmp->findMappedIndex(index) == -1 && tmp->next != nullptr)
		{
			index -= tmp->size;
			tmp = tmp->next;
		}
		else
			return (*tmp)[index % N];
	}
}

template<typename T>
void List<T>::pop()
{
	if (blocksCount == 0 || start->size == 0)
		throw "list is empty!";
	deleteEmptyNode(end);
	end->pop();
}

template<typename T>
void List<T>::pop(size_t index)
{
	if (index < 0 || index > getSize() - 1)
		throw "out of bounds!";
	node<T>* tmp = start;
	while (index >= 0)
	{
		if (tmp->findMappedIndex(index) == -1 && tmp->next != nullptr)
		{
			index -= tmp->size;
			tmp = tmp->next;
		}
		else
		{
			(*tmp).filled[tmp->findMappedIndex(index % N)] = false;
			tmp->size--;
			deleteEmptyNode(tmp);
			return;
		}
	}
}

template<typename T>
void List<T>::print()
{
	for (int i = 0; i < getSize(); i++)
		std::cout << (*this)[i] << " ";
	std::cout << "\n";
}

template<typename T>
void List<T>::deleteEmptyNode(node<T>* emptyNode)
{
	if (emptyNode->size == 0)
	{
		if (blocksCount == 1)
		{
			delete emptyNode;
			emptyNode = nullptr;
			start = nullptr;
		}
		else if (emptyNode->next == nullptr) // end of list
		{
			node<T>* tmp = emptyNode->prev;
			delete emptyNode;
			tmp->next = nullptr;
			end = tmp;
		}
		else if (emptyNode->prev == nullptr) // start of list
		{
			node<T>* tmp = emptyNode->next;
			delete emptyNode;
			tmp->prev = nullptr;
			start = tmp;
		}
		else // in the middle
		{
			node<T>* next = emptyNode->next;
			node<T>* prev = emptyNode->prev;
			delete emptyNode;
			next->prev = prev;
			prev->next = next;
		}
		blocksCount--;
	}
}

template<typename T>
size_t List<T>::getSize()
{
	node<T>* tmp = start;
	size_t blocksCount = 0;
	while (tmp != nullptr)
	{
		blocksCount += tmp->size;
		tmp = tmp->next;
	}
	return blocksCount;
}



