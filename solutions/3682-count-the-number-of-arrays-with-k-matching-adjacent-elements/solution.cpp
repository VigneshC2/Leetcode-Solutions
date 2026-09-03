class Solution {
public:
    long long MOD = 1e9 + 7 ;
    long long nCr(long long n , long long r){
        long long factorial[n+10] ;
        factorial[0] = factorial[1] = 1 ;
        // long long fermatFact[n+10] ;
        // fermatFact[0] = 1 ;
        // fermatFact[1] = 1 ;
        
        for(long long i = 2 ; i <= n ; i++){
            factorial[i] = (factorial[i-1] * i) % MOD ;
            // fermatFact[i] = expo(factorial[i] , MOD-2) ;
        }

        // fermatFact[n] = expo(factorial[n], MOD - 2);
        long long temp1 = expo(factorial[n-r], MOD - 2);
        long long temp2 = expo(factorial[r], MOD - 2);


        // for (long long i = n - 1; i >= 0; i--) {
        //     fermatFact[i] = (fermatFact[i + 1] * (i + 1)) % MOD;
        // }


        long long ans = factorial[n] ;
        ans *= temp2 ;
        ans %= MOD ;
        ans *= temp1 ;
        ans %= MOD ;

        return ans ;
    }

    long long expo(long long base , long long power){
        if(power == 0) return 1 ;
        long long ans = expo(base , (power >> 1)) ;
        ans *= ans ;
        ans %= MOD ;
        if(power & 1){
            ans *= base ;
            ans %= MOD ;
        }
        return ans ;
    }

    int countGoodArrays(int n, int m, int k) {
        long long ans = nCr(n-1 , k) ;
        ans *= m ;
        ans %= MOD ;

        ans *= expo(m - 1, n - k - 1) ;
        ans %= MOD ;

        return ans ;
    }
};