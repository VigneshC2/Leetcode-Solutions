class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int count1 = 0 ;

        int n = s.size() ;

        int i = 0 ;
        int j = 0 ;

        string ans = "" ;
        int len = 1e9 ;

        // while(true){
        //     if(j >= n) break ;

        //     if(s[j] == '1') count1 += 1 ;

        //     if(count1 < k){
        //         j += 1 ;
        //         continue ;
        //     }

        //     if(count1 > k){
        //         if(s[i] == '1') count1 -= 1 ;
        //         i += 1 ;
        //         continue ;
        //     }

        //     while(i <= j && s[i] == '0'){
        //         i += 1 ;
        //     }


        //     int temp_len = j - i + 1 ;
        //     if(temp_len < len){
        //         ans = s.substr(i , temp_len) ;
        //         len = temp_len ;
        //     }
        //     else if(temp_len == len){
        //         ans = min(ans , s.substr(i , len)) ;
        //     }
            
        //     if(s[i] == '1') count1 -= 1 ;
        //     i += 1 ;

        //     j = max(j , i) ;
        // }

        for (int j = 0; j < n; j++) {
            if (s[j] == '1')
                count1++;

            while (count1 > k) {
                if (s[i] == '1')
                    count1--;
                i++;
            }

            if (count1 == k) {
                while (i < j && s[i] == '0')
                    i++;

                int currLen = j - i + 1;
                string curr = s.substr(i, currLen);

                if (currLen < len) {
                    len = currLen;
                    ans = curr;
                }
                else if (currLen == len) {
                    ans = min(ans, curr);
                }
            }
        }

        return ans ;
    }
};