class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        stack<int> st;
        vector<int> ngr(n,-1),res,ngl;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
            if(st.empty())ngr[i]=-1;
            else ngr[i]=st.top();
            st.push(i);
        }
        // while(!st.empty())st.pop();
        // for(int i = 0;i<n;i++){
        //     while(!st.empty() && nums[st.top()]<nums[i])st.pop();
        //     if(st.empty())ngl[i]=-1;
        //     else ngl[i]=st.top();
        //     st.push(i);
        // }
        for(int i = 0 ; i < n-k+1 ; i++){
            int nr=ngr[i];
            if(nr>=i+k || nr==-1){nr=i;res.push_back(nums[nr]);continue;}
            int p;
            while(nr!=-1 && nr<i+k)p=nr,nr=ngr[nr];
            if(nr!=-1 && nr<i+k)res.push_back(nums[nr]);
            else res.push_back(nums[p]);
        }
        return res;
    }
};