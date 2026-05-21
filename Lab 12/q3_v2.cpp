#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[50];
    int age;

public:

    Person(const char n[], int a) {
        strcpy(name, n);
        age = a;
    }

    Person() {}

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    Person person1("Arslan", 18);

    ofstream fout("person.bin", ios::binary);

    if (!fout)
    {
        cout << "File cannot be Created for writing!" << endl;
        return 0;
    }

    fout.write((char*)&person1, sizeof(person1));
    fout.close();

    cout << "Data written successfully!" << endl;

    Person person2;

    ifstream fin("person.bin", ios::binary);

    if (!fin)
    {
        cout << "File cannot be opened for reading!" << endl;
        return 0;
    }

    fin.read((char*)&person2, sizeof(person2));
    fin.close();

    cout << "\nData read from file:\n";
    person2.display();

    return 0;
}