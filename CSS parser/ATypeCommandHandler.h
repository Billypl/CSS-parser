#pragma once

#include "vector.h"
#include "string.h"
#include "List.h"
#include "Section.h"
#include "algorithm.h"

class ATypeCommandHandler
{

public:

	List<Section, BLOCK_SIZE>& sections;

	ATypeCommandHandler();

	void chooseCommand(const vector<string>& params, const string& command);

	// count of atrs in section "i" (skip if not)
	int iAq(int i);
	// value of atr named "n" for section "i" (skip if not)
	string iAn(int i, const string& n);
	// count of atr named "n" across all sections
	int nAq(const string& n);
};

