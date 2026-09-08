class Solution(object):
    def countGoodRotations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)

        sum1 = 0 
        for i in range(n//2):
            sum1 += nums[i]

        tot = sum(nums)

        i = 0 
        j = n // 2 
        ans = 0 

        while (j < n) :
            if(sum1 != tot - sum1):
                ans += 1
            sum1 += nums[j]
            sum1 -= nums[i]
            i += 1 
            j += 1

        return ans 