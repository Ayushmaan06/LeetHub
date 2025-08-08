#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int total = n1 + n2;
        int half = (total + 1) / 2;  
        int l = 0, r = n1;
        while(l <= r) {
            int i = (l + r) / 2;      
            int j = half - i;         
            int nums1l = (i == 0) ? INT_MIN : nums1[i-1];
            int nums1r = (i == n1) ? INT_MAX : nums1[i];
            int nums2l = (j == 0) ? INT_MIN : nums2[j-1];
            int nums2r = (j == n2) ? INT_MAX : nums2[j];
            if(nums1l <= nums2r && nums2l <= nums1r) {
                if(total % 2 == 0)
                    return (max(nums1l, nums2l) + min(nums1r, nums2r)) / 2.0;
                else
                    return max(nums1l, nums2l);
            }
            else if(nums1l > nums2r) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};