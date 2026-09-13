class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size() ;
        unordered_map<int , vector<int>> occ ;

        for(int i = 0 ;i < n ; i++){
            int ele = nums[i] ;
            occ[ele].push_back(i) ;
        }

        int ans = 0 ;

        for(auto& it : occ){
            if(it.second.size() >= 3){
                int d = it.second[1] - it.second[0] ;
                bool f = true ;
                for(int i = 1 ; i < it.second.size() ; i++){
                    if(it.second[i] - it.second[i-1] != d){
                        f = false ;
                        break ;
                    }
                }
                if(f){
                    ans += 1 ;
                }
            }
        }

        return ans ;
    }
};