#include <iostream>
#include <set>
#include <string>
#include <cctype>

using namespace std;

void addGuests(set<string> &guests) {
    string name;
    char choice;

    do {
        do {
            cout << "Enter guest name: ";
            cin >> name;

            if (name.empty()) {
                cout << "Name cannot be empty!\n";
            }

        } while (name.empty());

        guests.insert(name);

        while (true) {
            cout << "Add another guest? (y/n): ";
            cin >> choice;

            choice = tolower(choice);

            if (choice == 'y' || choice == 'n') {
                break;
            } else {
                cout << "Invalid input! Enter y or n only.\n";
            }
        }

    } while (choice == 'y');
}

// Display guests
void displayGuests(const set<string> &guests) {

    if (guests.empty()) {
        cout << "No guests added yet!\n";
        return;
    }

    cout << "\n--- Guest List ---\n";

    for (const auto &g : guests) {
        cout << g << endl;
    }
}

// Display count
void displayCount(const set<string> &guests) {
    cout << "\nTotal unique guests: " << guests.size() << endl;
}

int main() {

    set<string> guests;
    int choice;

    do {
        cout << "\n===== PARTY GUEST SYSTEM =====\n";
        cout << "1. Add Guests\n";
        cout << "2. Display Guests\n";
        cout << "3. Show Guest Count\n";
        cout << "4. Exit\n";

         cout << "Enter your choice: ";
         cin >> choice;
   

        switch (choice) {
            case 1:
                addGuests(guests);
                break;

            case 2:
                displayGuests(guests);
                break;

            case 3:
                displayCount(guests);
                break;

            case 4:
                cout << "Program ended.\n";
                break;
            default:
            cout << "Invalid Choice" <<endl;
            break;    
        }

    } while (choice != 4);

    return 0;
}