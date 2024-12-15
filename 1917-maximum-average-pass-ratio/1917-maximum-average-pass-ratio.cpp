class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };
        
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& cls : classes) {
            double pass = cls[0], total = cls[1];
            pq.push({gain(pass, total), {pass, total}});
        }
        
        while (extraStudents--) {
            auto [currentGain, classData] = pq.top(); pq.pop();
            double pass = classData.first, total = classData.second;
            pass += 1;
            total += 1;
            pq.push({gain(pass, total), {pass, total}});
        }
        
        // Calculate final average ratio
        double ans = 0;
        while (!pq.empty()) {
            auto [_, classData] = pq.top(); pq.pop();
            double pass = classData.first, total = classData.second;
            ans += pass / total;
        }
        return ans / classes.size();
    }
};
