class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> s,g;
        int c = 0 ;
        for(int n : nums){
            if(n<pivot)s.push_back(n);
            else if (n>pivot) g.push_back(n);
            else c++;
        }
        while(c--)s.push_back(pivot);
        for(int i :g )s.push_back(i);
        return s;
    }
};