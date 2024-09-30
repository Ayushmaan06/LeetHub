#include <vector>
using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) : maxSize(maxSize), i(0) {
        v.resize(maxSize);
    }
    
    void push(int x) {
        if (i < maxSize) {
            v[i] = x;
            i++;
        }
    }
    
    int pop() {
        if (i > 0) {
            i--;
            return v[i];
        }
        return -1; // Return -1 if the stack is empty
    }
    
    void increment(int k, int val) {
        for (int t = 0; t < k && t < i; t++) {
            v[t] += val;
        }
    }

private:
    vector<int> v;
    int maxSize;
    int i;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k, val);
 */