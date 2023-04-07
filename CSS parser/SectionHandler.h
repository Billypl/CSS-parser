#pragma once
#include "List.h"
#include "string.h"
#include "Section.h"

class SectionHandler
{

	List<Section, BLOCK_SIZE>& sections;
	bool isSectionStarted = false;
	bool isSectionEnded = false;

public:

	SectionHandler();
	string input = "";
	void readSection(int ch);

private:

	static bool isInvalidCharacter(int ch);
	static bool isSectionEnding(int ch);

	void saveSelector(int ch);
	void saveAttribute();
	
	static bool isEmpty(const string& str);
};

