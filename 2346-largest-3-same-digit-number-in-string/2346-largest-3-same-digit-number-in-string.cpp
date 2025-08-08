class Solution {
public:
    string largestGoodInteger(string num) {
        string ma = "";
        int m = -1;
        for (int i = 2; i < num.length(); i++) {
            if (num[i] == num[i-1] && num[i-1] == num[i-2]) {
                string temp = string(3, num[i]);  
                int k = stoi(temp);
                if (k > m) {
                    m = k;
                    ma = temp;
                }
            }
        }
        return ma;
    }
};
