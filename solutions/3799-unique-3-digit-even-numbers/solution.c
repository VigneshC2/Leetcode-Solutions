int totalNumbers(int* digits, int digitsSize) {
    int freq[10] ;
        int temp[10] ;
        for(int i = 0 ; i < 10 ; i++){
            freq[i] = 0 ;
            temp[i] = 0 ;
        }
        for(int i = 0 ; i < digitsSize ; i++){
            freq[digits[i]] += 1 ;
        }

        int ans = 0 ;

        for(int i = 1 ; i < 10 ; i++){
            temp[i] += 1 ;
            for(int j= 0 ; j < 10 ; j++){
                temp[j] += 1 ;
                for(int k = 0 ; k < 10 ; k += 2){
                    temp[k] += 1 ;

                    bool f = true ;
                    for(int p = 0 ; p < 10 ;p++){
                        if(temp[p] > freq[p]){
                            f = false ;
                            break ;
                        }
                    }

                    temp[k] -= 1 ;

                    ans += f ;
                }
                temp[j] -= 1 ;
            }
            temp[i] -= 1 ;
        }

        return ans ;
}