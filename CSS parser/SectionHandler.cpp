#include "SectionHandler.h"
#include "List.cpp"
#include "vector.h"
#include "vector.cpp"
#include "pair.cpp"

void SectionHandler::readSection(int ch)
{
	if (isInvalidCharacter(ch))
		return;
	if (isSectionEnding(ch))
	{
		isSectionEnded = true;
		isSectionStarted = false;
		saveAttribute();
		return;
	}

	if (isSectionEnded && !isspace(ch))
	{
		sections.add();
		isSectionEnded = false;
	}

	switch (ch)
	{
	case '{':
		saveSelector(ch);
		isSectionStarted = true;
		break;
	case ',':
		saveSelector(ch);
		break;
	case ';':
		saveAttribute();
		break;
	default:
		input += char(ch);
		break;
	}
}

bool SectionHandler::isInvalidCharacter(int ch)
{
	return (ch < ' ' && !isspace(ch));
}

bool SectionHandler::isSectionEnding(int ch)
{
	return ch == '}';
}

void SectionHandler::saveSelector(int ch)
{
	if (!isSectionStarted)
	{
		sections.getLast().selectors.add(input.trim());
		input.clear();
	}
	else
		input += char(ch);
}

void SectionHandler::saveAttribute()
{
	if (isEmpty(input))
		return;
	auto tmp = input.trim().split(':');
	try {
		auto t = sections.getLast().findAtr(tmp[0].trim());
		t.value = tmp[1].trim();
	}
	catch (...) {
		sections.getLast().attributes.add({ tmp[0].trim(), tmp[1].trim() });
	}
	input.clear();
}

bool SectionHandler::isEmpty(const string& str)
{
	for (int i = 0; i < str.size(); i++)
		if (!isspace(str[i]))
			return false;
	return true;
}