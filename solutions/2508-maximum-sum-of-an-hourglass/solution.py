class Solution(object):
    def maxSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid) 
        m = len(grid[0]) 

        ans = 0 

        for i in range(1 , n-1):
            for j in range(1 , m-1):
                tot = grid[i][j] 

                for k in [-1,0,1] : 
                    tot += grid[i-1][j+k]
                    tot += grid[i+1][j+k]
                
                ans = max(ans , tot)

        return ans 