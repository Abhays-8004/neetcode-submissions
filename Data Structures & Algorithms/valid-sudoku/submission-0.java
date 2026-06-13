class Solution {
    public boolean isValidSudoku(char[][] board) {
        
        for(int col = 0;col<9;col++){
            Set<Character> s = new HashSet<>();
            for(int row = 0;row<9;row++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(s.contains(board[row][col])){
                    return false;
                }else{
                    s.add(board[row][col]);
                }

            }
        }

         for(int row = 0;row<9;row++){
            Set<Character> s = new HashSet<>();
            for(int col = 0;col<9;col++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(s.contains(board[row][col])){
                    return false;
                }else{
                    s.add(board[row][col]);
                }

            }
        }

        for(int row = 0;row<9;row+=3){
            for(int col = 0;col<9;col+=3){
                Set<Character> s = new HashSet<>();
                for(int i = 0;i<3;i++){
                    for(int j= 0;j<3;j++){
                        if(board[row+i][col+j] == '.'){
                            continue;
                        }
                        if(s.contains(board[row+i][col+j])){
                            return false;
                        }else{
                            s.add(board[row+i][col+j]);
                        }
                    }
                }
            }
        }

        return true;
    }
}
