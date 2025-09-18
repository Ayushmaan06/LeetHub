class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(char c : n){
            int a = c-'0';ans=max(ans,a);
        }
        return ans;
    }
};