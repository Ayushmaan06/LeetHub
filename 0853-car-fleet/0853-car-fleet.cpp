class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) cars.push_back({p[i], (double)(t - p[i]) / s[i]});
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double maxTime = 0;
        for (int i = 0; i < n; i++) {
            if (cars[i].second > maxTime) {
                fleets++;
                maxTime = cars[i].second;
            }
        }
        return fleets;
    }
};
