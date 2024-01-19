#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TASKS = 50; 

struct Task {
    char description[50];
    bool completed;
};

void addTask(Task tasks[], int& taskCount, const char* description) {
    if (taskCount < MAX_TASKS) {
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].completed = false;
        taskCount++;
        cout << "Task added successfully.\n";
    } else {
        cout << "Cannot add more tasks. List is full.\n";
    }
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to display.\n";
    } else {
        cout << "Tasks:\n";
        for (int i = 0; i < taskCount; ++i) {
            cout << (i + 1) << ". " << tasks[i].description << " - "
                      << (tasks[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

void markTaskAsCompleted(Task tasks[], int taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(Task tasks[], int& taskCount, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskCount) {
        for (int i = taskIndex - 1; i < taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        --taskCount;
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                char description[50];
                cout << "Enter task description: ";
                cin.ignore();  // Clear input buffer
                cin.getline(description, sizeof(description));
                addTask(tasks, taskCount, description);
                break;
            }
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                markTaskAsCompleted(tasks, taskCount, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskCount, taskIndex);
                break;
            }
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
