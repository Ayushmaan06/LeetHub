#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int sumOfDigits(int number) {
        int sum = 0;
        while (number != 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int num : nums) {
            int s = sumOfDigits(num);
            m[s].push_back(num);
        }

        int ans = -1;
        for (auto& it : m) {
            if (it.second.size() > 1) {
                sort(it.second.begin(), it.second.end(), greater<int>());
                ans = max(ans, it.second[0] + it.second[1]);
            }
        }
        return ans;
    }
};