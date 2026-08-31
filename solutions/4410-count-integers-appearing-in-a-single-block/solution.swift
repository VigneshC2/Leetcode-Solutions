class Solution {
    func countSpecialIntegers(_ nums: [Int]) -> Int {
        var n = nums.count ;
        var freq : [Int] = [] ;
        for i in 0..<101 {
            freq.append(0) ;
        }
        for i in 0..<n{
            freq[nums[i]] += 1 ;
        }

        var i = 1 ; 

        var ans = 0 ;
        
        var curr = nums[0] ;
        var len = 1 ;

        while(i < n){
            if(nums[i] == nums[i-1]){
                len += 1 ;
                i += 1 ;
            }
            else{
                if(len == freq[curr]){
                    ans += 1 ;
                }
                len = 1 ;
                curr = nums[i] ;
                i += 1 ;
            }
        }

        if(freq[curr] == len){ ans += 1 ;}

        return ans ;
    }
}