#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void separateEvenOdd(Node* head, Node*& evenHead, Node*& oddHead)
{
    Node* evenTail = NULL;
    Node* oddTail = NULL;

    evenHead = NULL;
    oddHead = NULL;

    while (head != NULL)
    {
        Node* nextNode = head->next;
        head->next = NULL;

        if (head->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = head;
                evenTail = head;
            }
            else
            {
                evenTail->next = head;
                evenTail = head;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = head;
                oddTail = head;
            }
            else
            {
                oddTail->next = head;
                oddTail = head;
            }
        }

        head = nextNode;
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
    head->next = new Node{15, NULL};
    head->next->next = new Node{20, NULL};
    head->next->next->next = new Node{25, NULL};
    head->next->next->next->next = new Node{30, NULL};

    Node* evenHead;
    Node* oddHead;

    separateEvenOdd(head, evenHead, oddHead);

    cout << "Even Prices: ";
    display(evenHead);

    cout << "\nOdd Prices: ";
    display(oddHead);

    return 0;
}
