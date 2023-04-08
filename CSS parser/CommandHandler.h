#pragma once

#include "string.h"
#include "List.h"
#include "Section.h"
#include "ATypeCommandHandler.h"
#include "STypeCommandHandler.h"
#include "DTypeCommandHandler.h"
#include "ZTypeCommandHandler.h"

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
	ZTypeCommandHandler ZCommandHandler;

	CommandHandler();

	void readCommand(int ch);

private:

	void chooseCommand(vector<string>& params);
	string readCommandLine(int ch);
	bool isCommandEmpty();

	bool isInvalidCharacter(int ch);


};

