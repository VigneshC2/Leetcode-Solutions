class Solution {
public:
    int helper(string& s , string& t , int idx1 , int idx2){
        int n1 = s.size() ;
        int n2 = t.size() ;

        if(idx2 >= n2){
            return 1 ;
        }
        if(idx1 >= n1){
            return 0 ;
        }

        int take = 0 ;
        if(s[idx1] == t[idx2]){
            take = helper(s , t , idx1 + 1 , idx2 + 1) ;
        }

        int not_take = helper(s , t , idx1 + 1 , idx2) ;

        int ans = take + not_take ;

        return ans ;
    }

    int helper_dp(string& s , string& t , int idx1 , int idx2 , vector<vector<int>>& dp){
        int n1 = s.size() ;
        int n2 = t.size() ;

        if(idx2 >= n2){
            return 1 ;
        }
        if(idx1 >= n1){
            return 0 ;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2] ;

        int take = 0 ;
        if(s[idx1] == t[idx2]){
            take = helper_dp(s , t , idx1 + 1 , idx2 + 1 , dp) ;
        }

        int not_take = helper_dp(s , t , idx1 + 1 , idx2 , dp) ;

        int ans = take + not_take ;

        return dp[idx1][idx2] = ans ;
    }

    int numDistinct(string s, string t) {
        int n1 = s.size() ;
        int n2 = t.size() ;
        vector<vector<int>> dp(n1 , vector<int> (n2 , -1)) ;
        return helper_dp(s , t , 0 , 0 , dp) ;
    }
};