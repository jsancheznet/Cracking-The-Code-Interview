// Given a string, write a function to check if it is a permutation of
// a palindrome. A palindrome is a word or phrase that is the same
// forwards and backwards. A permutation is a rearrangement of
// letters. The palindrome does not need to be limited to just
// dictionary words.


// Symbols dont count, onle letters
// I think a palindrom has to have almost all character count event, except 1 that can be uneven
// If the string size is even, character count should be even for all characters
// If the string size is odd, character count should be even for all characters except for one

#include <iostream>
#include <array>
#include <cctype>

bool IsPalindromePermutation(const std::string &String)
{
    if(String.size() < 1) { return false; }
    if(String.size() == 1 && std::isalpha(String[0])) { return true; } // A single character counts as a palindrome

    // TODO(Jsanchez): We could use a unordered_map/hash table
    std::array<int, 256> AsciiTable = {0};
    int CharacterCount = 0;

    // Count character occurrences
    for(int i = 0; i  < String.size(); i++)
    {
        // Only count alphabetic characters as valid
        if(!std::isalpha(String[i]))
        {
            continue;
        }

        if(std::isalpha(String[i]))
        {
            CharacterCount++;
            AsciiTable[std::tolower(String[i])]++;
        }
    }

    if(CharacterCount == 0) { return false; } // String only consisted of non alphabetic characters

    if(CharacterCount > 0 && CharacterCount % 2 == 0)
    {
        // If the character count in the string is even, then all character must have even occurrences
        for(int CharCounter : AsciiTable)
        {
            if(CharCounter % 2 != 0)
            {
                return false;
            }
        }
    }
    else
    {
        // When the character count in the string is odd, then all characters must have even occurrences, except one

        int OddCharCounter = 0;

        for(auto CharCounter : AsciiTable)
        {
            if(CharCounter > 0 && CharCounter % 2 != 0)
            {
                OddCharCounter++;
            }
        }

        if(OddCharCounter > 1)
        {
            return false;
        }
    }

    return true;
}

void main()
{
    std::cout << "--- Palindromes ---" << std::endl;

    // Strings who are palindromes
    std::cout << IsPalindromePermutation("a") << std::endl;
    std::cout << IsPalindromePermutation("aabb") << std::endl;
    std::cout << IsPalindromePermutation("aaa") << std::endl;
    std::cout << IsPalindromePermutation("aaaaa") << std::endl;
    std::cout << IsPalindromePermutation("aaabb") << std::endl;
    std::cout << IsPalindromePermutation("Tact Coa") << std::endl;
    std::cout << IsPalindromePermutation("aabbccdde") << std::endl;
    std::cout << IsPalindromePermutation("aab#") << std::endl; // Non alphabetic characters do not count
    std::cout << IsPalindromePermutation("Sit on a potato pan, Otis.") << std::endl;
    std::cout << IsPalindromePermutation("Naomi, Gianna, Ed, Nall, Robert, Allen, Red, Hon, Evan, Eden, Mel, Lola, Alol, Lemned, Enave, Noh, Der, Nella, Trebor, Llan, De, Anna, Ig & I moan.") << std::endl;

    std::cout << "--- Not Palindromes ---" << std::endl;

    // Strings who are not palindromes
    std::cout << IsPalindromePermutation("ab") << std::endl;
    std::cout << IsPalindromePermutation("aaa bbb") << std::endl;
    std::cout << IsPalindromePermutation("   ") << std::endl;
    std::cout << IsPalindromePermutation("###") << std::endl;
    std::cout << IsPalindromePermutation("aabc") << std::endl;
}
