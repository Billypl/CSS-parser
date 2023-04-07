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
	string& command;

	ATypeCommandHandler();

	void chooseCommand(const vector<string>& params);

	// count of atrs in section "i" (skip if not)
	void iAq(int i);
	// value of atr named "n" for section "i" (skip if not)
	void iAn(int i, const string& n);
	// count of atr named "n" across all sections
	void nAq(const string& n);
};

