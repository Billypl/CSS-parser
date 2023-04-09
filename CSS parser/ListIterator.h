#pragma once

template<typename List>
class ListIterator
{

public:

	using ValueType = typename List::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

	using ValueNodeType = typename List::NodeType;
	using PointerNodeType = ValueNodeType*;
	using ReferenceNodeType = ValueNodeType&;

public:

	ListIterator(PointerNodeType nodePtr, PointerType ptr)
		: nodePtr(nodePtr), ptr(ptr) {}

	ListIterator& operator++();
	ListIterator operator++(int);
	ListIterator& operator--();
	ListIterator operator--(int);

	bool operator==(const ListIterator& other) const;
	bool operator!=(const ListIterator& other) const;
	ReferenceType operator*();
	PointerType operator->();

private:

	PointerType ptr;
	PointerNodeType nodePtr;

};

