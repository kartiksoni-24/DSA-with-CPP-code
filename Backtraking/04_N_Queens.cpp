#include <iostream>
#include <vector>
using namespace std;

void printBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << "____________\n";
}

bool isSafe(const vector<vector<char>> &board, int row, int col)
{
    int n = board.size();

    // horizonatal
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
        {
            return false;
        }
    }

    // vertical
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }

    // left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    // right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> &board, int row)
{
    int n = board.size();

    if (row == n)
    {
        printBoard(board);
        return;
    }

    for (int j = 0; j < n; j++) // cols
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1);
            board[row][j] = '-';
        }
    }
}

// ------------------variation 1 : count of total solution-------------------
int nQueensSolCount(vector<vector<char>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        printBoard(board);
        return 1;
    }

    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            count += nQueensSolCount(board, row + 1);
            board[row][j] = '-';
        }
    }
    return count;
}

//-------------------variation 2 : print any single possible solution --------------------
bool nQueensAnySingleSol(vector<vector<char>> &board, int row)
{
    int n = board.size();
    if (row == n)
    {
        printBoard(board);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            bool res = nQueensAnySingleSol(board, row + 1);

            if (res)
            {
                return true;
            }
            board[row][j] = '-';
        }
    }

    return false;
}

int main()
{
    vector<vector<char>> board;
    int n = 5;
    // vector<vector<char>> board(n, vector<char>(n, '-'));

    for (int i = 0; i < n; i++)
    {
        vector<char> newRow;
        for (int j = 0; j < n; j++)
        {
            newRow.push_back('-');
        }
        board.push_back(newRow);
    }

    // nQueens(board, 0);
    // cout << "count is : " << nQueensSolCount(board, 0);
    nQueensAnySingleSol(board, 0);
    return 0;
}