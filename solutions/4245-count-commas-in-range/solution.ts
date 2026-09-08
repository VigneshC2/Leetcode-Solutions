function countCommas(n: number): number {
    var ans = 0 ;
        while(n>999){
            ans += (n-999) ;
            n = Math.floor(n/1000)
        }
        return ans ;
};