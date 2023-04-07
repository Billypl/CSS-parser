#pragma once
#include "vector.h"
#include "string.h"
#include "List.h"
#include "Section.h"
#include "algorithm.h"

class DTypeCommandHandler
{
public:

	List<Section, BLOCK_SIZE>& sections;
	string& command;

	DTypeCommandHandler();

	void chooseCommand(const vector<string>& params);

	// delete "i" section
	void iDq(int i);
	// delete atr named "n" od "i" section
	void iDn(int i, const string& n);
};

