int max(int a , int b){
    return (a > b) ? a : b ;
}

int min(int a , int b){
    return (a < b) ? a : b ;
}

int minimumDeletions(int* nums, int numsSize) {
    int max_idx = 0 ;
        int min_idx = 0 ;
        int n = numsSize ;
        
        int max_ele = nums[0] ;
        int min_ele = nums[0] ;

        for(int i = 0 ; i < n ; i++){
            int ele = nums[i] ;
        
            if(ele > max_ele){
                max_idx = i ;
                max_ele = ele ;
            }

            if(ele < min_ele){
                min_idx = i ;
                min_ele = ele ;
            }
        }

        int d1s = max_idx + 1 ;
        int d1b = n - max_idx ;

        int d2s = min_idx + 1 ;
        int d2b = n - min_idx ;

        int ans = max(d1s , d2s) ;
        ans = min(ans , max(d1b , d2b) ) ;

        ans = min(ans , d1s + d2b) ;
        ans = min(ans , d2s + d1b) ;

        return ans ;
}