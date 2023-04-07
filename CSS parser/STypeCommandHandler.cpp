#include "CSSReader.h"
#include "CommandHandler.h"
#include "STypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

using std::cout;
using std::endl;

STypeCommandHandler::STypeCommandHandler()
	: sections(CSSReader::sections), command(CommandHandler::command) {}

void STypeCommandHandler::chooseCommand(const vector<string>& params)
{
	if (params[2] == '?')
	{
		int i = sbl::stoiBool(params[0]);
		if (i <= -1)
			zSq(params[0]);
		else
			iSq(i);
	}
	else
		iSj(sbl::stoi(params[0]),
			sbl::stoi(params[2]));
}

void STypeCommandHandler::iSq(int i)
{
	i += CommandHandler::INDEX_OFFSET;
	try {
		int size = sections[i].selectors.getSize();
		cout << command << " == ";
		cout << size << endl;
	}
	catch (...) {}
}


void STypeCommandHandler::iSj(int i, int j)
{
	i += CommandHandler::INDEX_OFFSET;
	j += CommandHandler::INDEX_OFFSET;
	try {
		string name = sections[i].selectors[j];
		if (name.isEmpty())
			return;
		cout << command << " == ";
		cout << name << endl;
	}
	catch (...) {}
}



void STypeCommandHandler::zSq(const string& z)
{
	int selCount = 0;
	// TODO: fix performance 
	// (because of list nature iterating through it using index is slooow)
	for (int i = 0; i < sections.getSize(); i++)
	{
		//Section s = sections[i]; // cause of crash (but s ???? n,A,? **** s ???? n,A,? -> crash)
		Section s = sections[i];
		if (sections[i].findSelIndex(z) < sections[i].selectors.getSize())
			selCount++;
	}
	cout << command << " == ";
	cout << selCount << endl;
}