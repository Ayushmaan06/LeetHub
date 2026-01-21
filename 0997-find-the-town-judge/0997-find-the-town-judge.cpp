class Solution {
public:
    int findJudge(int n, vector<vector<int>>& gifts) {
        unordered_set<int> givers;
        unordered_map<int,int> recievers;
        for(auto it: gifts)givers.insert(it[0]),recievers[it[1]]++;
        for(int i = 1; i <= n ; i++){
            if(givers.count(i))continue;
            if(recievers[i]==n-1)return i;
        }
        return -1;
    }
};