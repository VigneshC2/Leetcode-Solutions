class Solution {
public:
    long long MOD = 1e9 + 7 ;
    long long expo(long long base , long long power){
        long long ans = 1 ;
        if(power == 0) return ans ;
        ans = expo(base , (power >> 1)) ;
        ans = ans * ans ;
        ans %= MOD ;
        if(power & 1) ans *= base ;
        ans %= MOD ;

        return ans ;
    }

    // long long rev(long long num){
    //     long long ans = 0 ;

    //     while(num > 0){
    //         int d = num % 10 ;
    //         ans = ans * 10 + d ;
    //         num /= 10 ;
    //     }

    //     return ans ;
    // }

    vector<int> vectorise(long long num){
        vector<int> ans ;

        while(num > 0){
            int d = num % 10 ;
            // ans = ans * 10 + d ;
            ans.push_back(d) ;
            num /= 10 ;
        }

        reverse(ans.begin() , ans.end()) ;

        return ans ;
    }

    long long decode(long long num){
        int w = num % 10 ;
        long long d = num / 10 ;

        // long long rev_num = rev(d) ;

        // cout << rev_num << endl ;

        auto rev_num = vectorise(d) ;

        long long x = 0 ;
        for(int i = 0 ; i < w ; i++){
            int temp = rev_num[i] ;
            x = x * 10 + temp ;
        }

        long long y = 0 ;
        

        for(int i = w ; i < rev_num.size() ; i++){
            int temp = rev_num[i] ;
            y = y * 10 + temp ;
        }
        // cout << x << " " << y << endl ;
        // cout << "num = " << num
        //  << " x = " << x
        //  << " y = " << y
        //  << " value = " << expo(x, y)
        //  << endl;

        return expo(x , y) ;
    }

    int sumDecoded(vector<long long>& nums) {
        long long ans = 0 ;
        int n = nums.size() ;
        
        for(int i = 0 ; i < n ; i++){
            ans += decode(nums[i]) ;
            ans %= MOD ;
        }

        return ans ;
    }
};