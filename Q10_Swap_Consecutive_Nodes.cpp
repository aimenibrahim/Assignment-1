#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void swapPairs(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* previous = NULL;
    Node* current = head;

    head = head->next;

    while (current != NULL && current->next != NULL)
    {
        Node* first = current;
        Node* second = current->next;

        first->next = second->next;
        second->next = first;

        if (previous != NULL)
            previous->next = second;

        previous = first;
        current = first->next;
    }
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};
    head->next->next->next->next = new Node{5, NULL};
    head->next->next->next->next->next = new Node{6, NULL};

    cout << "Original List: ";
    display(head);

    swapPairs(head);

    cout << "\nAfter Swapping: ";
    display(head);

    return 0;
}
