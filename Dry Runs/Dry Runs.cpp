#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char name[20];
    char major[20];
    float GPA;
    bool status;
};

void InputStudents(student* S, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter data for student " << i + 1 << ":\n";
        cout << "Enter Name: ";
        cin >> S[i].name;
        cout << "Enter Major: ";
        cin >> S[i].major;
        cout << "Enter GPA: ";
        cin >> S[i].GPA;
    }
}

void UpdateStatus(student* S, int n) {
    for (int i = 0; i < n; i++) {
        bool goodGPA = S[i].GPA >= 3.5;
        bool goodMajor = (strcmp(S[i].major, "Engineering") == 0 ||
            strcmp(S[i].major, "Science") == 0);
        S[i].status = goodGPA && goodMajor;
        cout << "\t";
    }
}

void DisplayEligibleStudents(student* S, int n) {
    cout << "Students eligible for scholarship are:\n";
    for (int i = 0; i < n; i++) {
        if (S[i].status) {
            cout << "Name: " << S[i].name << "\n";
            cout << "Major: " << S[i].major << "\n";
            cout << "GPA: " << S[i].GPA << "\n";
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    student* S = new student[n];

    InputStudents(S, n);
    UpdateStatus(S, n);
    DisplayEligibleStudents(S, n);

    delete[] S;
    S = nullptr;

    return 0;
}