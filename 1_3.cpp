// Urlify: Write a method to replace all spaces in a string with
// '%20', You may assume that the string has sufficient space at the
// end to hold the additional characters, and that you are given the
// "true" length of the string. Try to do this with C++ STL functions
// and without.

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Non STL version, simple array
// void Urlify(std::array &Array, int TrueLength)
// {
//     for(int i = 0; i < TrueLength; i++)
//     {
//     }
// }
// STL version

void Urlify_STL(string &String, int TrueLength)
{

}

void main()
{
    // { // STL Version
    //     string Example = {"Mr John Smith    "};
    //     Urlify_STL(Example, 13);
    // }


    string A = {"012345 5"};
    A.replace(6, 1, "%20");
    cout << A << endl;
}
