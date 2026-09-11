/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize){
int limit = (1 << n) ;

        // vector<int> temp(limit) , ans(limit) ;
        int temp[limit] ;

        int idx1 = 0 ;

        for(int i = 0 ; i < limit ; i++){
            int g = i ^ (i >> 1) ;
            temp[i] = g ;
            if(g == start) idx1 = i ;
        }

        int* ans = (int*) malloc(sizeof(int) * limit) ;
        *returnSize = limit ;

        for(int i = 0 ; i < limit ; i++){
            ans[i] = temp[idx1] ;
            idx1 += 1 ;
            if(idx1 >= limit) idx1 -= limit ;
        }

        return ans ;
}