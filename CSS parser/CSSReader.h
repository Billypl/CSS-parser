#pragma once
#include "string.h"
#include "vector.h"
#include "pair.h"

#include "List.h"
#include "Section.h"
#include "SectionHandler.h"
#include "CommandHandler.h"

class CSSReader
{

public:

	static List<Section, BLOCK_SIZE> sections;
	SectionHandler sectionHandler;
	CommandHandler commandHandler;

	bool isCommandBlockActive = false;

	CSSReader();

	void read();

private:

	void readInputSeparator(int& ch);
	bool isStartOfCommandBlock(char ch);
	bool isEndOfCommandBlock(char ch);

};

