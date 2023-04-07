#include <iostream>
#include "CSSReader.h"


using std::cout;
using std::endl;


int main()
{
	CSSReader reader;
	reader.read();
	//cout << reader.sections;
}



/*

abc{a: d;}
d{c: 2;}

????
?
2,D,c
****
ccc{k: m;}



*/