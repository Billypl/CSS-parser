#pragma once

#include "vector.h"
#include "string.h"
#include "List.h"
#include "Section.h"
#include "algorithm.h"

class STypeCommandHandler
{

public:

	List<Section, BLOCK_SIZE>& sections;
	string& command;

	STypeCommandHandler();

	void chooseCommand(const vector<string>& params, const string& command);

	// count of sel in section "i" (skip if not)
	int iSq(int i);
	// name of "j" sel for section "i" (skip if not)
	string iSj(int i, int j);
	// count of sel named "z" across all sections
	int zSq(const string& z);
};
