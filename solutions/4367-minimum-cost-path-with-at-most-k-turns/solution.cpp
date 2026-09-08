class Solution {
public:
    vector<int> dx = {0 , 0 , 1 , -1} ;
    vector<int> dy = {1 , -1, 0, 0} ;


    int helper(vector<vector<int>>& grid, int k , int i , int j , int dir){
        if(k < 0){
            return 1e9 ;
        }

        int n = grid.size() ;
        int m = grid[0].size() ;

        if(i == n-1 && j == m-1){
            if(k >= 0) return grid[i][j] ;
            else return 1e9 ;
        }

        if(i < 0 || i >= n || j < 0 || j >= m) return 1e9 ;

        int ans = grid[i][j] ;
        int temp = 1e9 ;
        for(int t = 0 ; t < 4 ; t += 1){
            int a = i + dx[t] ;
            int b = j + dy[t] ;
            if(dir == t){
                temp = min(temp , helper(grid , k , a , b , dir)) ;
            }
            else{
                temp = min(temp , helper(grid , k-1 , a , b , t)) ;
            }
        }

        if(temp == 1e9) return temp ;

        ans += temp ;

        return ans ;
    }

    // vector<vector<vector<vector<int>>>> dp ; 
    int dp[76][76][76][4] ;
    // k , i , j , dir

    int helper_dp(vector<vector<int>>& grid, int k , int i , int j , int dir){
        if(k < 0){
            return 1e9 ;
        }

        int n = grid.size() ;
        int m = grid[0].size() ;

        if(i == n-1 && j == m-1){
            if(k >= 0) return grid[i][j] ;
            else return 1e9 ;
        }

        if(i < 0 || i >= n || j < 0 || j >= m) return 1e9 ;

        if(dp[k][i][j][dir] != -1) return dp[k][i][j][dir] ;

        int ans = grid[i][j] ;
        int temp = 1e9 ;
        for(int t = 0 ; t < 4 ; t += 1){
            int a = i + dx[t] ;
            int b = j + dy[t] ;
            if(dir == t){
                temp = min(temp , helper_dp(grid , k , a , b , dir)) ;
            }
            else{
                temp = min(temp , helper_dp(grid , k-1 , a , b , t)) ;
            }
        }

        if(temp == 1e9) return dp[k][i][j][dir] = temp ;

        ans += temp ;

        return dp[k][i][j][dir] = ans ;
    }
    

    int minCost(vector<vector<int>>& grid, int k) {
        int ans = 1e9 ;
        int n = grid.size() ;
        int m = grid[0].size() ;

        // dp = vector<vector<vector<vector<int>>>> (k + 1 , vector<vector<vector<int>>> (n+1 , vector<vector<int>> (m + 1 , vector<int> (4 , -1)))) ;
        // memset(dp , -1 , ((n+1) * (m+1) * (k) * 4)) ;
        memset(dp, -1, sizeof(dp));

        for(int i = 0 ; i < 4 ; i++){
            ans = min(ans , helper_dp(grid , k , 0, 0 , i)) ;
        }

        if(ans >= 1e9) return -1 ;

        return ans ;
    }
};