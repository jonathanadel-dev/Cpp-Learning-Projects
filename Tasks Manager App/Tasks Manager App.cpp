#include <iostream>
#include <string>
using namespace std;


// Declarations
void addTask(string*& tasks, int& count, int& capacity);
void completeTask(string* tasks, int& count);
void getCurrentTask(string* tasks, int count);
void viewTasks(string* tasks, int count);

int main()
{
    
    string* tasks = new string[2];
    int count = 0, capacity = 2;
    char answer = 'y';

    cout << "*****************************************************************" << endl;
    cout << "\t Welcome to the tasks manager app" << endl;
    cout << "*****************************************************************" << endl;

    do {

        int choice;
        cout << "What operation do you want to perform?" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Complete a task" << endl;
        cout << "3. Get the current task" << endl;
        cout << "4. View all tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        cout << "--------------------------" << endl;
        switch (choice) {

            case 1: {
                addTask(tasks, count, capacity);
                break;
            }

            case 2: {
                completeTask(tasks, count);
                break;
            }

            case 3: {
                getCurrentTask(tasks, count);
                break;
            }

            case 4: {
                viewTasks(tasks, count);
                break;
            }

            case 5: {
                answer = 'n';
                delete[] tasks;
                break;
            }

            default: {
                cout << "Invalid Entry. Please enter a number from 1 to 5" << endl;
            }

        }
        cout << "--------------------------" << endl;

        if (answer != 'n') {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> answer;
        }

    } while (answer != 'n');

    cout << "*****************************************************************" << endl;
    cout << "\t Thank you for using our app" << endl;
    cout << "*****************************************************************" << endl;

}


// Definitions
void addTask(string*& tasks, int& count, int& capacity) {

    string task;
    cout << "Please enter a task to add: ";
    getline(cin, task);

    if (count == capacity) {
        capacity *= 2;
        string* newTasks = new string[capacity];
        for (int i = 0; i < count; i++)
            newTasks[i] = tasks[i];
        delete[] tasks;
        tasks = newTasks;
    }

    tasks[count++] = task;

}
void completeTask(string* tasks, int &count) {

    if (count == 0) {
        cout << "No tasks to remove" << endl;
    }
    else {
        cout << "Removed the task: " << tasks[count - 1] << endl;
        count--;
    }

}
void getCurrentTask(string* tasks, int count) {
    if (count == 0) {
        cout << "No current task" << endl;
        return;
    }
    cout << "Your current task: " << tasks[count - 1] << endl;
}
void viewTasks(string* tasks, int count) {
    cout << "Your tasks: " << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

/*

    Task Management App lets you handle your tasks in a stack order (last in first out)
    You can add or complete a task, get the tasks count, view all tasks in the stack and view the current task

    Its built using a dynamic array

*/