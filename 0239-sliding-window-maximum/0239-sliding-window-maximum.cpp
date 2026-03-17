class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        stack<int> st;int n = nums.size();
        vector<int> nge(n);
        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && nums[i] > nums[st.top()])st.pop();
            if(st.empty())nge[i]=-1;
            else nge[i]=st.top();
            st.push(i);
        }
        vector<int> res(n-k+1);
        for(int i = 0 ; i <= n-k ; i++ ){
            if(nge[i]==-1)res[i]=nums[i];
            else{
                int j=i,p;
                while(nge[j] < i+k && nge[j] != -1){
                    j = nge[j];
                }
                res[i] = nums[j];
            }
        }
        return res;
    }
};