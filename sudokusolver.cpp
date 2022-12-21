#include <bits/stdc++.h>
using namespace std;
bool isvalid(int i, int j, vector<vector<int>> &A, int c)
{
    for (int id = 0; id < 9; id++)
    {
        if (A[id][j] == c)
        {
            return false;
        }
        if (A[i][id] == c)
        {
            return false;
        }
        if (A[3 * (i / 3) + id / 3][3 * (j / 3) + id % 3] == c)
        {
            return false;
        }
    }
    return true;
}
bool func(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 0)
            {
                for (int c = 1; c <= 9; c++)
                {
                    if (isvalid(i, j, A, c))
                    {
                        A[i][j] = c;
                        if (func(A))
                        {
                            return true;
                        }
                        else
                        {
                            A[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>> &A)
{
    func(A);
}
int main()
{

    vector<vector<int>> board(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int b;
            cout << "Enter the number which is in row " << i + 1 << " and column " << j + 1 << " : ";
            cin >> b;
            board[i].push_back(b);
        }
    }
    solveSudoku(board);
    cout << "The Solved Sudoku Board is : " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
