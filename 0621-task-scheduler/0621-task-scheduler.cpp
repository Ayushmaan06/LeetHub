class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> counts;
        for (char task : tasks) counts[task]++;
        int mf = 0;
        for (auto const& [task, count] : counts) mf = std::max(mf, count);
        int nmf = 0;
        for (auto const& [task, count] : counts) {
            if (count == mf) nmf++;
        }
        int ct = (mf - 1) * (n + 1) + nmf;
        return std::max((int)tasks.size(), ct);
    }
};