class Solution(object):
    def findFarmland(self, land):
        """
        :type land: List[List[int]]
        :rtype: List[List[int]]
        """
        n = len(land)
        m = len(land[0])
        
        ans = []

        for r in range(n):
            for c in range(m) :


                if (land[r][c] == 0) :
                    continue

                if (r > 0 and land[r - 1][c] == 1) :
                    continue
                if (c > 0 and land[r][c - 1] == 1) :
                    continue

                c2 = c 
                while (c2 + 1 < m and land[r][c2 + 1] == 1):
                    c2 += 1
                

                r2 = r
                while (r2 + 1 < n and  land[r2 + 1][c] == 1):
                    r2 += 1 
                

                ans.append([r, c, r2, c2])

        return ans 