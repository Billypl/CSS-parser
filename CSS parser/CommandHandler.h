#pragma once

#include "string.h"
#include "List.h"
#include "Section.h"
#include "ATypeCommandHandler.h"
#include "STypeCommandHandler.h"
#include "DTypeCommandHandler.h"

using std::cout;
using std::endl;

class CommandHandler
{

public:

	List<Section, BLOCK_SIZE>& sections;
	static string command;
	static const int INDEX_OFFSET;

	ATypeCommandHandler ACommandHandler;
	STypeCommandHandler SCommandHandler;
	DTypeCommandHandler DCommandHandler;

	CommandHandler();

	void readCommands(int ch);

private:

	// value of atr named "n" for sel named "z"
	void zEn(const string& z, const string& n);

	void readCommandLine(int ch);
	bool isEmpty(const string& str);

	bool isInvalidCharacter(int ch);


};

