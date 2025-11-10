class BIT {
private:
    int n;
    vector<int> tree;
public:
    BIT(int n): n(n), tree(n+1, 0) {}
    void update(int i, int delta) {
        i++; // BIT is 1-indexed internally
        while(i <= n) {
            tree[i] += delta;
            i += i & (-i);
        }
    }
    int query(int i) {
        int sum = 0;
        i++; 
        while(i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
    int queryRange(int l, int r) {
        if(l > r) return 0;
        return query(r) - (l == 0 ? 0 : query(l - 1));
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxv = 0;
        for (int num : nums) {
            maxv = max(maxv, num);
        }
        vector<vector<int>> pos(maxv + 1);
        for (int i = 0; i < n; i++) {
            int v = nums[i];
            if(v != 0) {
                pos[v].push_back(i);
            }
        }
        BIT bit(n);
        for (int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                bit.update(i, 1);
            }
        }
        
        int ops = 0;
        for (int v = 1; v <= maxv; v++) {
            if(pos[v].empty()) continue;
            int segs = 0;
            int prev = -1;
            for (int idx : pos[v]) {
                if(prev == -1) {
                    segs++;
                } else {
                    if(bit.queryRange(prev + 1, idx - 1) > 0) {
                        segs++;
                    }
                }
                prev = idx;
            }
            ops += segs;
            for (int idx : pos[v]) {
                if(bit.queryRange(idx, idx) == 0) {
                    bit.update(idx, 1);
                }
            }
        }  
        return ops;
    }
};