#pragma once
#include<iostream>

template<typename T>
class node
{
public:
	node* prev = nullptr;
	node* next = nullptr;

	T item;
	node(T item) : item(item) {};
	node() {};
};

template<typename T>
class List
{
public:
	
	node<T>* start;
	node<T>* end;
	size_t size;

	List();
	~List();

	void add();
	void add(node<T>* item);
	void pop();
	T& operator[] (size_t index);
	void print();
};

