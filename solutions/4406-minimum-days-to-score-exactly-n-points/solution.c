int min(int a , int b){
    return (a < b) ? a : b ;
}

int allStreaks[1000] ;
    int dp[100001] ;
    int a ;

    int getIndex(int n) {
        int low = 1;
        int high = a - 1;
        int ans = 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(allStreaks[mid] <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int helper(int n){
        if(n <= 0) return 0 ;
        if(dp[n] != -1) return dp[n] ;
        int ans = 1e9 ;
        int idx = getIndex(n) ;
        int limit = 3 ;
        for(int i = idx ; i>=1 ; i--){
            if(allStreaks[i] == n){
                ans = i ;
                break ;
            }
            if(allStreaks[i] > n){
                break ;
            }
            int temp = i + 1 + helper(n - allStreaks[i]) ;
            ans = min(ans , temp) ;
            limit -= 1 ;
            if(limit == 0) break ;
        }
        return dp[n] = ans ;
    }
    int minDays(int n) {
        int s = 0 ;
        a = 0 ;
        for(int i = 0 ; i <= n ; i++){
            s += i ;
            if(s == n){
                return i ;
            }
            if(s > n){
                break ;
            }
            allStreaks[i] = (s) ;
            a += 1 ;
        }

        memset(dp , -1 , sizeof(dp)) ;

        return helper(n) ;

    }