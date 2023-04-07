#include "CSSReader.h"
#include "CommandHandler.h"
#include "ATypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

using std::cout;
using std::endl;

ATypeCommandHandler::ATypeCommandHandler()
	: sections(CSSReader::sections) {}

void ATypeCommandHandler::chooseCommand(const vector<string>& params, const string& command)
{
	try 
	{
		string result;
		if (params[2] == '?')
		{
			int i = sbl::stoiBool(params[0]);
			if (i <= -1)
				result = nAq(params[0]);
			else
				result = iAq(i);
		}
		else
			result = iAn(sbl::stoi(params[0]), params[2]);
		cout << command << " == " << result << endl;
	}
	catch(...) {}
}

int ATypeCommandHandler::iAq(int i)
{
	i += CommandHandler::INDEX_OFFSET;
	return sections[i].attributes.getSize();
}

string ATypeCommandHandler::iAn(int i, const string& n)
{
	i += CommandHandler::INDEX_OFFSET;
	return sections[i].findAtr(n).value;
}

int ATypeCommandHandler::nAq(const string& n)
{
	int atrCount = 0;
	// TODO: fix performance 
	// (because of list nature iterating through it using index is slooow)
	for (int i = 0; i < sections.getSize(); i++)
	{
		Section s = sections[i]; 
		if (s.findAtrIndex(n) < s.attributes.getSize())
			atrCount++;
	}
	return atrCount;
}

