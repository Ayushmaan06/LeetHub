class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> result;
        int sum = 0, m = rolls.size();

        for (int roll : rolls) {
            sum += roll;
        }

        int totalSum = mean * (m + n);

        int missingSum = totalSum - sum;

        if (missingSum < n || missingSum > 6 * n) {
            return result; 
        }

        int quotient = missingSum / n;
        int remainder = missingSum % n;
        
        for (int i = 0; i < n; ++i) {
            if (i < remainder) {
                result.push_back(quotient + 1);
            } else {
                result.push_back(quotient);
            }
        }
        
        return result;
    }
};