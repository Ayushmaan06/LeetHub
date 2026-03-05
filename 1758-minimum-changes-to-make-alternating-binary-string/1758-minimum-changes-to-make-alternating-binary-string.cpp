class Solution {
public:
    int minOperations(string s) {//ans1 0101 ans2 1010
        int ans1=0,ans2=0,i=0;
        for(char c : s){
            if(i%2){
                if(c=='0')ans1++;
                else ans2++;
            }
            else{
                if(c=='0')ans2++;
                else ans1++;
            }
            i++;
        }
        cout<<ans1<<" "<<ans2;
        return min(ans1,ans2);
    }
};