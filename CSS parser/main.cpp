#include <iostream>

#include "string.h"
#include "vector.h"
#include "vector.cpp"
#include "pair.h"
#include "pair.cpp"

#include "List.h"
#include "List.cpp"
#include "Section.h"
#include "SectionHandler.h"

using std::cout;
using std::endl;

class CSSReader
{

public:

	List<Section, BLOCK_SIZE> sections;
	SectionHandler sectionHandler;
	
	bool isCommandBlockActive = false;

	CSSReader()
		: sectionHandler(&sections)
	{
		sections.add();
	}
	
	void read()
	{
		while (true)
		{
			int ch = getchar();
			if (ch == EOF)
				return;
			else if (ch == '?')
				isCommandBlockActive = true;

			if (isCommandBlockActive)
				readCommands(ch);
			else
				sectionHandler.readSection(ch);
		}
	}
	void readCommands(int ch)
	{
		// TODO: add commands handling
	}
	

};

int main()
{
	CSSReader reader;
	reader.read();
	cout << reader.sections;
}

/*
a {
c: (a, b);
d: (a1, b1);
e: (a2, b2)
}

{
c: (a, b); d: (a1, b1); c: (a2, b2)
}

abc, dce 
{ 
color: 1px, 2px, 3px;
text: "cos"
}

abc, dce
{
color: 1px, 2px, 3px; text: "cos"; color: that
}



#breadcrumb
{
width: 80%;
font-size: 9pt;
}

h1, body {
min-width: 780px;
margin: 0;
padding: 0;
font-family: "Trebuchet MS", "Lucida Grande", Arial;
font-size: 85%;
color: #666666;
}
h1, h2, h3, h4, h5, h6 {color: #0066CB;}


*/