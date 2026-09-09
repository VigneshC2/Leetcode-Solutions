class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        unordered_map<string , int> mp ;

        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){
            string temp1 = "" ;
            string temp2 = "" ;


            for(int j = 0 ; j < m ; j++){
                char c1 = '0' + matrix[i][j] ;
                char c2 = '0' + 1 - matrix[i][j] ; 

                temp1 += c1 ;
                temp2 += c2 ;
            }

            mp[temp1] += 1 ;
            mp[temp2] += 1 ;
        }

        for(auto& it : mp){
            ans = max(ans , it.second) ;
        }

        return ans ;
    }
};