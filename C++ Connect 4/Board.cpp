#include <bits/stdc++.h>

#include "Board.h"

using namespace std;
/* Definition for Board constructor with no parameter
 * --------------------------------------------------
 * This constructor will initialize the blank board.
 */
Board::Board()
{
    // Initialize board vector
    board = vector<vector<char>> (rowSze, vector<char>(colSze));
    for (int i = 0; i < rowSze; i++)
    {
        for (int j = 0; j < colSze; j++)
        {
            board[i][j] = ' '; // Set board to blank
        }
    }
}
/* Definition for Board constructor with string parameter
 * ------------------------------------------------------
 * This constructor will initialize the board with the
 * moves sent to it.
 */
Board::Board(string moves)
{
    // Initialize board vector
    board = vector<vector<char>> (rowSze, vector<char>(colSze));
    bool oneturn = true; // Initialize player turn
    for (int i = 0; i < rowSze; i++)
    {
        for (int j = 0; j < colSze; j++)
        {
            board[i][j] = ' '; // Set board to blank
        }
    }
    for (int i = 0; i < (int)moves.size(); i++) // Loop through moves string
    {
        this->place(moves[i] - '0', oneturn); // Place based off sent moves
        oneturn = !oneturn; // Switch turn
    }
}
/* Definition for displayBoard function
 * -----------------------------------------------
 * This function will display the connect 4 board.
 */
void Board::displayBoard()
{
    for (int i = 0; i < rowSze; i++) // Loop through column
    {
        for (int j = 0; j < colSze; j++) // Loop through row
        {
            cout << board[i][j] << " | "; // Output board vector
        }
        cout << endl;
    }
    cout << endl;
}
/* Definition for getSlot function
 * -----------------------------------------------
 * This function will receive a row and column and
 * return the value at that position in the board.
 */
char Board::getSlot(int row, int col) 
{
    // Check if it is within range
    if (row < rowSze && col < colSze && row >= 0 && col >= 0) 
    {
        return board[row][col]; // return the character in that slot
    } else return ' '; // return a blank character
}
/* Definition for place function
 * ------------------------------------------------------
 * This function will receive a column and the current
 * player's turn and place the x/o on the board according
 * to this information. It will return if it was 
 * successful.
 */
bool Board::place(int col, bool oneturn)
{
    if (col < 0 || col > 6) // If the placement is out of bounds
    {
	return false; // Return unsuccessful
    }
    bool set = false; // Store if it was successful, initialized to false
    for (int i = this->getRowSze()-1; i >= 0; i--) // Loop through column
    {
        if (board[i][col] != ' ') // Needs to be placed in a blank space
        {
            continue; // Continue to next iteration
        }
        else
        { 
            //Place character based on turn
            board[i][col] = (oneturn ? 'X' : 'O');
            set = true; // Set was successfu;
            break;
        }
    }
    return set; // Return success status
}
/* Definition for getColSze function
 * --------------------------------------------------------
 * This function will return the amount of columns in a row
 */
const int Board::getColSze()
{
    return this->colSze;
}
/* Definition for getRowSze function
 * --------------------------------------------------------
 * This function will return the amount of rows in a column
 */
const int Board::getRowSze()
{
    return this->rowSze;
}
