#pragma once
#include <iostream>
#include "Node.h"
#include "Node.cpp"
#include <array>

template<typename T, size_t B_SIZE>
class List
{
	Node<T, B_SIZE>* start;
	Node<T, B_SIZE>* end;
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

	void deleteEmptyNode(Node<T, B_SIZE>* emptyNode);
};

