class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int  start = 0;
        int max_count = 0;

        for (int  end = 0;  end < nums.size(); ++ end) {
            if (nums[ end] == max_num) {
                max_count++;
            }

            while (max_count >= k) {
                count += nums.size() -  end;
                if (nums[ start] == max_num) {
                    max_count--;
                }
                 start++;
            }
        }

        return count;
    }
};