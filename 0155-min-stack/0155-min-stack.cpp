class MinStack {
private:
    stack<int> s1, s2; // s1 is the main stack, s2 keeps track of the minimums

public:
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val); // Always push the value onto the main stack
        if (s2.empty() || val <= s2.top()) {
            // If s2 is empty or val is less than or equal to the current minimum, push it onto s2
            s2.push(val);
        }
    }
    
    void pop() {
        if (s1.top() == s2.top()) {
            // If the top of s1 is the current minimum, pop it from s2 as well
            s2.pop();
        }
        s1.pop(); // Always pop the top from the main stack
    }
    
    int top() {
        return s1.top(); // Return the top of the main stack
    }
    
    int getMin() {
        return s2.top(); // The top of s2 is the current minimum
    }
};