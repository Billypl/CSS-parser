#pragma once
#include "vector.h"
#include "string.h"
#include "List.h"
#include "Section.h"
#include "algorithm.h"


class ZTypeCommandHandler
{
public:

	List<Section, BLOCK_SIZE>& sections;

	ZTypeCommandHandler();

	void chooseCommand(const vector<string>& params, const string& command);

	// value of atr named "n" for sel named "z"
	string zEn(const string& z, const string& n);
};


