class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans ;

        unordered_map<int,vector<int> > mp ;

        int n = groupSizes.size() ;

        for(int i = 0 ; i < n ; i++){
            int g = groupSizes[i] ;

            mp[g].push_back(i) ;

            if(mp[g].size() == g){
                ans.push_back(mp[g]) ;
                mp[g] = {} ;
            }
        }

        return ans ;
    }
};