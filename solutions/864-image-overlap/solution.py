class Solution(object):
    def largestOverlap(self, img1, img2):
        """
        :type img1: List[List[int]]
        :type img2: List[List[int]]
        :rtype: int
        """
        n = len(img1) 

        ans = 0 

        l = -n

        for x in range(l , n) :
            for y in range(0 , n) :
            
                count = 0 

                for i in range(0 , n) :
                    for j in range(0 , n) :

                        a = i + x 
                        b = j + y 
                        if(a < 0 or b < 0 or a >= n or b >= n) :
                            continue 
                        if((img2[i][j] == 1) and (img1[a][b] == img2[i][j])):
                            count += 1 
                        
                    
                

                if(count > ans):
                    ans = count 
                
            
        

        for x in range(l , n) :
            for y in range(0 , n) :
            
                count = 0 

                for i in range(0 , n) :
                    for j in range(0 , n) :

                        a = i + x 
                        b = j + y 
                        if(a < 0 or b < 0 or a >= n or b >= n) :
                            continue 

                        if((img1[i][j] == 1) and (img2[a][b] == img1[i][j])):
                            count += 1 
                    
                

                if(count > ans):
                    ans = count 
            
        

        return ans 