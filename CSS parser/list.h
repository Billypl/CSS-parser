#pragma once
#include <iostream>
#include "node.h"
#include "node.cpp"

template<typename T>
class List
{
	node<T>* start;
	node<T>* end;
	size_t blocksCount;

public:

	List();
	~List();

	size_t getSize();
	void add();
	void add(const T& item);
	void pop();
	void pop(size_t index);
	T& operator[] (size_t index);
	void print();

private:

	void deleteEmptyNode(node<T>* emptyNode);
};

