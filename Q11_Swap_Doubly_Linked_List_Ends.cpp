#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* previous;
    Node* next;
};

void swapDesks(Node* head)
{
    Node* left = head;
    Node* right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->previous != right)
    {
        string temp = left->data;
        left->data = right->data;
        right->data = temp;

        left = left->next;
        right = right->previous;
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
    Node* head = new Node{"Alice", NULL, NULL};

    Node* bob = new Node{"Bob", head, NULL};
    head->next = bob;

    Node* charlie = new Node{"Charlie", bob, NULL};
    bob->next = charlie;

    Node* dana = new Node{"Dana", charlie, NULL};
    charlie->next = dana;

    Node* eva = new Node{"Eva", dana, NULL};
    dana->next = eva;

    Node* frank = new Node{"Frank", eva, NULL};
    eva->next = frank;

    cout << "Original Arrangement: ";
    display(head);

    swapDesks(head);

    cout << "\nNew Arrangement: ";
    display(head);

    return 0;
}
