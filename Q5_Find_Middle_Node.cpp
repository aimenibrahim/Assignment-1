#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        if (fast->next->next == NULL)
            break;

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    cout << "Friends: ";
    display(head);

    Node* middle = findMiddle(head);

    cout << "\nMiddle Friend: " << middle->data;

    return 0;
}
