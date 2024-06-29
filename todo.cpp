#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void addTask(vector<pair<int, string>>& tasks, int& nextTaskId) {
    string description;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back(make_pair(nextTaskId++, description));
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<pair<int, string>>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        cout << "Tasks:\n";
        for (const auto& task : tasks) {
            cout << task.first << ". ";
            if (task.second.empty()) {
                cout << "[COMPLETED] ";
            }
            cout << task.second << "\n";
        }
    }
}

void markTaskCompleted(vector<pair<int, string>>& tasks) {
    int taskId;
    cout << "Enter task ID to mark as completed: ";
    cin >> taskId;
    auto it = find_if(tasks.begin(), tasks.end(), [taskId](const pair<int, string>& task) {
        return task.first == taskId;
    });

    if (it != tasks.end()) {
        cout << "Task '" << it->second << "' marked as completed.\n";
      
        it->second = "[COMPLETED] " + it->second;
    } else {
        cout << "Task with ID " << taskId << " not found.\n";
    }
}

void deleteTask(vector<pair<int, string>>& tasks) {
    int taskId;
    cout << "Enter task ID to delete: ";
    cin >> taskId;
    auto it = find_if(tasks.begin(), tasks.end(), [taskId](const pair<int, string>& task) {
        return task.first == taskId;
    });

    if (it != tasks.end()) {
        cout << "Task '" << it->second << "' deleted successfully.\n";
        tasks.erase(it); 
    } else {
        cout << "Task with ID " << taskId << " not found.\n";
    }
}

int main() {
    vector<pair<int, string>> tasks; 
    int nextTaskId = 1;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, nextTaskId);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
