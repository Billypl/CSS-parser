#include "CommandHandler.h"
#include "vector.h"
#include "vector.cpp"
#include "string.h"
#include "List.h"
#include "List.cpp"
#include "Section.h"
#include "algorithm.h"
#include "CSSReader.h"

const int CommandHandler::INDEX_OFFSET = -1;
string CommandHandler::command = "";

CommandHandler::CommandHandler()
	: sections(CSSReader::sections) {}

void CommandHandler::readCommands(int ch)
{
	if (isInvalidCharacter(ch))
		return;
	readCommandLine(ch);

	if (isEmpty(command))
	{
		return;
	}
	else if (command.trim() == '?')
	{
		cout << "? == " << sections.getSize() << endl;
	}
	else
	{
		command = command.trim();
		vector<string> params = command.split(',');
		char type = params[1][0];
		params[0] = params[0].trim();
		params[1] = params[1].trim();
		params[2] = params[2].trim();

		switch (type)
		{
		case 'A':
			ACommandHandler.chooseCommand(params, command);
			break;
		case 'S':
			SCommandHandler.chooseCommand(params, command);
			break;
		case 'E':
			zEn(params[0], params[2]);
			break;
		case 'D':
			DCommandHandler.chooseCommand(params, command);
			break;
		default:
			command.clear();
			break;
		}
	}
	command.clear();

}



void CommandHandler::zEn(const string& z, const string& n)
{
	// TODO: fix performance 
	// (because of list nature iterating through it using index is slooow)
	for (int i = sections.getSize() - 1; i >= 0; i--)
	{
		if (sections[i].findSelIndex(z) < sections[i].selectors.getSize())
		{
			if (sections[i].findAtrIndex(n) < sections[i].attributes.getSize())
			{
				cout << command << " == ";
				cout << sections[i].findAtr(n).value << endl;
				return;
			}
		}
	}
}


void CommandHandler::readCommandLine(int ch)
{
	if (ch == '\n')
		return;
	do {
		if (ch == EOF || ch == 26)
		{
			//TODO: make it prettier?
			ungetc(ch, stdin);
			return;
		}
		command += char(ch);
	} while ((ch = getchar()) != '\n');
}

bool CommandHandler::isEmpty(const string& str)
{
	for (int i = 0; i < str.size(); i++)
		if (!isspace(str[i]))
			return false;
	return true;
}

bool CommandHandler::isInvalidCharacter(int ch)
{
	return (ch < ' ' && !isspace(ch));
}