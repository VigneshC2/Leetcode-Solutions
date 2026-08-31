class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size() ;
        int m = isWater[0].size() ;

        vector<vector<int>> ans(n , vector<int> (m , -1)) ;

        set<pair<int,int>> water_cells ;

        queue<pair<int,int>> q ;

        int val = 0 ;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m ; j++){
                if(isWater[i][j]){
                    ans[i][j] = 0 ;
                    q.push({i , j}) ;
                }
            }
        }

        // pair<int,int> temp = {-1,-1};

        // q.push(temp) ;

        vector<int> dx = {0 , 0 , 1 , -1} ;
        vector<int> dy = {1 , -1, 0 , 0} ;

        while(!q.empty()){
            auto f = q.front() ;
            q.pop() ;
            int i = f.first ;
            int j = f.second ;

            // if(i == -1){
            //     val += 1 ;
            //     q.push(temp) ;
            //     continue ;
            // }

            // if(ans[i][j] < val) continue ;

            // ans[i][j] = min(ans[i][j] , val) ;
            // ans[i][j] = val ;

            for(int t = 0 ; t < 4 ; t++){
                int a = i + dx[t] ;
                int b = j + dy[t] ;
                
                if(a < 0 || a >= n || b < 0 || b >= m) continue ;
                if(ans[a][b] == -1){
                    ans[a][b] = ans[i][j] + 1 ;
                    q.push({a,b}) ;
                }
            }
        }

        return ans ;
    }
};