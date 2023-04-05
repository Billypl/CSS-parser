#include "Section.h"
#include "List.cpp"
#include "pair.cpp"
#include <iostream>

Atr& Section::findAtr(string name)
{
    size_t index = findAtrIndex(name);
    if(index > attributes.getSize() - 1)
        throw "there is no attribute with given name!";
    attributes[index];
}

size_t Section::findAtrIndex(string name)
{
    for (int i = 0; i < attributes.getSize(); i++)
        if (attributes[i].a == name)
            return i;
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Section& section)
{
    std::cout << section.selectors;
    std::cout << section.attributes;
    return os;
}
