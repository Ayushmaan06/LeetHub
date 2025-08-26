class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDia = -1, maxArea = 0;
        for (auto &d : dimensions) {
            int dia = d[0]*d[0] + d[1]*d[1];
            int area = d[0]*d[1];
            if (dia > maxDia || (dia == maxDia && area > maxArea)) {
                maxDia = dia;
                maxArea = area;
            }
        }
        return maxArea;
    }
};
