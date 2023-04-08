#include "CSSReader.h"
#include "List.cpp"
#include "pair.cpp"
#include "vector.cpp"
#define CURRENT_ACTIVE_SECTION_FLAG -69


List<Section, BLOCK_SIZE> CSSReader::sections;

CSSReader::CSSReader()
{
	sections.add();
}

void CSSReader::read()
{
	//TODO: think about isEOF func?
	bool isEOF = false;
	while (!isEOF)
	{
		int ch = getchar();
		if (ch == EOF)
		{
			isEOF = true;
		}

		if (isCommandBlockActive(ch))
			commandHandler.readCommand(ch);
		else
			sectionHandler.readSection(ch);
	}
}

CSSReader& CSSReader::get()
{
	static CSSReader cssReader;
	return cssReader;
}

void skipNCharacters(int n)
{
	for (int i = 0; i < n; i++)
		getchar();
}

int CSSReader::readCharAfterBlockSeparator(int& ch)
{
	skipNCharacters(4);
	return getchar();
}

bool CSSReader::isStartOfCommandBlock(char ch)
{
	int FLAG = CURRENT_ACTIVE_SECTION_FLAG;
	return ch == '?' && isCommandBlockActive(FLAG) == false;
}

bool CSSReader::isEndOfCommandBlock(char ch)
{
	return ch == '*' && sectionHandler.input.trim().isEmpty();
}

bool CSSReader::isCommandBlockActive(int& ch)
{
	static bool isActive = false;
	if (ch == CURRENT_ACTIVE_SECTION_FLAG)
	{
		return isActive;
	}

	if (isStartOfCommandBlock(ch))
	{
		ch = readCharAfterBlockSeparator(ch);
		isActive = true;
	}
	else if (isEndOfCommandBlock(ch))
	{
		ch = readCharAfterBlockSeparator(ch);
		isActive = false;
	}
	
	return isActive;
}