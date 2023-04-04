#include <iostream>

#include "string.h"
#include "vector.h"
#include "vector.cpp"
#include "pair.h"
#include "pair.cpp"

#include "list.h"
#include "list.cpp"

using std::cout;
using std::endl;

void listTest();

int main()
{
	listTest();
}

void listTest()
{
	List<int> a;
	a.add(new node<int>(1));
	a.add(new node<int>(2));
	a.add(new node<int>(3));
	a.add(new node<int>(4));
	a.print();
	a.pop();
	a.print();
	a.add();
	a[a.size - 1] = 69;
	a.print();
}
