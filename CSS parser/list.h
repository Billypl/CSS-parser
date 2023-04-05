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

	size_t getSize() const;
	void add();
	void add(const T& item);
	void pop();
	void pop(size_t index);

	T& get(size_t index);
	T& operator[] (size_t index);
	const T& operator[] (size_t index) const;
	void operator=(const List& other);
	
	void print() const;
	bool isEmpty(); 
	void erease();

	template<typename T, size_t B_SIZE>
	friend std::ostream& operator<<(std::ostream& os, const List<T, BLOCK_SIZE>& list);

private:

	void deleteEmptyNode(Node<T, B_SIZE>* emptyNode);
};

