#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 0;

        // Handle 1s separately as 1^2 = 1
        auto it1 = counts.find(1);
        if (it1 != counts.end()) {
            int c = it1->second;
            if (c % 2 == 1) {
                max_len = max(max_len, c);
            } else {
                max_len = max(max_len, c - 1);
            }
        }

        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            int current_len = 0;
            long long curr = val;

            while (true) {
                if (curr > 1000000000LL) {
                    current_len -= 1;
                    break;
                }
                auto it = counts.find(curr);
                if (it != counts.end()) {
                    if (it->second >= 2) {
                        current_len += 2;
                        curr = curr * curr;
                    } else {
                        current_len += 1;
                        break;
                    }
                } else {
                    current_len -= 1;
                    break;
                }
            }
            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};