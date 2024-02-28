// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.

// Space ' ' counts as a value

#include <iostream>
#include <algorithm>
#include <array>

using std::string;
using std::cout;
using std::endl;

bool ArePermutation(string &StringA, string &StringB)
{
    if(StringA.size() != StringB.size()) { return false; }

    // Here I'm assuming empty string are not permutations of each other, this must fail
    if(StringA.empty() && StringB.empty()) { return false; }

    std::sort(StringA.begin(), StringA.end());
    std::sort(StringB.begin(), StringB.end());

    if(StringA != StringB)
    {
        return false;
    }

    return true;
}

bool ArePermutation_WithoutSorting(const string &A, const string  &B)
{
    std::array<int, 256> AsciiTable = {0};

    for(int i = 0; i < A.size(); i++)
    {
        AsciiTable[A[i]]++;
    }

    for(int i = 0; i < B.size(); i++)
    {
        AsciiTable[B[i]]--;

        if(AsciiTable[B[i]] < 0)
        {
            return false;
        }
    }

    return true;
}

void main()
{
    string String1 = "abcde_fg";
    string String2 = "abcde_fg";
    string String3 = "abcde_fj";
    string String4 = "Abcde_fg";
    string String5 = "gf_edcba";
    string String6 = "gf_edcba ";
    string String7 = "gf_ edcba";

    cout << ArePermutation(String1, String2) << endl;
    cout << ArePermutation(String1, String3) << endl;
    cout << ArePermutation(String1, String4) << endl;
    cout << ArePermutation(String1, String5) << endl;
    cout << ArePermutation(String6, String7) << endl;

    cout << "---" << endl;

    cout << ArePermutation_WithoutSorting(String1, String2) << endl;
    cout << ArePermutation_WithoutSorting(String1, String3) << endl;
    cout << ArePermutation_WithoutSorting(String1, String4) << endl;
    cout << ArePermutation_WithoutSorting(String1, String5) << endl;
    cout << ArePermutation_WithoutSorting(String6, String7) << endl;
}
