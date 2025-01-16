class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size(),x=0;
        if(n1%2){
            for(int i = 0 ; i < n2 ; i++){
                x^=nums2[i];
            }
        }
        if(n2%2){
            for(int i = 0 ; i < n1 ; i++){
                x^=nums1[i];
            }
        }
        return x;
    }
};