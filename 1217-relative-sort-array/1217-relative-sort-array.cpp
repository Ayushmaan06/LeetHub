class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int a : arr1){
            mp[a]++;
        }
        vector<int> res,t;

        for(int a : arr2){
            for(int i = 0 ; i<mp[a]; i++){
                res.push_back(a);
            }
            mp.erase(a);
        }
        for(auto it : mp){
            for(int i=0 ;i<it.second;i++)
            t.push_back(it.first);
        }
        sort(t.begin(),t.end());
        for(int tt:t){
            res.push_back(tt);
        }
        return res;
    }
};