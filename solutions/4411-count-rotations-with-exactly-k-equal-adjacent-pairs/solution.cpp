class Solution {
public:
    int countRotations(string s, int k) {
        string temp = s + s ;

        int n = s.size() ;
        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){
            int score = 0 ;
            for(int j = 0 ; j < n-1 ; j++){
                if(temp[i+j] == temp[i+j+1]){
                    score += 1 ;
                }
            }
            if(score == k) ans += 1 ;
        }

        return ans ;
    }
};