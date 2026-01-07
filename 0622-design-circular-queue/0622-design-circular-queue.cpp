class MyCircularQueue {
public:
    vector<int> v;
    int head, sz, n;

    MyCircularQueue(int k) {
        v.resize(k);
        n = k;
        head = 0;
        sz = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        // Rear is at (head + sz) % n. Since we add 1, new element at:
        v[(head + sz) % n] = value;
        sz++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % n;
        sz--;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : v[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : v[(head + sz - 1) % n];
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == n;
    }
};