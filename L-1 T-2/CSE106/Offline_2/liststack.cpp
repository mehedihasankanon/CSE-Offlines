#include "stack.h"
#include <iostream>

// Constructor implementation
ListStack::ListStack()
{
    // TODO: Initialize head to nullptr
    // TODO: Initialize current_size to 0
    head = nullptr;
    current_size = 0;
}

// Destructor implementation
ListStack::~ListStack()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Push implementation
void ListStack::push(int item)
{
    // TODO: Create a new node with the given item
    // TODO: Make the new node point to the current head
    // TODO: Update head to point to the new node
    // TODO: Increment current_size
    Node *elem = new Node(item, head);
    head = elem;
    current_size++;
}

// Pop implementation
int ListStack::pop()
{
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Store the data from the head node
    // TODO: Update head to point to the next node
    // TODO: Delete the old head node
    // TODO: Decrement current_size
    // TODO: Return the stored data
    if (!head)
    {
        // std::cout << "Error: Empty Stack (Stack Underflow)" << std::endl;
        return -1e9;
    }
    int ret = head->data;
    Node *rmv = head;
    head = head->next;
    delete (rmv);
    current_size--;
    return ret;
}

// Clear implementation
void ListStack::clear()
{
    // TODO: Traverse the linked list, deleting each node
    // TODO: Reset head to nullptr
    // TODO: Reset current_size to 0
    while (head)
    {
        Node *cur = head;
        head = head->next;
        delete cur;
    }
    head = nullptr;
    current_size = 0;
}

// Size implementation
int ListStack::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Top implementation
int ListStack::top() const
{
    // TODO: Check if the stack is empty, display error message if it is
    // TODO: Return the data from the head node without removing it
    if (!head)
    {
        // std::cout << "Error: Empty Stack\n";
        return -1e9;
    }
    return head->data;
}

// Empty implementation
bool ListStack::empty() const
{
    // TODO: Return whether head is nullptr
    return !head;
}

// Print implementation
void ListStack::print() const
{
    // TODO: Print stack elements from top to bottom in the format: |elem1, elem2, ..., elemN>
    // TODO: Traverse the linked list from head, printing each node's data
    Node *it = head;
    std::cout << '|';
    while (it)
    {
        std::cout << it->data;
        if (it->next)
            std::cout << ", ";
        it = it->next;
    }
    std::cout << ">\n";
    return;
}