class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int a : arr)mp[a]++;
        priority_queue<int> pq;
        for(auto it : mp)pq.push(it.second);
        int s=0,c=0,n=arr.size()/2;
        while(s<n)s+=pq.top(),pq.pop(),c++;
        return c;
    }
};