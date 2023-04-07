#include "CSSReader.h"
#include "List.cpp"
#include "pair.cpp"
#include "vector.cpp"


List<Section, BLOCK_SIZE> CSSReader::sections;

CSSReader::CSSReader()
{
	sections.add();
}

void CSSReader::read()
{
	while (true)
	{
		int ch = getchar();
		if (ch == EOF)
			return;
		else if (isStartOfCommandBlock(ch))
		{
			readInputSeparator(ch);
			isCommandBlockActive = true;
		}
		else if (isEndOfCommandBlock(ch))
		{
			readInputSeparator(ch);
			isCommandBlockActive = false;
		}

		if (isCommandBlockActive)
			commandHandler.readCommands(ch);
		else
			sectionHandler.readSection(ch);
	}
}

void CSSReader::readInputSeparator(int& ch)
{
	getchar();
	getchar();
	getchar();
	ch = getchar();
}

bool CSSReader::isStartOfCommandBlock(char ch)
{
	return ch == '?' && isCommandBlockActive == false;
}

bool CSSReader::isEndOfCommandBlock(char ch)
{
	return ch == '*' && sectionHandler.input.trim().isEmpty();
}
