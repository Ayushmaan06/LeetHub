bool isc(int i, int n){
    if(i>=0 && i<n)return true;
    return false;
}
class Solution {
public:
    bool canReach(vector<int>& arr, int st) {
        int n = arr.size();
        if(arr[st]==0)return true;
        queue<int> q;
        q.push(st);
        vector<bool> v(n,false);
        v[st]=true;
        while(!q.empty()){
            int x = q.front();q.pop();
            if(arr[x]==0)return true;
            int l = x + arr[x], r = x - arr[x];
            if(isc(l,n) && !v[l]){
                v[l]= true;
                q.push(l);
            }
            if(isc(r,n) && !v[r]){
                v[r]= true;
                q.push(r);
            }
        }
        return false;
    }
};