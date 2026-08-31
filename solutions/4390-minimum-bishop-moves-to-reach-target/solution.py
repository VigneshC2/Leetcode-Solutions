class Solution(object):
    def minBishopMoves(self, source, target):
        """
        :type source: List[int]
        :type target: List[int]
        :rtype: int
        """
        temp1 = source[0] + source[1] 
        temp2 = target[0] + target[1] 

        if((temp1 ^ temp2) % 2 == 1):
            return -1

        if (temp1 == temp2):
            return 1

        temp1 = source[0] - source[1] 
        temp2 = target[0] - target[1] 

        if (temp1 == temp2):
            return 1


        return 2 