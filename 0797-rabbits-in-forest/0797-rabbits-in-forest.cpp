class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        for(int a : answers){
            mp[a]++;
        }
        int ans=0;
        for(auto it : mp){
            if(it.first+1>=it.second)ans+=it.first+1;
            else{
                int q = (it.second)/(it.first+1), r = (it.second)%(it.first+1);
                ans+=(it.first+1)*q;
                if(r)ans+=(it.first+1);
            }
        }
        return ans;
    }
};