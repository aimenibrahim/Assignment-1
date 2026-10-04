#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* previous;
    Node* next;
};

void displayForward(Node* head)
{
    while (head != NULL)
    {
        cout << head->song << endl;
        head = head->next;
    }
}

void displayBackward(Node* tail)
{
    while (tail != NULL)
    {
        cout << tail->song << endl;
        tail = tail->previous;
    }
}

int main()
{
    Node* head = new Node{"Song 1", NULL, NULL};

    Node* song2 = new Node{"Song 2", head, NULL};
    head->next = song2;

    Node* song3 = new Node{"Song 3", song2, NULL};
    song2->next = song3;

    Node* tail = new Node{"Song 4", song3, NULL};
    song3->next = tail;

    cout << "Forward Playlist:\n";
    displayForward(head);

    cout << "\nBackward Playlist:\n";
    displayBackward(tail);

    return 0;
}
