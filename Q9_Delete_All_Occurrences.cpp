#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void deleteAll(Node*& head, int key)
{
    while (head != NULL && head->data == key)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;

    while (current != NULL && current->next != NULL)
    {
        if (current->next->data == key)
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
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
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{20, NULL};
    head->next->next->next->next = new Node{40, NULL};
    head->next->next->next->next->next = new Node{20, NULL};

    int key;

    cout << "Enter Book ID to delete: ";
    cin >> key;

    deleteAll(head, key);

    cout << "Updated List: ";
    display(head);

    return 0;
}
