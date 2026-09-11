class Solution {
public:

    vector<int> dir_x = {1 , 1 , -1, -1 , 1 , -1 , 0 , 0} ;
    vector<int> dir_y = {1 , -1 , 1 , -1 , 0 , 0 , 1, -1} ;


    bool canAttack(vector<int>& king , vector<int>& queen  , vector<vector<bool> >& isQueenPresent){
        int king_row = king[0] ;
        int king_col = king[1] ;
        int queen_row = queen[0] ;
        int queen_col = queen[1] ;

        for(int type = 0 ; type < 8 ; type += 1){
            int i = queen_row ;
            int j = queen_col ;
            i += dir_x[type] ;
            j += dir_y[type] ;

            while(true){
                if(i < 0 || i >= 8 || j < 0 || j <= 8) break;
                if(i == king_row && j == king_col){
                    return true ;
                }
                
                // if(i != queen_row && j != queen_col){
                if(isQueenPresent[i][j]){
                    i = -100;
                    break;
                }
                // }
                
                i += dir_x[type] ;
                j += dir_y[type] ;
            }
        }

        return false ;
    }

    vector<vector<int>> gettingAttacked(vector<int>& king , vector<vector<bool> >& isQueenPresent){
        vector<vector<int>> ans ;

        for(int type = 0 ; type < 8 ; type += 1){
            int i = king[0] ;
            int j = king[1] ;

            while(true){
                if(i < 0 || i >= 8 || j < 0 || j >= 8) break;

                if(isQueenPresent[i][j]){
                    ans.push_back({i ,j}) ;
                    break;
                }

                i += dir_x[type] ;
                j += dir_y[type] ;
            }
        }
        

        return ans ;
    }

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans ;

        // vector<vector<bool> > isQueenPresent(8 , vector<bool> (8 , false)) ;

        bool isQueenPresent[8][8] ;

        for(int i = 0 ; i < 8 ; i++){
            for(int j = 0 ; j < 8 ; j++){
                isQueenPresent[i][j] = false ;
            }
        }

        for(auto& q : queens){
            int x = q[0] ;
            int y = q[1] ;

            isQueenPresent[x][y] = true ;
        }

        for(int type = 0 ; type < 8 ; type += 1){
            int i = king[0] ;
            int j = king[1] ;

            while(true){
                if(i < 0 || i >= 8 || j < 0 || j >= 8) break;

                if(isQueenPresent[i][j]){
                    ans.push_back({i ,j}) ;
                    break;
                }

                i += dir_x[type] ;
                j += dir_y[type] ;
            }
        }
        

        return ans ;
    }
};