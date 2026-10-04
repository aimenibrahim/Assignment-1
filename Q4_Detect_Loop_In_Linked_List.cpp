#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    Node* head = new Node{10, NULL};
    head->next = new Node{20, NULL};
    head->next->next = new Node{30, NULL};
    head->next->next->next = new Node{40, NULL};

    // Creating a loop
    head->next->next->next->next = head->next;

    if (detectLoop(head))
        cout << "Loop exists.";
    else
        cout << "No loop exists.";

    return 0;
}
