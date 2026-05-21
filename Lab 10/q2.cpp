#include <iostream>
using namespace std;

template <class T1,class T2>
void swapData(T1 &a,T2&b) {
    auto temp = a;
    a = b;
    b = temp;
}


int main() {

    int x = 10;
    int y = 20;

    cout << "Before Swapping:\n";
    cout << "x = " << x << " y = " << y << endl;

    swapData(x, y);

    cout << "After Swapping:\n";
    cout << "x = " << x << " y = " << y << endl;

    cout << endl;

    int a = 15;
    float b = 25.5;

    cout << "Before Swapping:\n";
    cout << "a = " << a << " b = " << b << endl;

    swapData(a, b);

    cout << "After Swapping:\n";
    cout << "a = " << a << " b = " << b << endl;

    return 0;
}