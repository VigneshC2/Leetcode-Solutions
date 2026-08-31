class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n = nums.size() ;
        nums.push_back(lower - 1) ;
        nums.push_back(upper + 1) ;

        sort(nums.begin() , nums.end()) ;

        vector<vector<int>> ans ;

        for(int i = 0 ; i < n+2 ; i++){
            // cout << nums[i] << endl ;
            if(nums[i] > lower){
                if(nums[i] > nums[i-1] + 1){
                    ans.push_back({nums[i-1] + 1 , nums[i] - 1}) ;
                }
            }
            if(nums[i] > upper){
                break ;
            }
        }

        return ans ;
    }
};