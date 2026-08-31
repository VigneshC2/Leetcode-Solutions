class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map < int , unordered_set<int> > mp1 ;

        vector<int> ans(k,0) ;

        for(auto& log : logs){
            int id = log[0] ;
            int time = log[1] ;

            mp1[id].insert(time) ;
        }

        for(auto& it : mp1){
            int idx = it.second.size() ;
            ans[idx-1] += 1 ;
        }

        return ans ;
    }
};