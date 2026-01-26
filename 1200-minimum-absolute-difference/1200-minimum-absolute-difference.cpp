class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mid=INT_MAX,n=arr.size();
        for(int i =1 ; i < n ; i++) mid=min(mid,arr[i]-arr[i-1]);
        vector<vector<int>> res;
        for(int i = 1 ; i < n ; i++){
            if(arr[i]-arr[i-1]==mid)res.push_back({arr[i-1],arr[i]});
        }
        return res;
    }
};