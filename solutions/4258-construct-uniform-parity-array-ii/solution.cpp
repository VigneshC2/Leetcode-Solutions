class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int temp1 = 1e9 ;
        int temp2 = temp1 ;

        for(int ele : nums1){
            if(ele & 1){
                if(ele < temp1) temp1 = ele ;
            }
            else{
                if(ele < temp2) temp2 = ele ;
            }
        }

        if(temp1 == 1e9 || temp2 == 1e9) return true ;

        if(temp1 < temp2){
            return true ;
        }

        return false ;

    }
};