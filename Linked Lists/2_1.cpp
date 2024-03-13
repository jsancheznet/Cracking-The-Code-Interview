// Remove Dups: Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed?

#include <iostream>
#include <forward_list>
#include <unordered_map>

void RemoveDuplicates_HashTable(std::forward_list<int> &List)
{
    // Create a Hash Table of ints, this table will contain seen values
    std::unordered_map<int, bool> ExtraBuffer;

    // Iterate the list, check the has table for the value, if it's not there: add and move on, if it's there delete the current node and move on

    // NOTE(Jsanchez): The following loop uses two iterators, It and
    // PrevIt. PrevIt points to the element before It, you can use
    // before_begin() to initialize it and set it to the next on the
    // end of the loop
    auto PrevIt = List.before_begin();
    for(auto It = List.begin(); It != List.end(); ++It)
    {
        auto Search = ExtraBuffer.find(*It);
        if(Search != ExtraBuffer.end())
        {
            // Found it
            std::cout << "Removing Item: " << *It << std::endl;
            List.erase_after(PrevIt);
        }
        else
        {
            ExtraBuffer.insert({*It, true});
        }

        PrevIt = It;
    }
}

void RemoveDuplicates_NSquaredSolution(std::forward_list<int> &List)
{
    // N^2 Loop over the List
    for(auto It = List.begin(); It != List.end(); It++)
    {
        auto PrevIt = It;
        for(auto It2 = std::next(It, 1); It2 != List.end(); It2++)
        {
            if(*It2 == *It)
            {
                std::cout << "Removing Item: " << *It2 << std::endl;
                List.erase_after(PrevIt);
            }

            PrevIt = It2;
        }
    }
}

void PrintList(const std::forward_list<int> &List)
{
    for(auto It = List.begin(); It != List.end(); ++It)
    {
        std::cout << *It;
    }

    std::cout << std::endl;
}

int main()
{
    std::cout << "RemoveDuplicates_HashTable(MyList)" << std::endl;
    std::forward_list<int> MyList = {1, 2, 3, 4, 4, 5, 5, 6, 7, 6};
    PrintList(MyList);
    RemoveDuplicates_HashTable(MyList);
    PrintList(MyList);
    std::cout << "--------------------------" << std::endl;

    std::cout << "RemoveDuplicates_NSquaredSolution(MyList2)" << std::endl;
    std::forward_list<int> MyList2 = {1, 2, 3, 4, 4, 5, 5, 6, 7, 6, 1};
    PrintList(MyList2);
    RemoveDuplicates_NSquaredSolution(MyList2);
    PrintList(MyList2);
}
