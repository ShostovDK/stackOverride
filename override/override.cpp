
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    int size() {
        return top + 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return data[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    Stack operator+(int value) {
        Stack result;
        result.push(value);
        return result;
    }

    Stack operator-(int& value) {
        value = pop();
        return *this;
    }

    Stack operator*(int value) {
        Stack result;
        for (int i = 0; i <= top; i++) {
            result.push(value * data[i]);
        }
        return result;
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            top = other.top;
            for (int i = 0; i <= top; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    bool operator==(const Stack& other) const {
        if (this == &other) {
            return true;
        }
        if (top != other.top) {
            return false;
        }
        for (int i = 0; i <= top; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Stack& other) const {
        return !(*this == other);
    }

    Stack operator+=(int value) {
        push(value);
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Stack& stack);
    friend istream& operator>>(istream& is, Stack& stack);
};

ostream& operator<<(ostream& os, const Stack& stack) {
    os << "[";
    for (int i = 0; i <= stack.top; i++) {
        os << stack.data[i];
        if (i != stack.top) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

istream& operator>>(istream& is, Stack& stack) {
    int value;
    is >> value;
    stack.push(value);
    return is;
}

int main() {
    Stack stack1, stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2 = stack1;
    cout << stack2 << endl;
    cout << (stack1 == stack2) << endl;
    cout << (stack1 != stack2) << endl;
    stack1 += 4;
    cout << stack1 << endl;
    int value;
    (stack2 - value);
    cout << stack2 << endl;
    stack2 = stack2 * 3;
    cout << stack2 << endl;
    return 0;
}