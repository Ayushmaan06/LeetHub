class Solution {
public:
    string intToBinary(int n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) {
            result.push_back('0' + (n % 2));
            n /= 2;
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
    int minimumOneBitOperations(int k) {
        string s = intToBinary(k);
        int n = s.size();
        int ans=0,c=0;
        for(int i = 0 ; i <n ; i++){
            if(s[i]=='1'){
                int x = 1<<(n-i-1);
                x=2*x-1;
                if(c%2)ans-=x;
                else ans+=x;
                c++;
            }
        }
        return ans;
    }
};
// 0 = 0
// 1 = 1
// 2 = 3

// 3 = 2 
// 4 = 7
// 5 = 6 101
// 6 = 4
// 7 = 5

// 8 = 15
// 9= 14
// 1001
// 1011
// 1010
// 1110
// 1111
// 1101
// 1100
// 0100
// 0101
// 0111
// 0110
// 0010
// 0011
// 0001
// 0000

// 156 = 10011100
// 255-31+15-7