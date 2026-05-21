#include <iostream>
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

    T Front() {
        if (!isEmpty())
            return this->arr[frontIndex];
        throw runtime_error("Queue is empty");
    }

    T Rear() {
        if (!isEmpty())
            return this->arr[rearIndex];
        throw runtime_error("Queue is empty");
    }

    void enqueue(T value) {
        if (isFull()) {
            cout << "Queue is full, resizing...\n";
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

    void resize() {
        int newCapacity = this->capacity * 2;
        T* newArr = new T[newCapacity];

        for (int i = 0; i < count; i++) {
            newArr[i] = this->arr[(frontIndex + i) % this->capacity];
        }

        delete[] this->arr;
        this->arr = newArr;
        this->capacity = newCapacity;

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

    Queue<int> q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.enqueue(40);

    q.display();

    try{
        cout << "Front: " << q.Front() << endl;
        cout << "Rear: " << q.Rear() << endl;
    }catch(runtime_error&e){
        cout << e.what()<<endl;
    }

    q.dequeue();
    q.display();

    cout << "Size: " << q.size() << endl;

    return 0;
}