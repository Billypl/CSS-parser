#include <iostream>
#include "CSSReader.h"
#include "List.h"
#include "List.cpp"

using std::cout;
using std::endl;


int main()
{
	//CSSReader::get().read();
	List<int, 3> a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.add(6);
	a.add(7);

	/*it++;
	cout << (it != a.end())  << " | " << * it;*/
	for (auto& it : a)
	{
		cout << it;
	}

}



/*

abc{a: d;}
d{c: 2;}
{
n: 39;
}

????
?
2,D,c
****
ccc{k: m;}



*/