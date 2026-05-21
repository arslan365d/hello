#include <iostream>
using namespace std;

// Generic Template Class
template <class T>
class mycontainer {
private:
    T value;

public:
    mycontainer(T v) {
        value = v;
    }

    void increase() {
        value++;
        cout << "Increased value: " << value << endl;
    }
};

// Template Specialization for char
template <>
class mycontainer<char> {
private:
    char value;

public:
    mycontainer(char v) {
        value = v;
    }

    void uppercase() {
        if (value >= 'a' && value <= 'z') {
            value = value - 32;
        }

        cout << "Uppercase value: " << value << endl;
    }
};

int main() {

    mycontainer<int> obj1(10);
    cout << "Integer container:\n";
    obj1.increase();

    cout << endl;

    mycontainer<char> obj2('d');
    cout << "Char container:\n";
    obj2.uppercase();

    return 0;
}