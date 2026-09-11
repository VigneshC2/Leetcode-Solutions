class Solution(object):
    def corpFlightBookings(self, bookings, n):
        """
        :type bookings: List[List[int]]
        :type n: int
        :rtype: List[int]
        """
        ans = [0] * n

        for b in bookings :
            ans[b[0] - 1] += b[2]
            if(b[1] == n):
                continue
            ans[b[1]] -= b[2]
        
        curr = 0 

        for i in range(n) :
            curr += ans[i]
            ans[i] = curr
        
        return ans