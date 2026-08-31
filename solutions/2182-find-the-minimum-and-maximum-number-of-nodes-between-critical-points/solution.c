/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int min(int a ,int b){
    return (a < b) ? a : b ;
}
int max(int a ,int b){
    return (a > b) ? a : b ;
}
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    int dist = -1 ;

        int min_dist = 1e9 ;
        int max_dist = -1 ;

        int dist2 = 0 ;

        struct ListNode* curr = head->next ;
        struct ListNode* prev = head ;


        while(curr->next){
            int prev_val = prev->val ;
            int curr_val = curr->val ;
            int next_val = curr->next->val ;

            bool isCritical = false ;

            if(prev_val < curr_val && curr_val > next_val) isCritical = true ;
            if(prev_val > curr_val && curr_val < next_val) isCritical = true ;

            if(isCritical){
                if(dist == -1){
                    dist2 = 0 ;
                }
                else{
                    min_dist = min(min_dist , dist) ;
                    max_dist = max(max_dist , dist2) ;
                    dist = 0 ;
                }
                dist = 0 ;
            }

            if(dist != -1) dist += 1 ;
            if(dist != -1) dist2 += 1 ;

            prev = curr ;
            curr = curr->next ;
        } 

        if(min_dist == 1e9) min_dist = -1 ;

        int* ans = (int*) malloc(sizeof(int) * 2) ;
        *returnSize = 2 ;

        ans[0] = min_dist ;
        ans[1] = max_dist ;

        return ans ;
}