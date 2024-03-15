// Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

// If the size of the list is known, we could just advance until we hit the node (ListSize - K)

// I could use two pointers. The first one loops until the linked list ends.

// The second one should start at the beggining and only advance to
// the next once the first one has advanced K times. After that
// advance every single time until the first pointer reaches the end.

#include <iostream>
#include <assert.h>
#include <stdlib.h>

struct node
{
    node *Next;
    int Value;
};

struct list
{
    node *Head;
};

list *CreateList()
{
    list *Result = nullptr;

    Result = (list*)malloc(sizeof(list));
    Result->Head = nullptr;

    return Result;
}

void Prepend(list *List, int Value)
{
    assert(List);

    node *NewNode = (node*)malloc(sizeof(node));
    NewNode->Value = Value;

    if(List->Head == nullptr)
    {
        // First node inserted in the list
        NewNode->Next = nullptr;
        List->Head = NewNode;
    }
    else
    {
        NewNode->Next = List->Head;
        List->Head = NewNode;
    }
}

node *GetLastNode(list *List)
{
    if(List->Head == nullptr)
    {
        return nullptr;
    }

    for(node *CurrNode = List->Head; CurrNode != nullptr; CurrNode = CurrNode->Next)
    {
        if(CurrNode->Next == nullptr)
        {
            return CurrNode;
        }
    }

    return nullptr;
}

void PrintList(list *List)
{
    for(node *CurrNode = List->Head; CurrNode != nullptr; CurrNode = CurrNode->Next)
    {
        std::cout << CurrNode->Value << ", ";
    }

    std::cout << std::endl;
}

node *GetKthToLast(list *List, int K)
{
    if (K < 0) { return nullptr; }
    if (K == 0) { return GetLastNode(List); }

    node *CurrentPtr = List->Head;
    node *KPtr = List->Head;
    int i = 0 ;

    // Advance CurrentPtr K Times. If we reach the end of the list before K nodes, return nullptr.
    for(CurrentPtr = List->Head; CurrentPtr != nullptr; CurrentPtr = CurrentPtr->Next)
    {
        if(i > K)
        {
            KPtr = KPtr->Next;
        }

        ++i;
    }

    std::cout << "Kth(" << K << ")" << KPtr->Value << std::endl;

    return KPtr;
}

int main()
{
    // TODO(Jsanchez): The general algorithm is fine, i need to fix the case when K > NumNodes

    list *MyList = CreateList();

    Prepend(MyList, 10);
    Prepend(MyList, 11);
    Prepend(MyList, 12);
    Prepend(MyList, 13);
    Prepend(MyList, 14);
    Prepend(MyList, 15);
    Prepend(MyList, 16);
    Prepend(MyList, 17);

    PrintList(MyList);

    node *Kth = GetKthToLast(MyList, 0); Kth;
    node *Kth2 = GetKthToLast(MyList, 1); Kth2;
    node *Kth3 = GetKthToLast(MyList, 3); Kth3;
    node *Kth4 = GetKthToLast(MyList, 8); Kth4;

    return 0;
}
