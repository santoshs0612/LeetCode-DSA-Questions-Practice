class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        maxProd = -1e9
        leftProd = 1
        rightProd= 1
        n = len(nums)
        i=0
        for i in range(n):
            if leftProd == 0:
                leftProd = 1
            if rightProd == 0:
                rightProd =1
            leftProd*=nums[i]
            rightProd*=nums[n-i-1]

            maxProd = max(maxProd, max(leftProd, rightProd))
        return maxProd