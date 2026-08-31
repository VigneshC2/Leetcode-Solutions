class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size() ;
        int m = l.size() ;

        vector<bool> ans(m , false) ;

        for(int q = 0 ; q< m ; q++){
            int a = l[q] ;
            int b = r[q] ;

            vector<int> temp ;

            for(int i = a ; i <= b ; i++){
                temp.push_back(nums[i]) ;
            }

            sort(temp.begin() , temp.end()) ;

            if(temp.size() <= 1){
                ans[q] = true ;
                continue ;
            }

            int d = temp[1] - temp[0] ;

            bool f = true ;
            for(int i = 1 ; i < temp.size() ; i++){
                if(temp[i] - temp[i-1] != d){
                    f = false ;
                    break ;
                }
            }

            ans[q] = f ;
        }

        return ans ;
    }
};