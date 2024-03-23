#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[X] " : "[ ] ");
            cout << tasks[i].description << endl;
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks[index].completed = true;
        cout << "Task marked as completed." << endl;
    }

    void removeTask(size_t index) {
        if (index >= tasks.size()) {
            cout << "Invalid task index." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index);
        cout << "Task removed successfully." << endl;
    }
};

int main() {
    TodoList todoList;
    char choice;

    do {
        cout << "\nMENU\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case '1': {
                cout << "Enter task description: ";
                string description;
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                cout << "Enter the index of the task to mark as completed: ";
                size_t index;
                cin >> index;
                todoList.markTaskAsCompleted(index - 1);
                break;
            }
            case '4': {
                cout << "Enter the index of the task to remove: ";
                size_t index;
                cin >> index;
                todoList.removeTask(index - 1);
                break;
            }
            case '5':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
