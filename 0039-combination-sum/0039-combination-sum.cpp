#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void solve(vector<int>& in,vector<int>& out,vector<vector<int>>& ans,int i, int sum,int target){
            if(sum==target){
                ans.push_back(out);
                i++;
                return;
            }
            if(sum>target || i >= in.size())return;
            out.push_back(in[i]);
            sum+=in[i];
            solve(in,out,ans,i,sum,target);
            sum-=in[i];
            out.pop_back();
            solve(in,out,ans,i+1,sum,target);
            return;
            
        }
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            vector<int> out;
            int n = nums.size();
            solve(nums,out,ans,0,0,target);
            return ans;

        }
    };
    