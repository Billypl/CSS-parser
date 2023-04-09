#include "ListIterator.h"
#include "List.h"

template<typename List>
ListIterator<List>& ListIterator<List>::operator++()

{
	if (ptr != &(nodePtr->getLast()) ||
		(ptr == &(nodePtr->getLast()) && nodePtr->next == nullptr))
	{
		ptr++;
	}
	else
	{
		nodePtr = nodePtr->next;
		ptr = &(*nodePtr)[0];
	}
	return *this;
}

template<typename List>
ListIterator<List> ListIterator<List>::operator++(int)
{
	ListIterator iterator = *this;
	++(*this);
	return iterator;
}

template<typename List>
ListIterator<List>& ListIterator<List>::operator--()
{
	if (ptr == &(*nodePtr)[0])
	{
		nodePtr = nodePtr->prev;
		ptr = &(nodePtr->getLast());
	}
	else
	{
		ptr--;
	}
	return *this;
}

template<typename List>
ListIterator<List> ListIterator<List>::operator--(int)
{
	ListIterator iterator = *this;
	--(*this);
	return iterator;
}

template<typename List>
bool ListIterator<List>::operator==(const ListIterator& other) const
{
	return ptr == other.ptr;
}

template<typename List>
bool ListIterator<List>::operator!=(const ListIterator& other) const
{
	return !((*this) == other);
}

template<typename List>
typename ListIterator<List>::ReferenceType ListIterator<List>::operator*()
{
	return *ptr;
}

template<typename List>
typename ListIterator<List>::PointerType ListIterator<List>::operator->()
{
	return ptr;
}
