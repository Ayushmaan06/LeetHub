#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        for (int num : arr) {
            int remainder = ((num % k) + k) % k; 
            remainderCount[remainder]++;
        }

        for (auto& [remainder, count] : remainderCount) {
            if (remainder == 0) {

                if (count % 2 != 0) return false;
            } else {
                
                if (remainderCount[remainder] != remainderCount[k - remainder]) return false;
            }
        }
        
        return true;
    }
};