#include "CSSReader.h"
#include "CommandHandler.h"
#include "STypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

using std::cout;
using std::endl;

STypeCommandHandler::STypeCommandHandler()
	: sections(CSSReader::sections), command(CommandHandler::command) {}

void STypeCommandHandler::chooseCommand(const vector<string>& params, const string& command)
{
	try 
	{
		string result;
		if (params[2] == '?')
		{
			int i = sbl::stoiBool(params[0]);
			if (i <= -1)
				result = zSq(params[0]);
			else
				result = iSq(i);
		}
		else
			result = iSj(sbl::stoi(params[0]), sbl::stoi(params[2]));
		cout << command << " == " << result << endl;
	}
	catch (...) {}
}

int STypeCommandHandler::iSq(int i)
{
	i += CommandHandler::INDEX_OFFSET;
	return sections[i].selectors.getSize();
}


string STypeCommandHandler::iSj(int i, int j)
{
	i += CommandHandler::INDEX_OFFSET;
	j += CommandHandler::INDEX_OFFSET;
	string name = sections[i].selectors[j];
	if (name.isEmpty())
		throw "Section is empty";
	return name;
}



int STypeCommandHandler::zSq(const string& z)
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
	return selCount;
}