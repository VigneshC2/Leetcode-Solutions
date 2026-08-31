class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int ,vector<int>> adj ;

        for(auto& p : adjacentPairs){
            int u = p[0] ;
            int v = p[1] ;

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        unordered_map<int,bool> isFound ;

        vector<int> ans ;

        queue<int> q ;

        for(auto & it : adj){
            int ele = it.first ;
            if(it.second.size() == 1){
                q.push(ele) ;
                break ;
            }
        }

        while(!q.empty()){
            int ele = q.front() ;
            q.pop() ;

            ans.push_back(ele) ;
            isFound[ele] = true ;

            for(auto& neigh : adj[ele]){
                if(isFound[neigh]) continue ;
                q.push(neigh) ;
            }
        }

        return ans ;
    }
};