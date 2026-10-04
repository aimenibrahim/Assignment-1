#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    int priority;
    string status;
    Node* next;
};

class TaskScheduler
{
private:
    Node* head;
    Node* current;

public:
    TaskScheduler()
    {
        head = NULL;
        current = NULL;
    }

    void addTask(string name, int priority, string status)
    {
        Node* newNode = new Node;

        newNode->name = name;
        newNode->priority = priority;
        newNode->status = status;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            current = head;
        }
        else
        {
            Node* temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    void removeTask(string name)
    {
        if (head == NULL)
            return;

        Node* currentNode = head;
        Node* previous = NULL;

        do
        {
            if (currentNode->name == name)
            {
                if (currentNode == head)
                {
                    if (head->next == head)
                    {
                        delete head;
                        head = NULL;
                        current = NULL;
                        return;
                    }

                    Node* last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;

                    if (current == currentNode)
                        current = head;

                    delete currentNode;
                    return;
                }
                else
                {
                    previous->next = currentNode->next;

                    if (current == currentNode)
                        current = currentNode->next;

                    delete currentNode;
                    return;
                }
            }

            previous = currentNode;
            currentNode = currentNode->next;

        } while (currentNode != head);
    }

    void getNextTask()
    {
        if (head == NULL)
            return;

        Node* temp = current;

        do
        {
            temp = temp->next;

            if (temp->status == "pending")
            {
                current = temp;

                cout << "Next Task: " << current->name << endl;
                cout << "Priority: " << current->priority << endl;
                cout << "Status: " << current->status << endl;

                return;
            }

        } while (temp != current);

        cout << "No pending task found." << endl;
    }

    void displayAllTasks()
    {
        if (head == NULL)
        {
            cout << "No tasks." << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << "Task: " << temp->name << endl;
            cout << "Priority: " << temp->priority << endl;
            cout << "Status: " << temp->status << endl;
            cout << endl;

            temp = temp->next;

        } while (temp != head);
    }

    void updateTaskStatus(string name, string newStatus)
    {
        if (head == NULL)
            return;

        Node* temp = head;

        do
        {
            if (temp->name == name)
            {
                temp->status = newStatus;

                cout << "Task: " << temp->name << endl;
                cout << "Updated Status: " << temp->status << endl;

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Task not found." << endl;
    }
};

int main()
{
    TaskScheduler scheduler;

    scheduler.addTask("Task 1", 1, "pending");
    scheduler.addTask("Task 2", 2, "pending");
    scheduler.addTask("Task 3", 3, "completed");
    scheduler.addTask("Task 4", 1, "pending");

    cout << "All Tasks:\n";
    scheduler.displayAllTasks();

    cout << "\nNext Task:\n";
    scheduler.getNextTask();

    cout << "\nUpdating Task 1:\n";
    scheduler.updateTaskStatus("Task 1", "completed");

    cout << "\nNext Task:\n";
    scheduler.getNextTask();

    cout << "\nRemoving Task 2:\n";
    scheduler.removeTask("Task 2");

    cout << "\nRemaining Tasks:\n";
    scheduler.displayAllTasks();

    return 0;
}
