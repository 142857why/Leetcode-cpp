#include <iostream>
#include <queue>

using namespace std;
class MyStack1 {
private:
    queue<int> q1, q2;
public:
    explicit MyStack1() = default;
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }

    int pop() {
        int r = q1.front();
        q1.pop();
        return r;
    }

    int top() {
        int r = q1.front();
        return r;
    }

    bool empty() const{
        return q1.empty();
    }
};

class MyStack2 {
private:
    queue<int> q;

public:
    explicit MyStack2() = default;

    void push(int x) {
        unsigned n = q.size();
        q.push(x);
        for (unsigned i = 0; i < n; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int r = q.front();
        q.pop();
        return r;
    }

    int top() const{
        return (q.front());
    }

    bool empty() const {
        return q.empty();
    }
};
int main() {
//    MyStack1 *obj = new MyStack1();
    MyStack2 *obj = new MyStack2();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    cout << obj->pop() << endl;
    obj->push(5);
    cout << obj->pop() << endl;
    return 0;
}

