#include "CommandHandler.h"
#include "vector.h"
#include "vector.cpp"
#include "string.h"
#include "List.h"
#include "List.cpp"
#include "Section.h"
#include "algorithm.h"
#include "CSSReader.h"

#define SUB 26

const int CommandHandler::INDEX_OFFSET = -1;
string CommandHandler::command = "";

CommandHandler::CommandHandler()
	: sections(CSSReader::sections) {}

void CommandHandler::readCommand(int ch)
{
	command = readCommandLine(ch).trim();
	if (command == '?')
	{
		cout << "? == " << sections.getSize() << endl;
	}
	else if(!isCommandEmpty())
	{
		vector<string> params = command.split(',');
		chooseCommand(params);
	}
	command.clear();
}

void CommandHandler::chooseCommand(vector<string>& params)
{
	for (int i = 0; i < params.size(); i++)
		params[i] = params[i].trim();
	char type = params[1][0];

	switch (type)
	{
	case 'A':
		ACommandHandler.chooseCommand(params, command);
		break;
	case 'S':
		SCommandHandler.chooseCommand(params, command);
		break;
	case 'E':
		ZCommandHandler.chooseCommand(params, command);
		break;
	case 'D':
		DCommandHandler.chooseCommand(params, command);
		break;
	}
}


string CommandHandler::readCommandLine(int ch)
{
	if (isInvalidCharacter(ch))
		return "";

	string command;
	while (ch != '\n')
	{
		if (ch == EOF || ch == SUB)
		{
			ungetc(ch, stdin);
			return command;
		}
		command += char(ch);
		ch = getchar();
	}
	return command;
}

bool CommandHandler::isCommandEmpty()
{
	for (int i = 0; i < command.size(); i++)
		if (!isspace(command[i]))
			return false;
	return true;
}

bool CommandHandler::isInvalidCharacter(int ch)
{
	return (ch < ' ' && !isspace(ch));
}

