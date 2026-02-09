struct XorTrie {
    // Node structure optimized for memory layout
    struct Node {
        int child[2] = {-1, -1}; // Indices to children (-1 = null)
        int cnt = 0;             // Count of numbers passing through this node
    };

    vector<Node> trie;

    // Constructor: Pre-allocates memory to avoid resizing overhead
    // N = roughly (number of elements * 30). 
    // For 10^5 elements, 3,000,000 is safe.
    XorTrie(int capacity = 3000000) {
        trie.reserve(capacity);
        trie.emplace_back(); // Create root node (index 0)
    }
    
    // Clear trie for reuse in multiple test cases
    void clear() {
        trie.clear();
        trie.emplace_back();
    }

    // Insert a number
    void insert(int num) {
        int curr = 0;
        trie[curr].cnt++; // Increment root count
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (trie[curr].child[bit] == -1) {
                trie[curr].child[bit] = trie.size();
                trie.emplace_back();
            }
            curr = trie[curr].child[bit];
            trie[curr].cnt++;
        }
    }

    // Remove a number (assumes number exists)
    // Lazy deletion: we just decrement counts, we don't actually delete nodes
    void erase(int num) {
        int curr = 0;
        // Optional: Check if empty to prevent underflow
        if (trie[curr].cnt == 0) return; 
        
        trie[curr].cnt--;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            // In a valid erase call, path must exist
            curr = trie[curr].child[bit];
            trie[curr].cnt--;
        }
    }

    // Count how many times 'num' exists in the trie
    int count(int num) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (trie[curr].child[bit] == -1 || trie[trie[curr].child[bit]].cnt == 0) {
                return 0;
            }
            curr = trie[curr].child[bit];
        }
        return trie[curr].cnt;
    }

    // Get Maximum XOR of 'num' against numbers currently in Trie
    int getMax(int num) {
        int curr = 0;
        // If trie is empty, return 0 or handle error
        if (trie[curr].cnt == 0) return 0; 
        
        int max_xor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int desired = 1 - bit; // We want the opposite bit
            
            // Go to desired if it exists AND has active numbers
            if (trie[curr].child[desired] != -1 && trie[trie[curr].child[desired]].cnt > 0) {
                max_xor |= (1 << i);
                curr = trie[curr].child[desired];
            } else {
                // Otherwise force to go to the existing path
                curr = trie[curr].child[bit];
            }
        }
        return max_xor;
    }

    // Get Minimum XOR of 'num' against numbers currently in Trie
    int getMin(int num) {
        int curr = 0;
        if (trie[curr].cnt == 0) return 0;

        int min_xor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            
            // We want the SAME bit to minimize XOR (0^0=0, 1^1=0)
            if (trie[curr].child[bit] != -1 && trie[trie[curr].child[bit]].cnt > 0) {
                curr = trie[curr].child[bit];
            } else {
                // If forced to take opposite, we accumulate XOR value
                min_xor |= (1 << i);
                curr = trie[curr].child[1 - bit];
            }
        }
        return min_xor;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        XorTrie trie(nums.size() * 35); 
        vector<vector<int>> v; 
        for(int i = 0; i < queries.size(); i++) v.push_back({queries[i][1], queries[i][0], i});
        sort(v.begin(), v.end()); 
        sort(nums.begin(), nums.end());
        vector<int> res(queries.size());
        int lc = 0, n = nums.size();
        for(auto& q : v) {
            int m = q[0], x = q[1],idx = q[2];
            while(lc < n && nums[lc] <= m) trie.insert(nums[lc++]);
            if(lc == 0) res[idx] = -1;
            else res[idx] = trie.getMax(x);
        }
        return res;
    }
};