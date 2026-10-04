#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* reverseList(Node* head)
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

    return previous;
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
    head->next->next->next->next->next->next = new Node{7, NULL};
    head->next->next->next->next->next->next->next = new Node{8, NULL};

    Node* secondHalf = head;

    for (int i = 1; i < 4; i++)
        secondHalf = secondHalf->next;

    Node* firstHalf = head;
    Node* firstHalfEnd = head;

    for (int i = 1; i < 3; i++)
        firstHalfEnd = firstHalfEnd->next;

    firstHalfEnd->next = NULL;

    firstHalf = reverseList(firstHalf);
    secondHalf = reverseList(secondHalf);

    Node* temp = firstHalf;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = secondHalf;

    cout << "Final List: ";
    display(firstHalf);

    return 0;
}
