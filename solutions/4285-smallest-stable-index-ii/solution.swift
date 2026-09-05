class Solution {
    func firstStableIndex(_ nums: [Int], _ k: Int) -> Int {
        var sum = 0 ;

        var n = nums.count ;

        var max_seen : [Int] = [nums[0]] ;

        // max_seen[0] = nums[0] ;

        for i in 1..<n{
            max_seen.append(0) ;
            max_seen[i] =  max_seen[i-1];
            if(nums[i] > max_seen[i]) {max_seen[i] = nums[i] ;}
        }

        var curr = nums[n-1] ;

        var ans = -1 ;
        for j in 0..<n {
            // curr = min(curr , nums[i]) ;
            var i = n-1-j ;
            if(curr > nums[i]) {curr = nums[i] ;}

            var score = max_seen[i] - curr ;

            if(score <= k){ ans = i ;}
        }

        return ans ;
    }
}