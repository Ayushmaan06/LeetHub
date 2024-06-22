class StockSpanner {
private:
    stack<pair<int, int>> s; // Declare the stack as a private member variable

public:
    StockSpanner() {
        // The stack is now properly accessible throughout the class
    }
    
    int next(int price) {
        int span = 1; // Initialize span for the current price
        // While the stack is not empty and the current price is greater than or equal to the price at the top of the stack
        while (!s.empty() && price >= s.top().first) {
            span += s.top().second; // Add the span of the top element to the current span
            s.pop(); // Remove the top element
        }
        s.push({price, span}); // Push the current price and its calculated span onto the stack
        return span; // Return the span of the current price
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */