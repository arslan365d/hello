#include <iostream>
#include <string>
using namespace std;

template <class T>
class DynamicArray {
protected:
    T* arr;
    int capacity;

public:
    DynamicArray(int cap) {
        capacity = cap;
        arr = new T[capacity];
    }

    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;

    virtual ~DynamicArray() {
        delete[] arr;
    }
};

template <class T>
class Queue : public DynamicArray<T> {
private:
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int cap) : DynamicArray<T>(cap) {
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool isFull() override {
        return count == this->capacity;
    }

    bool isEmpty() override {
        return count == 0;
    }

    int size() override {
        return count;
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue full. Resizing...\n";
            resize();
        }

        rearIndex = (rearIndex + 1) % this->capacity;
        this->arr[rearIndex] = value;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        frontIndex = (frontIndex + 1) % this->capacity;
        count--;
    }

    T Front() {
        return this->arr[frontIndex];
    }

    void resize() {
        int newCap = this->capacity * 2;
        T* newArr = new T[newCap];

        for (int i = 0; i < count; i++) {
            newArr[i] = this->arr[(frontIndex + i) % this->capacity];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->capacity = newCap;

        frontIndex = 0;
        rearIndex = count - 1;
    }

    void display() {
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << this->arr[(frontIndex + i) % this->capacity] << " ";
        }
        cout << endl;
    }
};

int main() {

    Queue<string> printerQueue(3);

    printerQueue.enqueue("Job1");
    printerQueue.enqueue("Job2");
    printerQueue.enqueue("Job3");

    cout << "Initial Print Queue:\n";
    printerQueue.display();

    printerQueue.enqueue("Job4");

    cout << "\nProcessing Print Jobs:\n";

    while (!printerQueue.isEmpty()) {

        cout << "Printing: " << printerQueue.Front() << endl;
        printerQueue.dequeue();

        if (!printerQueue.isEmpty()) {
            cout << "Next job in queue...\n";
        }
        else {
            cout << "Printer is now idle.\n";
        }
    }

    return 0;
}