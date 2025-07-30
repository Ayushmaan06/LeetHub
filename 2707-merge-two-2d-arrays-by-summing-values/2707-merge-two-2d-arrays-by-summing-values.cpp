class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int i1=0,i2=0;
        vector<vector<int>> res;
        while(i1<n1&&i2<n2){
            if(nums1[i1][0]==nums2[i2][0]){
                res.push_back({nums1[i1][0],nums1[i1][1]+nums2[i2][1]});
                i1++;i2++;
            }
            else if(nums1[i1][0]<nums2[i2][0]){
                res.push_back({nums1[i1][0],nums1[i1][1]});
                i1++;
            }
            else if(nums2[i2][0]<nums1[i1][0]){
                res.push_back({nums2[i2][0],nums2[i2][1]});
                i2++;
            }
        }
        while(i1<n1){
            res.push_back({nums1[i1][0],nums1[i1][1]});
                i1++;
        }
        while(i2<n2){
            res.push_back({nums2[i2][0],nums2[i2][1]});
                i2++;
        }
        return res;
    }
};