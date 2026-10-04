#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void removeDuplicates(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* previous = current;
        Node* temp = current->next;

        while (temp != NULL)
        {
            if (temp->data == current->data)
            {
                previous->next = temp->next;
                delete temp;
                temp = previous->next;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
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
    Node* head = new Node{101, NULL};
    head->next = new Node{202, NULL};
    head->next->next = new Node{101, NULL};
    head->next->next->next = new Node{303, NULL};
    head->next->next->next->next = new Node{202, NULL};

    cout << "Original Stamps: ";
    display(head);

    removeDuplicates(head);

    cout << "\nUnique Stamps: ";
    display(head);

    return 0;
}
