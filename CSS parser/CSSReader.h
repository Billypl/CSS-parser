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

	void read();
	static CSSReader& get();

private:

	SectionHandler sectionHandler;
	CommandHandler commandHandler;

	CSSReader();
	int readCharAfterBlockSeparator(int& ch);
	bool isStartOfCommandBlock(char ch);
	bool isEndOfCommandBlock(char ch);

	bool isCommandBlockActive(int& ch);

};

