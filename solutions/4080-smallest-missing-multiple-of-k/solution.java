class Solution {
    public int missingMultiple(int[] nums, int k) {
        boolean isFound[] = new boolean [201] ;

        int n = nums.length ;

        for(int i = 0 ; i < n ; i++) isFound[nums[i]] = true ;

        int ans = k ;

        while(isFound[ans]) ans += k ;

        return ans ;
    }
}