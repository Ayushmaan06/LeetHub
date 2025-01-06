class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> l;
        vector<int> res;
        int n = boxes.length();
        vector<int> ans(n,0);
        for(int i = 0 ; i < n ; i++){
            if(boxes[i]=='1'){
                l.push_back(i);
            }
        }
        int k = l.size();
        vector<int> r(k+1,0);
        for(int i = 0 ; i < k ; i++){
            r[i+1]=r[i]+l[i];
        }
        for(int i = 0 ; i < n ; i++){
            int j=lower_bound(l.begin(), l.end(), i)-l.begin();
            // if(l[j]>i&&j>0)j--;
            int ans = r[k]-r[j]-i*(k-j);
            if(j>0){
                ans+=abs(r[j] - i*j);
            }
            res.push_back(ans);
        }

        return res;
    }
};