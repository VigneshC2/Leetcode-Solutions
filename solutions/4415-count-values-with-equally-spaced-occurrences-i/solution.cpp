class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size() ;

        unordered_map<int , int> freq ;
        unordered_map<int , vector<int>> first_occ ;

        for(int i = 0 ;i < n ; i++){
            int ele = nums[i] ;
            freq[ele] += 1 ;
            first_occ[ele].push_back(i) ;
        }

        int ans = 0 ;

        for(auto&it : freq){
            if(it.second == 3){
                int i = first_occ[it.first][0] ;
                int j = first_occ[it.first][1] ;
                int k = first_occ[it.first][2] ;

                if(j - i == k - j) ans += 1 ;
            }
        }

        return ans ;
    }
};