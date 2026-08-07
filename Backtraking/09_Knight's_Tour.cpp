#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<int>> &board){
    for (int i = 0; i < board.size(); i++)
    {
        for(int j =0;j<board.size(); j++){
            cout << board[i][j] << "\t";

        }
        cout<< endl;
    }
    
}

bool tour(vector<vector<int>> &board, int row, int col, int move){

    int n = board.size();

    if(move == n*n){
        print(board);
        return true;
    }

    // right side
    if(row+1 < n && col+2 < n && board[row+1][col+2] == -1){
        board[row + 1][col + 2] = move;
        if(tour(board, row+1, col+2, move+1)){
            return true;
        }
        board[row + 1][col + 2] = -1;
   
    }
    if (row - 1 >= 0 && row - 1 < n && col + 2 < n && board[row - 1][col + 2] == -1)
    {
        board[row - 1][col + 2] = move;
        if(tour(board, row - 1, col + 2, move+1)){
            return true;
        }
        board[row - 1][col + 2] = -1;
       
    }

    // up side
    if (row - 2 >= 0 && row - 2 < n && col + 1 < n && board[row - 2][col + 1] == -1)
    {
        board[row -2][col + 1] = move;
        if(tour(board, row -2, col + 1, move+1)){
            return true;
        }
        board[row - 2][col + 1] = -1;
    
    }
    if (row - 2 >= 0 && row - 2 < n && col - 1 >= 0 && col - 1 < n && board[row - 2][col - 1] == -1)
    {
        board[row - 2][col - 1] = move;
        if(tour(board, row - 2, col - 1, move+1)){
            return true;
        }
        board[row - 2][col - 1] = -1;
        
    }

    //left side
    if (row + 1 < n && col - 2 >= 0 && col - 2 < n && board[row + 1][col - 2] == -1)
    {
        board[row +1][col -2] = move;
        if(tour(board, row +1, col -2, move+1)){
            return true;
        }
        board[row + 1][col - 2] = -1;
        
    }
    if (row - 1 >= 0 && row - 1 < n && col - 2 >= 0 && col - 2 < n && board[row - 1][col - 2] == -1)
    {
        board[row - 1][col - 2] = move;
       if( tour(board, row - 1, col - 2, move+1)){
           return true;
       }
        board[row - 1][col - 2] = -1;
    
    }

    //down side
    if (row + 2 < n && col +1 < n && board[row + 2][col +1] == -1)
    {
        board[row + 2][col +1] = move;
        if(tour(board, row +2, col +1, move+1)){
            return true;
        }
        board[row + 2][col + 1] = -1;
    
    }
    if (row + 2 < n && col-1 >= 0 && col - 1 < n && board[row + 2][col - 1] == -1)
    {
        board[row + 2][col - 1] = move;
        if(tour(board, row + 2, col - 1, move+1)){
            return true;
        }
        board[row + 2][col - 1] = -1;
        
    }

    return false;
}

    int main()
{
    int n = 5;
    vector<vector<int>> board(n, vector<int>(n, -1));
    // vector<vector<bool>> visited(n, vector<bool>(n, false));
    board[0][0] = 0;
    tour(board, 0, 0, 1);
}