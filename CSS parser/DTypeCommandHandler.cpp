#include "DTypeCommandHandler.h"
#include "CSSReader.h"
#include "CommandHandler.h"
#include "STypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

DTypeCommandHandler::DTypeCommandHandler()
	: sections(CSSReader::sections), command(CommandHandler::command) {}


void DTypeCommandHandler::chooseCommand(const vector<string>& params)
{
	if (params[2] == '*')
		iDq(sbl::stoi(params[0]));
	else
		iDn(sbl::stoi(params[0]), params[2]);
	command.clear();
}

void DTypeCommandHandler::iDq(int i)
{
	i += CommandHandler::INDEX_OFFSET;
	try {
		sections.pop(i);
		cout << command;
		cout << " == deleted" << endl;
	}
	catch (...) {}
}

void DTypeCommandHandler::iDn(int i, const string& n)
{
	i += CommandHandler::INDEX_OFFSET;
	try {
		sections[i].attributes.pop(sections[i].findAtrIndex(n));
		if (sections[i].attributes.isEmpty())
			sections.pop(i);
		cout << command;
		cout << " == deleted" << endl;
	}
	catch (...) {}
}