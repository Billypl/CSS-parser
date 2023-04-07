#include <iostream>

#include "string.h"
#include "vector.h"
#include "vector.cpp"
#include "pair.h"
#include "pair.cpp"
#include "algorithm.h"

#include "List.h"
#include "List.cpp"
#include "Section.h"
#include "SectionHandler.h"

using std::cout;
using std::endl;

class CSSReader
{

public:

	List<Section, BLOCK_SIZE> sections;
	SectionHandler sectionHandler;
	
	bool isCommandBlockActive = false;
	bool isDeletedSuccessful = false;
	bool isFileEnded = false;
	string command = "";
	const int INDEX_OFFSET = -1;

	CSSReader()
		: sectionHandler(&sections)
	{
		sections.add();
	}
	
	void read()
	{
		while (true)
		{
			if (isFileEnded)
				return;
			int ch = getchar();
			if (ch == EOF || isFileEnded)
				return;
			else if (isStartOfCommandBlock(ch))
			{
				readInputSeparator(ch);
				isCommandBlockActive = true;
			}
			else if (isEndOfCommandBlock(ch))
			{
				readInputSeparator(ch);
				isCommandBlockActive = false;
			}

			if (isCommandBlockActive)
				readCommands(ch);
			else
				sectionHandler.readSection(ch);
		}
	}
	void readInputSeparator(int& ch)
	{
		getchar();
		getchar();
		getchar();
		ch = getchar();
	}
	bool isStartOfCommandBlock(char ch)
	{
		return ch == '?' && isCommandBlockActive == false;
	}
	bool isEndOfCommandBlock(char ch)
	{
		return ch == '*' && sectionHandler.input.trim().isEmpty();
	}

	void readCommands(int ch)
	{
		if (isInvalidCharacter(ch))
			return;
		readCommandLine(ch);

		if (isEmpty(command))
		{
			command.clear();
			return;
		}
		else if (command.trim() == '?')
		{
			cout << "? == " << sections.getSize() << endl;
			command.clear();
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
				chooseATypeCommand(params);
				break;
			case 'S':
				chooseSTypeCommand(params);
				break;
			case 'E':
				zEn(params[0], params[2]);
				break;
			case 'D':
				chooseDTypeCommand(params);
				break;
			default:
				command.clear();
				break;
			}
			command.clear();
		}
	}
	void chooseATypeCommand(const vector<string>& params)
	{
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

	// count of atrs in section "i" (skip if not)
	void iAq(int i) 
	{
		i += INDEX_OFFSET;
		try {
			int size = sections[i].attributes.getSize();
			cout << command << " == ";
			cout << size << endl;
		} catch (...) {}
	}
	// value of atr named "n" for section "i" (skip if not)
	void iAn(int i, const string& n)
	{
		i += INDEX_OFFSET;
		try {
			string value = sections[i].findAtr(n).value;
			cout << command << " == ";
			cout << value << endl;
		}
		catch (...) {}
	}
	// count of atr named "n" across all sections
	void nAq(const string& n)
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

	void chooseSTypeCommand(const vector<string>& params)
	{
		if (params[2] == '?')
		{
			int i = sbl::stoiBool(params[0]);
			if(i <= -1)
				zSq(params[0]);
			else
				iSq(i);
		}
		else
			iSj(sbl::stoi(params[0]), 
				sbl::stoi(params[2]));
	}

	// count of sel in section "i" (skip if not)
	void iSq(int i)
	{
		i += INDEX_OFFSET;
		try {
			int size = sections[i].selectors.getSize();
			cout << command << " == ";
			cout << size << endl;
		}
		catch (...) {}
	}
	// name of "j" sel for section "i" (skip if not)
	void iSj(int i, int j)
	{
		i += INDEX_OFFSET;
		j += INDEX_OFFSET;
		try {
			string name = sections[i].selectors[j];
			cout << command << " == ";
			cout << name << endl;
		}
		catch (...) {}
	}
	// count of sel named "z" across all sections
	void zSq(const string& z)
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

	// value of atr named "n" for sel named "z"
	void zEn(const string& z, const string& n)
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

	void chooseDTypeCommand(const vector<string>& params)
	{
		if (params[2] == '*')
			iDq(sbl::stoi(params[0]));
		else
			iDn(sbl::stoi(params[0]), params[2]);
		command.clear();
	}

	// delete "i" section
	void iDq(int i)
	{
		i += INDEX_OFFSET;
		try {
			sections.pop(i);
			cout << command;
			cout << " == deleted" << endl;
		} catch(...) { }
	}
	// delete atr named "n" od "i" section
	void iDn(int i, const string& n)
	{
		i += INDEX_OFFSET;
		try {
			Section s = sections[i];
			s.attributes.pop(s.findAtrIndex(n));
			if (s.attributes.isEmpty())
				sections.pop(i);
			cout << command;
			cout << " == deleted" << endl;
		} catch (...) {}
	}


	void readCommandLine(int ch)
	{
		if (ch == '\n')
			return;
		do {
			if (ch == EOF || ch == 26)
			{
				isFileEnded = true;
				return;
			}
			command += char(ch);
		} while ((ch = getchar()) != '\n');
	}

	bool isEmpty(const string& str)
	{
		for (int i = 0; i < str.size(); i++)
			if (!isspace(str[i]))
				return false;
		return true;
	}

	bool isInvalidCharacter(int ch)
	{
		return (ch < ' ' && !isspace(ch));
	}

};
int main()
{
	CSSReader reader;
	reader.read();
	//cout << reader.sections;
}



/*

abc{a: d;}
d{c: 2;}

????
?
2,D,c
****
ccc{k: m;}



*/