// Delete Middle Node: Implement an algorithm to delete a node in the
// middle (i.e., any node but the first and last node, not necessarily
// the axact middle) of a singly linked list. Given only access to
// that node.

// EXAMPLE
// Input: The node c from the linked list a->b->c->d->e->f
// Result: Nothing is returned, but the new linked list looks like a->b->d->e->f

// CreateList
// Prepend(List, IntValue)
// PrintList(List)
// node *GetLastNode(List)
#include "singly_linked_list.h"

#include <iostream>

// NOTES: Any node but the first and last node.

void RemoveNode(node *Node)
{
    // It's the last node, do not remove
    if(Node->Next == nullptr) { return; }

    // It's the first node We have no way of knowing if it's the first
    // node on a singly linked list. I assume the text says that we
    // will always be given a node somewhere in the middle.

    // Copy the next node, to the given node
    Node->Value = Node->Next->Value;
    Node->Next = Node->Next->Next;

    // Delete the next node
    free(Node->Next);
}

int main()
{
    // TODO: Do a STL C++ Version

    list *MyList = CreateList();
    Prepend(MyList, 8);
    Prepend(MyList, 7);
    Prepend(MyList, 6);
    node *GivenNode = Prepend(MyList, 5);
    Prepend(MyList, 4);
    Prepend(MyList, 3);
    Prepend(MyList, 2);
    Prepend(MyList, 1);

    PrintList(MyList);

    RemoveNode(GivenNode);

    PrintList(MyList);

    return 0;
}
