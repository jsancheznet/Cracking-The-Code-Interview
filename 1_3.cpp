// Urlify: Write a method to replace all spaces in a string with
// '%20', You may assume that the string has sufficient space at the
// end to hold the additional characters, and that you are given the
// "true" length of the string. Try to do this with C++ STL functions
// and without.

#include <iostream>

using std::cout;
using std::endl;
using std::string;

void Urlify_Array(std::string &String, int TrueLength)
{
    // Space Count
    int SpaceCount = 0;
    for(int i = 0; i < TrueLength; i++)
    {
        if(String[i] == ' ')
        {
            SpaceCount++;
        }
    }

    // Add the nul terminator to the string to make it complete
    if(TrueLength < String.size())
    {
        String[TrueLength] = '\0';
    }

    int Index = TrueLength + SpaceCount * 2;
    for(int i = TrueLength - 1; i >= 0; i--)
    {
        if(String[i] == ' ')
        {
            String[Index - 1] = '0';
            String[Index - 2] = '2';
            String[Index - 3] = '%';
            Index -= 3;
        }
        else
        {
            String[Index - 1] = String[i];
            Index--;
        }
    }
}

void main()
{
    std::string ExampleString = "Mr John Smith    ";
    std::string ExampleString2 = "Mr Jorge Sanchez    ";
    std::string ExampleString3 = "Mr John Smith A        ";

    Urlify_Array(ExampleString, 13);
    Urlify_Array(ExampleString2, 16);
    Urlify_Array(ExampleString3, 15);

    std::cout << ExampleString << std::endl;
    std::cout << ExampleString2 << std::endl;
    std::cout << ExampleString3 << std::endl;
}
