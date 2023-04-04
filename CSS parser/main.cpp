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
	a.add(1);
	a.add(1);
	cout << a[0];
	cout << a[1];
	cout << a[2];
	//a.add(1);
	//a.add(1);
	//a.add(1);
	//a.add(1);
	//a.add(1);
	//a.add(1);
	//a.add(2);
	//a.pop();
	//a.pop();
	//a.pop();
	//a.print();
}
