// One Away: There are three types of edits that can be performed on string:
// - Insert a character.
// - Remove a character.
// - Replace a character.
// Given two strings, write a function to check if they are one edit (or zero edits)  away.

#include <iostream>

bool AreOneAway(const std::string A, const std::string B)
{
    // Insert one character - > std::string::insert
    // Replace one character - > std::string::replace
    // Erase one character - > std::string::erase

    // Strings cannot have more than -1. 0, +1 character counts. This
    // is a good early return before doing the required computations

    // Maybe loop over the first string, when we find a difference try
    // to insert/remove the correct character. This should maybe be
    // done on the string with less/more characters

    // TODO: Copiar los ejemplos del libro, y manualmente loopear sobre las strings hasta que aparezca la solucion!

    return true;
}

void main()
{
    std::cout << "Hello!" << std::endl;
}
