class Solution {
public:
    int findTheWinner(int n, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int w = 0;
        for(int i = 1 ; i <= n;i++){
            w=(w+k)%i;
        }
        return w+1;
    }
};