#include <bits/stdc++.h>

using namespace std;

int win(vector<vector<char>> board)
{
    int win = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (board[i][j] == ' ')
            {
                continue;
            }
            char start = board[i][j];
            int count = 0;
            for (int k = i, l = j; k < i+4 && l < j+4 && k < 6 && l < 7; k++, l++)
            {
                if (board[k][l] == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via upright" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i, l = j; k > i-4 && l > j-4 && k >= 0 && l >= 0; k--, l--)
            {
                if (board[k][l] == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via downleft" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = i; k < i+4 && k < 6; k++)
            {
                if(board[k][j] == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won via rightleft" << endl;
                return start == 'X' ? 1 : 2;
            }
            count = 0;
            for (int k = j; k < j+4 && k < 7; k++)
            {
                if (board[i][k] == start)
                {
                    count++;
                }
            }
            if (count == 4)
            {
                cout << start << " won by downup" << endl;
                return start == 'X' ? 1 : 2;
            }
        }
    }
    return win;
}

int main()
{
    vector<vector<char>> board(6, vector<char>(7, ' '));
    bool oneturn = true;
    while (!win(board))
    {
        int col;
        cout << "Choose your column: ";
        cin >> col;
        bool set = false;
        for (int i = 5; i >= 0; i--)
        {
            if (board[i][col] == ' ')
            {
                set = true;
                board[i][col] = (oneturn ? 'X' : 'O');
                break;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                cout << board[i][j] << " | ";
            }
            cout << endl;
        }
        cout << endl;
        oneturn = !oneturn;
        cout << win(board) << endl;
    }
    cout << win(board) << endl;
}
