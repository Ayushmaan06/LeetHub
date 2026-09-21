class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0]*k
        dp = [0]*k
        for num in nums:
            v = num%k
            ndp = [0]*k
            for r in range(k):
                if dp[r]>0 :
                    ndp[(r*v)%k]+=dp[r]
            ndp[v]+=1
            for r in range(k):
                ans[r]+=ndp[r]
            dp=ndp
        return ans