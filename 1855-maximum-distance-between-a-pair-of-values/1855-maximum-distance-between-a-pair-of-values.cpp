class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int ans=INT_MIN;
        // for(int i = 0 ; i < nums2.size(); i++){
        //     int j = lower_bound(nums1.begin()+i, nums1.end(),nums2[i])-nums1.begin();
        //     if(j==nums1.size() || nums1[j]>nums2[i])j--;
        //     ans=max(ans,j-i);
        // }
        // return ans;
        int i = 0, j = 0,max_dist = 0,n1 = nums1.size(),n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) max_dist = max(max_dist, j - i), j++; 
            else i++; 
        }
        return max_dist;

    }
};