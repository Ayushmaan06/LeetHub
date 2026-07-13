class Solution {
public:
    std::vector<int> sequentialDigits(int low, int high) {
        std::vector<int> result;
        for (int start = 1; start <= 9; ++start) {
            int num = start;
            for (int next = start + 1; next <= 9; ++next) {
                num = num * 10 + next;
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        std::sort(result.begin(), result.end()); // Sort the result vector
        return result;
    }
};