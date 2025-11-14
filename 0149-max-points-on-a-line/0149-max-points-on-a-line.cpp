class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n==1)    return 1;
        int maxPoints = 0;
        for(int i = 0 ; i < n; i++){
            unordered_map<double, int> m;
            for(int j = i+1; j<n; j++){
                double slope = (points[j][0] == points[i][0]) ? INT_MAX : 
                               (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                m[slope]++;
            }
            for(auto it = m.begin(); it != m.end(); it++)
                maxPoints = max(maxPoints, it->second + 1);
        }
        return maxPoints;
    }
};