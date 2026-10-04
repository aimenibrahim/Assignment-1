#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void displayReverse(Node* head)
{
    if (head == NULL)
        return;

    displayReverse(head->next);
    cout << head->data << " ";
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
    Node* head = new Node;
    head->data = 10;
    head->next = new Node;
    head->next->data = 20;
    head->next->next = new Node;
    head->next->next->data = 30;
    head->next->next->next = new Node;
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    cout << "Original List: ";
    display(head);

    cout << "\nReverse Order: ";
    displayReverse(head);

    return 0;
}
