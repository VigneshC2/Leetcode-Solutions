int distinctSubseqII(char* s) {
    // int n = s.size() ;

        long long MOD = 1e9 + 7 ;

        int temp[26] ;
        for(int i = 0 ; i < 26 ; i++){
            temp[i] = 0 ;
        }

        int ans = 0 ;
        int i = 0 ;

        // for(int i = 0 ; i < n ; i++){
        while(s[i] != '\0'){
            int tot = 0 ;
            if(i == 0){
                tot = 1 ;
            }
            else{
                tot = ans + 1 ;
            }
            int dup = temp[s[i] - 'a'] ;

            ans = (ans + tot - dup + MOD) % MOD ;

            temp[s[i] - 'a'] = tot ;

            i += 1 ;
        }

        return ans ;
}