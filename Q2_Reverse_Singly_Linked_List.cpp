#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void reverseList(Node*& head)
{
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;
}

int main()
{
    Node* head = new Node{1, NULL};
    head->next = new Node{2, NULL};
    head->next->next = new Node{3, NULL};
    head->next->next->next = new Node{4, NULL};

    cout << "Original Playlist: ";
    display(head);

    reverseList(head);

    cout << "\nReversed Playlist: ";
    display(head);

    return 0;
}
