// Last updated: 2/11/2026, 10:34:49 PM
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1, s2;

    // Helper to move elements from input to output stack
    void move() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        move();
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        move();
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};