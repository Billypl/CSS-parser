#include "CSSReader.h"
#include "CommandHandler.h"
#include "ZTypeCommandHandler.h"
#include "vector.cpp"
#include "list.cpp"

using std::cout;
using std::endl;

ZTypeCommandHandler::ZTypeCommandHandler()
	: sections(CSSReader::sections) {}

void ZTypeCommandHandler::chooseCommand(const vector<string>& params, const string& command)
{
	try {
		string result = zEn(params[0], params[2]);
		cout << command << " == " << result << endl;
	}
	catch(...) {}
}

string ZTypeCommandHandler::zEn(const string& z, const string& n)
{
	// TODO: fix performance 
	// (because of list nature iterating through it using index is slooow)
	for (int i = sections.getSize() - 1; i >= 0; i--)
	{
		if (sections[i].findSelIndex(z) < sections[i].selectors.getSize())
		{
			if (sections[i].findAtrIndex(n) < sections[i].attributes.getSize())
			{
				return sections[i].findAtr(n).value;
			}
		}
	}
	throw "No value found!";
}