#include <iostream>
#include <string>
using namespace std;

// Node for each task in the circular linked list
class TaskNode
{
public:
    int taskId;
    string taskName;
    string status;
    TaskNode* next;

    // Constructor
    TaskNode(int id, string name)
    {
        taskId = id;
        taskName = name;
        status = "Waiting";
        next = NULL;
    }
};

// Circular Task Scheduler
class TaskScheduler
{
private:
    TaskNode* head;
    int totalTasks;

public:

    // Constructor
    TaskScheduler()
    {
        head = NULL;
        totalTasks = 0;
    }

    // Add a new task at the end
    void addTask(int id, string name)
    {
        // Do not add more than 10 tasks
        if (totalTasks == 10)
        {
            cout << "Maximum 10 tasks are allowed.\n";
            return;
        }

        TaskNode* newTask = new TaskNode(id, name);

        // First task
        if (head == NULL)
        {
            head = newTask;
            newTask->next = head;
            totalTasks++;

            updateStatuses();
            return;
        }

        // Find the last node
        TaskNode* current = head;

        while (current->next != head)
        {
            current = current->next;
        }

        // Add new task at the end
        current->next = newTask;
        newTask->next = head;

        totalTasks++;

        // Update statuses according to the required cycle
        updateStatuses();
    }

    // Update the status of all tasks
    void updateStatuses()
    {
        if (head == NULL)
            return;

        TaskNode* current = head;

        for (int i = 1; i <= totalTasks; i++)
        {
            // Task position from newest task
            int positionFromNewest = totalTasks - i + 1;

            if (positionFromNewest == 1)
            {
                // Newest task is Waiting
                current->status = "Waiting";
            }
            else if (positionFromNewest == 2)
            {
                // Second newest task is Ready
                current->status = "Ready";
            }
            else if (positionFromNewest == 3)
            {
                // Third newest task is In Progress
                current->status = "In Progress";
            }
            else
            {
                // Older tasks are Completed
                current->status = "Completed";
            }

            current = current->next;
        }
    }

    // Remove a task using its ID
    void removeTask(int id)
    {
        if (head == NULL)
        {
            cout << "No tasks available.\n";
            return;
        }

        TaskNode* current = head;
        TaskNode* previous = NULL;

        // Find the task
        do
        {
            if (current->taskId == id)
                break;

            previous = current;
            current = current->next;

        } while (current != head);

        // Task was not found
        if (current->taskId != id)
        {
            cout << "Task " << id << " not found.\n";
            return;
        }

        // Only one task exists
        if (current == head && current->next == head)
        {
            delete current;
            head = NULL;
            totalTasks = 0;
            return;
        }

        // If deleting the head
        if (current == head)
        {
            TaskNode* last = head;

            while (last->next != head)
            {
                last = last->next;
            }

            head = head->next;
            last->next = head;

            delete current;
        }
        else
        {
            previous->next = current->next;
            delete current;
        }

        totalTasks--;

        // Recalculate statuses after removing a task
        updateStatuses();

        cout << "Task " << id << " removed successfully.\n";
    }

    // Get the next task according to round-robin order
    TaskNode* getNextTask()
    {
        if (head == NULL)
        {
            cout << "No tasks available.\n";
            return NULL;
        }

        TaskNode* current = head;

        // Search for a task that is Waiting,
        // Ready, or In Progress
        do
        {
            if (current->status != "Completed")
            {
                return current;
            }

            current = current->next;

        } while (current != head);

        cout << "All tasks are completed.\n";
        return NULL;
    }

    // Display all tasks
    void displayAllTasks()
    {
        if (head == NULL)
        {
            cout << "No tasks available.\n";
            return;
        }

        TaskNode* current = head;

        cout << "\n===== TASK SCHEDULER =====\n";

        do
        {
            cout << "Task ID: " << current->taskId << endl;
            cout << "Task Name: " << current->taskName << endl;
            cout << "Status: " << current->status << endl;
            cout << "--------------------------\n";

            current = current->next;

        } while (current != head);
    }

    // Update one task's status manually
    void updateTaskStatus(int id, string newStatus)
    {
        if (head == NULL)
        {
            cout << "No tasks available.\n";
            return;
        }

        TaskNode* current = head;

        do
        {
            if (current->taskId == id)
            {
                current->status = newStatus;

                cout << "Task " << id
                     << " status updated to "
                     << newStatus << ".\n";

                return;
            }

            current = current->next;

        } while (current != head);

        cout << "Task " << id << " not found.\n";
    }
};


// Main function
int main()
{
    TaskScheduler scheduler;

    // Add 10 tasks
    scheduler.addTask(1, "Task 1");
    scheduler.displayAllTasks();

    scheduler.addTask(2, "Task 2");
    scheduler.displayAllTasks();

    scheduler.addTask(3, "Task 3");
    scheduler.displayAllTasks();

    scheduler.addTask(4, "Task 4");
    scheduler.displayAllTasks();

    scheduler.addTask(5, "Task 5");
    scheduler.displayAllTasks();

    scheduler.addTask(6, "Task 6");
    scheduler.displayAllTasks();

    scheduler.addTask(7, "Task 7");
    scheduler.displayAllTasks();

    scheduler.addTask(8, "Task 8");
    scheduler.displayAllTasks();

    scheduler.addTask(9, "Task 9");
    scheduler.displayAllTasks();

    scheduler.addTask(10, "Task 10");
    scheduler.displayAllTasks();

    // Get the next task
    cout << "\n===== NEXT TASK =====\n";

    TaskNode* nextTask = scheduler.getNextTask();

    if (nextTask != NULL)
    {
        cout << "Next Task ID: " << nextTask->taskId << endl;
        cout << "Next Task Name: " << nextTask->taskName << endl;
        cout << "Status: " << nextTask->status << endl;
    }

    // Example of removing a task
    cout << "\n===== REMOVE TASK =====\n";

    scheduler.removeTask(5);

    scheduler.displayAllTasks();

    return 0;
}


