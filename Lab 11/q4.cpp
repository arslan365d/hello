#include <iostream>
#include <map>
#include <cctype>
using namespace std;

void addStudents(map<string, char> &students) {

    char choice;

    do {
        string name;
        char grade;

        do {
            cout << "Enter student name: ";
            cin >> name;

            if (name.empty()) {
                cout << "Name cannot be empty!\n";
            }

        } while (name.empty());

        while (true) {

            cout << "Enter grade (A-F): ";
            cin >> grade;

            grade = toupper(grade);

            if (grade == 'A' || grade == 'B' || grade == 'C' ||
                grade == 'D' || grade == 'F') {

                break;
            }
            else {
                cout << "Invalid grade! Enter A, B, C, D, or F only.\n";
            }
        }

        students[name] = grade;

        do {
            cout << "Add another student? (y/n): ";
            cin >> choice;

            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid input! Enter y or n only.\n";
            }

        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');
}


void getGrade(map<string, char> &students, string name) {

    auto it = students.find(name);

    if (it != students.end()) {
        cout << "Grade of " << name << " is: " << it->second << endl;
    }
    else {
        cout << "Student not found!" << endl;
    }
}


void updateGrade(map<string, char> &students, string name) {

    auto it = students.find(name);

    if (it != students.end()) {

        char newGrade;

        while (true) {

            cout << "Enter new grade (A-F): ";
            cin >> newGrade;

            newGrade = toupper(newGrade);

            if (newGrade == 'A' || newGrade == 'B' ||
                newGrade == 'C' || newGrade == 'D' ||
                newGrade == 'F') {

                break;
            }
            else {
                cout << "Invalid grade! Enter A, B, C, D, or F only.\n";
            }
        }

        it->second = newGrade;

        cout << "Grade updated successfully!" << endl;
    }
    else {
        cout << "Student not found!" << endl;
    }
}


void deleteStudent(map<string, char> &students, string name) {

    auto it = students.find(name);

    if (it != students.end()) {

        students.erase(name);

        cout << "Student deleted successfully!" << endl;
    }
    else {
        cout << "Student not found!" << endl;
    }
}


void displayStudents(map<string, char> &students) {

    if (students.empty()) {
        cout << "No students found!" << endl;
        return;
    }

    cout << "\nStudent List:\n";

    for (const auto &x: students) {
        cout << x.first << " : " << x.second << endl;
    }
}


int main() {

    map<string, char> students;

    int choice;

    do {

        cout << "\n===== MENU =====\n";
        cout << "1. Add Students\n2. Retrieve Grade\n3. Update Grade\n4. Delete Student\n5. Display Students\n6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            addStudents(students);
            break;

        case 2: {
            string name;

            cout << "Enter student name: ";
            cin >> name;

            getGrade(students, name);
            break;
        }

        case 3: {
            string name;

            cout << "Enter student name: ";
            cin >> name;

            updateGrade(students, name);
            break;
        }

        case 4: {
            string name;

            cout << "Enter student name: ";
            cin >> name;

            deleteStudent(students, name);
            break;
        }

        case 5:
            displayStudents(students);
            break;

        case 6:
            cout << "Program terminated!" << endl;
            break;
        default:
        cout << "Invalid Choice"<<endl;
        break;    
        }


    } while (choice != 6);

    return 0;
}