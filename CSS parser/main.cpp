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

Section createSection();
Section createSection2();

void sectionsTest()
{
	List<Section, BLOCK_SIZE> a;

	a.add(createSection());
	a.add(createSection2());

	int i = 0,j = 0;
	cout << "First: " << a[i].attributes[j].name << endl << endl;
	cout << "Print whole list:\n" << " " << a;
}

Section createSection()
{
	Section res;

	res.selectors.add("s1");
	res.attributes.add({ "test1", "lol1" });
	res.attributes.add({ "test2", "lol2" });
	return res;
}
Section createSection2()
{
	Section res;

	res.selectors.add("s2");
	res.attributes.add({ "test3", "lol3" });
	res.attributes.add({ "test4", "lol4" });
	return res;
}


void listTest()
{
	List<int, BLOCK_SIZE> a, b;
	a.add(1);
	a.add(2);
	b = a;

	//a.pop(a.getSize() - 1);
	//a.print();
	cout << a << endl;
	cout << b;
}
