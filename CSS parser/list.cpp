#include "List.h"
#include <iostream>

template<typename T, size_t B_SIZE>
List<T, B_SIZE>::List()
	: start(nullptr), end(nullptr), blocksCount(0) {}

template<typename T, size_t B_SIZE>
List<T, B_SIZE>::~List()
{
	if (blocksCount == 0)
		return;
	else if (blocksCount == 1)
	{
		delete end;
		return;
	}

	Node<T, B_SIZE>* tmp = start->next;
	do
	{
		delete start;
		start = tmp;
		tmp = tmp->next;
	} while (tmp != nullptr);

}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::add()
{
	T item;
	add(item);
}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::add(const T& item)
{
	if (blocksCount == 0)
	{
		Node<T, B_SIZE>* tmp = new Node<T, B_SIZE>;
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
			Node<T, B_SIZE>* tmp = new Node<T, B_SIZE>;
			end->next = tmp;
			tmp->prev = end;

			end = tmp;
			blocksCount++;
		}
	}
}


template<typename T, size_t B_SIZE>
T& List<T, B_SIZE>::operator[](size_t index)
{
	return get(index);
}

template<typename T, size_t B_SIZE>
const T& List<T, B_SIZE>::operator[](size_t index) const
{
	return const_cast<List*>(this)->get(index);
}

template<typename T, size_t B_SIZE>
T& List<T, B_SIZE>::get(size_t index)
{
	if (index > getSize() - 1)
		throw "out of bounds!";
	Node<T, B_SIZE>* tmp = start;
	while (index >= 0)
	{
		if (tmp->findMappedIndex(index) == -1 && tmp->next != nullptr)
		{
			index -= tmp->size;
			tmp = tmp->next;
		}
		else
			return (*tmp)[index % B_SIZE];
	}
}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::pop()
{
	if (blocksCount == 0 || start->size == 0)
		throw "list is empty!";
	deleteEmptyNode(end);
	end->pop();
}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::pop(size_t index)
{
	if (index > getSize() - 1)
		throw "out of bounds!";
	Node<T, B_SIZE>* tmp = start;
	while (index >= 0)
	{
		if (tmp->findMappedIndex(index) == -1 && tmp->next != nullptr)
		{
			index -= tmp->size;
			tmp = tmp->next;
		}
		else
		{
			(*tmp).filled[tmp->findMappedIndex(index % B_SIZE)] = false;
			tmp->size--;
			deleteEmptyNode(tmp);
			return;
		}
	}
}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::print() const
{
	for (int i = 0; i < getSize(); i++)
		std::cout << (*this)[i] << " ";
	std::cout << "\n";
}

template<typename T, size_t B_SIZE>
bool List<T, B_SIZE>::isEmpty()
{
	return getSize() == 0;
}

template<typename T, size_t B_SIZE>
void List<T, B_SIZE>::deleteEmptyNode(Node<T, B_SIZE>* emptyNode)
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
			Node<T, B_SIZE>* tmp = emptyNode->prev;
			delete emptyNode;
			tmp->next = nullptr;
			end = tmp;
		}
		else if (emptyNode->prev == nullptr) // start of list
		{
			Node<T, B_SIZE>* tmp = emptyNode->next;
			delete emptyNode;
			tmp->prev = nullptr;
			start = tmp;
		}
		else // in the middle
		{
			Node<T, B_SIZE>* next = emptyNode->next;
			Node<T, B_SIZE>* prev = emptyNode->prev;
			delete emptyNode;
			next->prev = prev;
			prev->next = next;
		}
		blocksCount--;
	}
}

template<typename T, size_t B_SIZE>
size_t List<T, B_SIZE>::getSize() const
{
	Node<T, B_SIZE>* tmp = start;
	size_t size = 0;
	while (tmp != nullptr)
	{
		size += tmp->size;
		tmp = tmp->next;
	}
	return size;
}

template<typename T, size_t B_SIZE>
std::ostream& operator<<(std::ostream& os, const List<T, B_SIZE>& list)
{
	list.print();
	return os;
}
