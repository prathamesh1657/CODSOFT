#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Status {
    PENDING,
    COMPLETED
};

struct Task {
    string description;
    Status status;
};

class TodoList {
private:

    vector<Task> tasks;

public:
    void addTask(const string& description)
     {
        tasks.push_back({description, PENDING});
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description;
                cout << " - ";
                cout << (tasks[i].status == PENDING ? "Pending" : "Completed") << endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].status = COMPLETED;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string task;
    size_t index;
    char addAnother;

    do {
        cout << "\nTo-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    cout << "Enter task: ";
                     cin.ignore(); 
                    getline(cin, task);
                    todoList.addTask(task);

                    cout << "Do you want to Add another task? (y=yes / n=no): ";
                    cin >> addAnother;
                } while (tolower(addAnother) == 'y');
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todoList.markTaskCompleted(index - 1); // Adjust index for user input
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todoList.removeTask(index - 1); // Adjust index for user input
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}