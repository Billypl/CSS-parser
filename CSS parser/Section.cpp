#include "Section.h"
#include "List.cpp"
#include "pair.cpp"
#include <iostream>

Atr& Section::findAtr(const string& name)
{
    size_t index = findAtrIndex(name);
    if(index > attributes.getSize())
        throw "there is no attribute with given name!";
    return attributes[index];
}

size_t Section::findAtrIndex(const string& name)
{
    for (int i = 0; i < attributes.getSize(); i++)
        if (attributes[i].name == name)
            return i;
    return -1;
}

size_t Section::findSelIndex(const string& name)
{
    for (int i = 0; i < selectors.getSize(); i++)
        if (selectors[i] == name)
            return i;
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Section& section)
{
    std::cout << "selectors: " << section.selectors;
    std::cout << "attributes: " << section.attributes;
    return os;
}
