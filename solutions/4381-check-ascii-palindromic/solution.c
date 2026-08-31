bool isPalindromic(char* s) {
    int n = 0 ;
    while(s[n] != '\0') n+= 1 ;
        int i = 0 ;
        int j = n-1 ;

        while(i <= j){
            if(s[i] == 'f' && s[i] == s[j]){
                i += 1 ;
                j -= 1 ;
                continue ;
            }
            if(s[i] == 'v' && s[j] == 'n'){
                i += 1 ;
                j -= 1 ;
                continue ;
            }
            if(s[i] == 'n' && s[j] == 'v'){
                i += 1 ;
                j -= 1 ;
                continue ;
            }
            return false ;
        }

        return true ;
}