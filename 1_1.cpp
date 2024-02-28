// Implement an algorith to determine if a string has all unique
// characters. What if you cannot use additional data structures?


// This solution iterates over an array in 2 nested for loops. This should be O(N^2)

// We could also create a hash table/map and iterate over the array
// once, add each character to the hash table and count
// occurences. This should be theoritically faster, but in this small
// example, thanks to caching the iteration solution should be the
// fastest.

// Another option even faster than the AsciiTable version can be to
// use an array of bits, it should some space, pretty useful if the
// string are huge.

#include <iostream>


bool StringHasUniqueCharacters(std::string &String)
{
    for(int i = 0; i < String.size(); i++)
    {
        for(int j = i + 1; j < String.size(); j++)
        {
            if(String[i] == String[j])
            {
                return false;
            }
        }
    }

    return true;
}

bool HasUniqueCharactersBoolArray(std::string &String)
{
    // In this version we assume String just contains characters from the ASCII character set.

    bool AsciiTable[256] = {0};

    for(int i = 0; i < String.size(); i++)
    {
        if(AsciiTable[String[i]] == true)
        {
            return false;
        }
        else
        {
            AsciiTable[String[i]] = true;
        }
    }

    return true;
}

void main()
{
    std::string ExampleString0 = "abcda";
    std::string ExampleString1 = "Hola, mi nombre es Jorge!";
    std::string ExampleString2 = "abcdefghijklmnopqrstu";
    std::string ExampleString3 = "a8hj46z";


    { // Version implemented using a bool array
        std::cout << "--- N^2 solution ---" << std::endl;

        if(HasUniqueCharactersBoolArray(ExampleString0))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }

        if(HasUniqueCharactersBoolArray(ExampleString2))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }
    }

    { // N^2 version (this one's mine)
        std::cout << "--- N^2 solution ---" << std::endl;

        if(StringHasUniqueCharacters(ExampleString0))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }

        if(StringHasUniqueCharacters(ExampleString1))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }

        if(StringHasUniqueCharacters(ExampleString2))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }

        if(StringHasUniqueCharacters(ExampleString3))
        {
            std::cout << "Has all unique characters" << std::endl;
        }
        else
        {
            std::cout << "Has non unique characters" << std::endl;
        }
    }
}
