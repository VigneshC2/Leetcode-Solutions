function pancakeSort(arr: number[]): number[] {
    var reverse = ( i , j) => {
        j -= 1 ;
        while(i < j){
            var temp = arr[i] ;
            arr[i] = arr[j] ;
            arr[j] = temp ;
            i += 1 ;
            j -= 1 ;
        }
        return ;
    }

    var n = arr.length ;
        // vector<int> ans ;
        // int* ans = (int*) malloc(sizeof(int) * (2*n)) ;
        var ans = []

        var curr = 0 ;

        for(var i = n ; i > 0 ; i--){
            var idx = 0 ;

            for(var j = i-1 ; j >= 0 ; j--){
                if(arr[j] == i){
                    idx = j ;
                    break ;
                } 
            }

            // reverse(arr.begin() , arr.begin() + idx + 1 ) ;
            // reverse(arr.begin() , arr.begin() + i ) ;
            reverse(0 , idx + 1) ;
            reverse(0 , i) ;

            // ans.push_back(idx+1) ;
            // ans.push_back(i) ;

            ans[curr++] = idx + 1 ;
            ans[curr++] = i ;

        }

        // *returnSize = 2*n ;

        return ans ;
};