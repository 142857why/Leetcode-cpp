#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
private:
    stack<int> inStack, outStack;

    void in2Out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:
    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2Out();
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    int peek() {
        if (outStack.empty()) {
            in2Out();
        }
        return outStack.top();
    }

    bool empty() {
        return (inStack.empty() && outStack.empty());
    }

    void print() {
        stack<int> tempIn(inStack);
        stack<int> tempOut(outStack);
        cout << "----InStack----" << endl;
        while (!tempIn.empty()) {
            cout << tempIn.top() << " ";
            tempIn.pop();
        }
        cout << "\n----------------" << endl;

        cout << "----OutStack----" << endl;
        while (!tempOut.empty()) {
            cout << tempOut.top() << " ";
            tempOut.pop();
        }
        cout << "\n-----------------" << endl;
    }
};

int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->print();
    cout << obj->pop() << endl;
    cout << obj->peek() << endl;
    obj->push(5);
    obj->print();
    return 0;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */