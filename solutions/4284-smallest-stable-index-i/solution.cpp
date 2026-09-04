class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int sum = 0 ;

        int n = nums.size() ;

        vector<int> max_seen(n) ;

        max_seen[0] = nums[0] ;

        for(int i = 1 ; i < n ; i++){
            max_seen[i] = max(nums[i] , max_seen[i-1]) ;
        }

        int curr = nums.back() ;

        int ans = -1 ;
        for(int i = n -1 ; i>= 0 ; i--){
            curr = min(curr , nums[i]) ;

            int score = max_seen[i] - curr ;

            if(score <= k) ans = i ;
        }

        return ans ;
    }
};