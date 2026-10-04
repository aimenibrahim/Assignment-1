#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int josephus(int n, int m)
{
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 1; i <= n; i++)
    {
        Node* newNode = new Node;
        newNode->data = i;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* current = head;
    Node* previous = tail;

    while (current->next != current)
    {
        for (int i = 1; i < m; i++)
        {
            previous = current;
            current = current->next;
        }

        previous->next = current->next;

        Node* temp = current;
        current = current->next;

        delete temp;
    }

    int survivor = current->data;

    delete current;

    return survivor;
}

int main()
{
    int n, m;

    cout << "Enter Number of Persons: ";
    cin >> n;

    cout << "Enter M: ";
    cin >> m;

    cout << "Survivor: " << josephus(n, m);

    return 0;
}
