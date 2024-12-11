class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // vector<pair<int,int>> v;
        unordered_map<int,int>m;
    
        // for(int num : nums){
        //     v.push_back({num-k,num+k});
        // }
        
        // for(int i = mi;i<=ma;i++){
        //     m[mi]=0;
        // }
        // for(auto it : v){
        //     m[it.first]+=1;
        //     m[it.second+1]-=1;
        // }
        
        int mi=INT_MAX,ma=INT_MIN;
        for(int num : nums){
            m[num-k]+=1;
            m[num+k+1]-=1;
            mi=min(num,mi);
            ma=max(num,ma);
        }
        mi-=k;ma+=k;
        int x=m[mi];
        for(int i = mi+1 ; i<=ma ; i++){
            m[i]+=m[i-1];
            x=max(x,m[i]);
        }
        return x;

    }
};