class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int x = low; x <= high; x++) {
            string s = to_string(x);
            if (s.size() % 2 != 0) continue;
            int mid = s.size() / 2;
            int sumFirst = 0, sumSecond = 0;
            for (int i = 0; i < mid; i++) {
                sumFirst += s[i] - '0';
            }
            for (int i = mid; i < s.size(); i++) {
                sumSecond += s[i] - '0';
            }
            if(sumFirst == sumSecond)
                count++;
        }
        return count;
    }
};