#pragma once
#include<iostream>
#define N 8

template<typename T>
class node
{
public:
	node* prev = nullptr;
	node* next = nullptr;
	T items[N];
	size_t size = 0;

	void add(const T& item) 
	{
		if (size < N)
		{
			items[size] = item;
			size++;
		}
		else
			throw "items are full!";
	};
	T& operator[] (size_t index) 
	{ 
		if (index >= N)
			throw "out of bounds!";
		return items[index];
	}
	void pop()
	{
		size--;
	}
	node() {};
};

template<typename T>
class List
{
	
	node<T>* start;
	node<T>* end;
	size_t size;

public:

	List();
	~List();

	size_t getTotalSize();
	void add();
	void add(const T& item);
	void pop();
	T& operator[] (size_t index);
	void print();
};

