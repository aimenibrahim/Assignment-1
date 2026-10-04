#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* previous;
    Node* next;
};

void createPattern(Node* head)
{
    Node* left = head->next;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    right = right->previous;

    while (left != NULL && right != NULL)
    {
        if (left == right || left->next == right)
            break;

        int temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next->next;
        right = right->previous->previous;
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
    Node* head = new Node{1, NULL, NULL};

    Node* n2 = new Node{2, head, NULL};
    head->next = n2;

    Node* n3 = new Node{3, n2, NULL};
    n2->next = n3;

    Node* n4 = new Node{4, n3, NULL};
    n3->next = n4;

    Node* n5 = new Node{5, n4, NULL};
    n4->next = n5;

    Node* n6 = new Node{6, n5, NULL};
    n5->next = n6;

    Node* n7 = new Node{7, n6, NULL};
    n6->next = n7;

    Node* n8 = new Node{8, n7, NULL};
    n7->next = n8;

    Node* n9 = new Node{9, n8, NULL};
    n8->next = n9;

    cout << "Original Seats: ";
    display(head);

    createPattern(head);

    cout << "\nNew Seat Pattern: ";
    display(head);

    return 0;
}
