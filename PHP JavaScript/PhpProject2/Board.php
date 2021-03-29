<!--

-->
<title>

</title>
<html>
<head>
<meta>
<?php>
class Board
{
    private $ board;
    private $ define(rowSze, 6);
    privear $ define(colSze, 7);

    //default constructor
    public function __ construct()
    {
        board = $vector(rowSze, $vector(colSze));
        for ($ i = 0; i < rowSze; i++)
        {
            for ($ j = 0; j < colSze; j++)
            {
                board[i][j] = ' ';
            }
        }
    }

    //moves constructor
    public function __construct($ moves)
    {
        board = $vector(rowSze, $vector(colSze));
        $ oneturn = true;
        for ($ i = 0; i < $moves.size(); i++)
        {
            $this->place(moves[i] - '0', oneturn);
            oneturn = !oneturn;
        }
    }

    public function displayBoard()
    {
        for ($ i = 0; i < rowSze; i++)
        {
            for ($ j = 0; j < colSze; j++)
            {
                echo(board[i][j]);
                echo(" | ");
            }
            echo("<br>");
        }
        echo("<br>"); 
    }

    //get slot on board
    public function getSlot($ row, $ col)
    {
        if (row < rowSze && col < colSze && row >= 0 && col >= 0)
        {
            //throw an error.
        }
        return board[row][col];
    }
        
    public function place($ col, $ oneturn)
    {
        $ set = false;
        for ($ i = $this->getRowSze()-1; i >= 0; i--)
        {
            if (board[i][col] != ' ')
            {
                continue;
            }
            else
            {
                board[i][col] = (oneturn ? 'X' : 'O');
                set = true;
                break;
            }
        }
        return set;
    }
        
    public function getRowSze()
    {
        return $this->rowSze;
    }

    public function getColSze()
    {
        return $this->colSze;
    }
}
?>
</head>
</html>