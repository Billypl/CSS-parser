#pragma once
#include "List.h"
#include "string.h"
#include "pair.h"

typedef List<Atr, BLOCK_SIZE> AtrList;
typedef List<string, BLOCK_SIZE> SelList;

class Section
{

public:

	SelList selectors;
	AtrList attributes;
	
	Atr& findAtr(string name);
	size_t findAtrIndex(string name);

	friend std::ostream& operator<<(std::ostream& os, const Section& section);

};

