#include <iostream>
#include <queue>

using namespace std;

//Messy.. 
class MyStack {
public:
    queue<int> q;

    MyStack() {

    }

    void push(int x) {
        q.push(x);
    }

    int pop() {
        int a = q.back();
        int n = q.size();
        queue<int> qTemp;


        for (int i = 0; i < n - 1; i++)
        {
            qTemp.push(q.front());
            q.pop();
        }

        q = qTemp;

        return a;
    }

    int top() {
        return q.back();
    }

    bool empty() {
        return q.empty();
    }
};

//Solution:
class MyStack2 {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int topValue = q1.front();
        q1.pop();
        return topValue;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main()
{
    MyStack2 a = MyStack2();
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    a.pop();
    a.pop();
}
