class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        for(int& f : fruits){
            for(int& b : baskets){
                if(b>=f){
                    b=-1;
                    f=-1;
                    break;
                }
                
            }

        }
        int ans=0;
        for(int f : fruits){
            if(f>-1)ans++;
        }
        return ans;
    }
};