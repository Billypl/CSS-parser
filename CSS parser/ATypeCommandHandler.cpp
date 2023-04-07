#include "CSSReader.h"
#include "CommandHandler.h"
#include "ATypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

using std::cout;
using std::endl;

ATypeCommandHandler::ATypeCommandHandler()
	: sections(CSSReader::sections), command(CommandHandler::command) {}

void ATypeCommandHandler::chooseCommand(const vector<string>& params)
{
	this->command = command;
	if (params[2] == '?')
	{
		int i = sbl::stoiBool(params[0]);
		if (i <= -1)
			nAq(params[0]);
		else
			iAq(i);
	}
	else
		iAn(sbl::stoi(params[0]), params[2]);
}

void ATypeCommandHandler::iAq(int i)
{
	i += CommandHandler::INDEX_OFFSET;
	try {
		int size = sections[i].attributes.getSize();
		cout << command << " == ";
		cout << size << endl;
	}
	catch (...) {}
}

void ATypeCommandHandler::iAn(int i, const string& n)
{
	i += CommandHandler::INDEX_OFFSET;
	try {
		string value = sections[i].findAtr(n).value;
		cout << command << " == ";
		cout << value << endl;
	}
	catch (...) {}
}

void ATypeCommandHandler::nAq(const string& n)
{
	int atrCount = 0;
	// TODO: fix performance 
	// (because of list nature iterating through it using index is slooow)
	for (int i = 0; i < sections.getSize(); i++)
	{
		//Section s = sections[i]; // cause of crash (but s ???? n,A,? **** s ???? n,A,? -> crash)
		if (sections[i].findAtrIndex(n) < sections[i].attributes.getSize())
			atrCount++;
	}
	cout << command << " == ";
	cout << atrCount << endl;
}

