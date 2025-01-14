class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> m;
        int n = A.size();
        vector<int> res;
        int ans=0;
        for(int i = 0 ; i < n ; i ++){
            m[A[i]]++;
            if(m[A[i]]==2)ans++;
            m[B[i]]++;
            if(m[B[i]]==2)ans++;
            res.push_back(ans);
        }
        return res;
    }
};