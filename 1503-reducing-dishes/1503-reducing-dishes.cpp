class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int ans=INT_MIN;
        for(int i = 0 ; i < s.size() ; i++){
            int t=s[i],d=2;
            for(int j = i+1; j < s.size(); j++){
                t+=s[j]*d;d++;
            }
            ans=max(ans,t);
        }
        if(ans>0)return ans;
        return 0;
    }
};