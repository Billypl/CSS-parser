#pragma once
#define N 2


template<typename T>
class node
{
public:
	node* prev = nullptr;
	node* next = nullptr;
	T items[N];
	bool filled[N];
	size_t size = 0;

	size_t findLastFilledIndex();

	void add(const T& item);
	T& operator[] (size_t index);
	void pop();
	node();

	size_t findMappedIndex(size_t index);

};

