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
	
	Atr& findAtr(const string& name);
	size_t findAtrIndex(const string& name);
	size_t findSelIndex(const string& name);

	friend std::ostream& operator<<(std::ostream& os, const Section& section);

};

