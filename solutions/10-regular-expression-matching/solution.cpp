class Solution {
public:
    vector<vector<int>> dp ;
    bool helper(string& s , string& p , int idx1 , int idx2){
        int n1 = s.size() ;
        int n2 = p.size() ;

        if(idx1 == n1 && idx2 == n2){
            return true ;
        }

        if(idx2 == n2){
            return false ;
        }

        if(idx1 == n1){
            if(idx2 < n2-1){
                if(p[idx2 + 1] == '*'){
                    return helper(s , p , idx1 , idx2 + 2) ;
                }
            }
            return false ;
        }



        if(idx2 < n2-1){
            if(p[idx2 + 1] == '*'){
                bool not_take = helper(s , p , idx1, idx2 + 2) ;
                if(not_take) return true ;
                if(p[idx2] == s[idx1] || p[idx2] == '.'){
                    return helper(s , p , idx1 + 1 , idx2) ;
                }
                return false ;
            }
        }

        if(s[idx1] == p[idx2] || p[idx2] == '.'){
            return helper(s , p , idx1 + 1 , idx2 + 1) ;
        }

        return false ;
    }

    bool helper_dp(string& s , string& p , int idx1 , int idx2){
        int n1 = s.size() ;
        int n2 = p.size() ;

        if(idx1 == n1 && idx2 == n2){
            return true ;
        }

        if(idx2 == n2){
            return false ;
        }

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2] ;

        if(idx1 == n1){
            if(idx2 < n2-1){
                if(p[idx2 + 1] == '*'){
                    return dp[idx1][idx2] = helper_dp(s , p , idx1 , idx2 + 2) ;
                }
            }
            return false ;
        }



        if(idx2 < n2-1){
            if(p[idx2 + 1] == '*'){
                bool not_take = helper_dp(s , p , idx1, idx2 + 2) ;
                if(not_take) return dp[idx1][idx2] = true ;
                if(p[idx2] == s[idx1] || p[idx2] == '.'){
                    return dp[idx1][idx2] = helper_dp(s , p , idx1 + 1 , idx2) ;
                }
                return dp[idx1][idx2] = false ;
            }
        }

        if(s[idx1] == p[idx2] || p[idx2] == '.'){
            return dp[idx1][idx2] = helper_dp(s , p , idx1 + 1 , idx2 + 1) ;
        }

        return dp[idx1][idx2] = false ;
    }

    bool isMatch(string s, string p) {
        dp = vector<vector<int>> (22 , vector<int> (22 , -1)) ;
        return helper_dp(s , p , 0 , 0) ;
    }
};