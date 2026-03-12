class DSU {
private:
    vector<int> parent;
    vector<int> rank;  // For union by rank
    vector<int> size;  // For union by size

public:
    // Constructor: initialize DSU with n elements (0-indexed)
    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Path compression find
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }

    // Union by rank: attach tree with lower rank under tree with higher rank
    void unionByRank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }

    // Union by size: attach tree with smaller size under tree with larger size
    void unionBySize(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

    int getSize(int a) {
        return size[find(a)];
    }
    void reset(int a){parent[a]=a;}
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int j =0;
        if(nums.size()==0)return 0;
        unordered_map<int,int> mp;
        for(int i : nums)
            if(mp.find(i)==mp.end())mp[i]=j++;
        DSU dsu(j);
        for(int i : nums){
            if(mp.find(i-1)!=mp.end())dsu.unionBySize(mp[i],mp[i-1]);
            if(mp.find(i+1)!=mp.end())dsu.unionBySize(mp[i],mp[i+1]);
        }
        int ans=-1;
        for(int i : nums)ans=max(ans,dsu.getSize(mp[i]));
        return ans;
    }
};