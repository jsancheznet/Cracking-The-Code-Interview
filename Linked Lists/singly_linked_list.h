#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>

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

node *Prepend(list *List, int Value)
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

    return NewNode;
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
