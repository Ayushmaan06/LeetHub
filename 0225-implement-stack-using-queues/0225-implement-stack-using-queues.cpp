#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x); // Push x to q2
        while (!q1.empty()) { // Move all elements from q1 to q2
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2); // Swap the names of q1 and q2
    }
    
    int pop() {
        if (q1.empty()) return -1; // If stack is empty, return -1
        int top = q1.front(); // The front of q1 is the top of stack
        q1.pop(); // Remove the top element
        return top;
    }
    
    int top() {
        if (q1.empty()) return -1; // If stack is empty, return -1
        return q1.front(); // The front of q1 is the top of stack
    }
    
    bool empty() {
        return q1.empty(); // Stack is empty if q1 is empty
    }
};