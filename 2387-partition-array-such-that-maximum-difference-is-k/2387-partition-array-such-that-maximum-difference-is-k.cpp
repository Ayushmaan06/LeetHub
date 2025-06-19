class Solution {
public:
    static int partitionArray(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return 1;

        int freq[100001] = {0}, xMax = -1;
        for (int x : nums) {
            freq[x]++;
            xMax = max(xMax, x);
        }

        int partitions = 0;
        for (int x = 0; x <= xMax;) {
            while (x <= xMax && freq[x] == 0)
                x++;
            if (x > xMax)
                break;

            int end = x + k;
            partitions++;
            x = end + 1;
        }
        return partitions;
    }
};