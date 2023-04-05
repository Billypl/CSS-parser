#include <iostream>

#include "string.h"
#include "vector.h"
#include "vector.cpp"
#include "pair.h"
#include "pair.cpp"

#include "List.h"
#include "List.cpp"
#include "Section.h"

using std::cout;
using std::endl;

void listTest();
void sectionsTest();

int main()
{
	//listTest();
	sectionsTest();

}

void sectionsTest()
{
	List<Section, BLOCK_SIZE> a;
	a.add();
	a[0].attributes.add({ "test", "lol" });
	a[0].selectors.add("dziala?");
	cout << a;
}


void listTest()
{
	List<int, BLOCK_SIZE> a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);

	a.pop();
	a.pop();

	//a.pop(a.getSize() - 1);
	//a.print();
	cout << a;
}
