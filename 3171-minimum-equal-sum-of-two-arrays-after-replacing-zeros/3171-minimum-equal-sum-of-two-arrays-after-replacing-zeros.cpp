class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(nums1.begin(), nums1.end(), 0LL);
        long long s2 = accumulate(nums2.begin(), nums2.end(), 0LL);
        int c1 = count(nums1.begin(), nums1.end(), 0);
        int c2 = count(nums2.begin(), nums2.end(), 0);
        if(s1 > s2) {
            swap(s1, s2);
            swap(c1, c2);
        }
        if(c1 == 0 && c2 == 0) {
            return (s1 == s2) ? s1 : -1;
        }
        if(c2 == 0) {
            int diff = s2 - s1;
            if(diff < c1) return -1; 
            return s2;
        }
        if(c1 == 0) {
            if(s1 != s2) return -1;
            return s1;
        }
        long long diff = s2 - s1;
        long long X = max((long long)c1, diff + (long long)c2);
        return s1 + X;
    }
};