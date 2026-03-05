#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float marks;
};

Student s[100];
int count = 0;

void addStudent() {
    if (count >= 100) {
        cout << "Student limit reached!\n";
        return;
    }

    cout << "\nEnter Roll Number: ";
    cin >> s[count].roll;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s[count].name);

    cout << "Enter Marks: ";
    cin >> s[count].marks;

    count++;

    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (count == 0) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    for (int i = 0; i < count; i++) {
        cout << "\nRoll Number: " << s[i].roll;
        cout << "\nName: " << s[i].name;
        cout << "\nMarks: " << s[i].marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            cout << "\nStudent Found\n";
            cout << "Name: " << s[i].name << endl;
            cout << "Marks: " << s[i].marks << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {

            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }

            count--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {

    int choice;

    do {
        cout << "\n----- Student Management System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}