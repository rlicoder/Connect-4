<!--

-->
<title>

</title>
<html>
<head>
<meta>
<?php>
class Game extends Board extends Player
{
    private $ board;
    private $ player1;
    private $ player2;
    private $ moves;
    private $ gamestate;
    private $ oneturn;

    //default constructor
    public function __construct()
    {
        $this->gamestate = true;
        $this->moves = "";
    }

    //moves constructor
    public function __construct($ moves)
    {
        
    }

    //starts game
    public function start()
    {
        $this->oneturn = true;
        while ($this->gamestate) 
        {
            board.displayBoard();
            echo "Choose your column, ";
            echo (oneturn ? "Player 1 " : "Player 2 <br>");
            $ col;
            cin >> col;
            while (!board.place(col, oneturn))
            {
	    echo "Try again: ";
	    cin >> col;
            }
            $this->addMove(col + '0');
            $this->oneturn = !$this->oneturn;
            if ($this->win()>0)
            {
                $this->gamestate = false;
            }
        }
    }
    
    //checks win condition
    public function win()
    {
        $ win = 0;
        //check the general win conditions
        for ($ i = 0; i < board.getRowSze(); i++)
        {
            for ($ j = 0; j < board.getColSze(); j++)
            {
                if (board.getSlot(i,j) == ' ')
                {
                    continue;
                }
                $ count = 0;
                for ($ k = i, l = j; k < i+4 && l < j+4 && k < board.getRowSze() && l < board.getColSze(); k++, l++)
                {
                    if (board.getSlot(k,l) == board.getSlot(i,j))
                    {
                        count++;
                    }
                }
                if (count == 4)
                {
                    echo board.getSlot(i,j);
                    echo " won via downright<br>";
                    return board.getSlot(i,j) == 'X' ? 1 : 2;
                }
                count = 0;
                for ($ k = i, l = j; k > i-4 && l > j-4 && k >= 0 && l >= 0; k--, l++)
                {
                    if (board.getSlot(k,l) == board.getSlot(i,j))
                    {
                        count++;
                    }
                }
                if (count == 4)
                {
                    echo board.getSlot(i,j);
                    echo " won via upright<br>";
                    return board.getSlot(i,j) == 'X' ? 1 : 2;
                }
                count = 0;
                for ($ k = i; k < i+4 && k < board.getRowSze(); k++)
                {
                    if(board.getSlot(k,j) == board.getSlot(i,j))
                    {
                        count++;
                    }
                }
                if (count == 4)
                {
                    echo board.getSlot(i,j);
                    echo " won via rightleft<br>";
                    return board.getSlot(i,j) == 'X' ? 1 : 2;
                }
                count = 0;
                for (var k = j; k < j+4 && k < board.getColSze(); k++)
                {
                    if (board.getSlot(i,k) == board.getSlot(i,j))
                    {
                        count++;
                    }
                }
                if (count == 4)
                {
                    echo board.getSlot(i,j);
                    echo " won by downup<br>";
                    return board.getSlot(i,j) == 'X' ? 1 : 2;
                }
            }
        }
        //check if the board is full
        $ full = true;
        board.displayBoard();
        for ($ i = 0; i < board.getRowSze(); i++)
        {
            for ($ j = 0; j < board.getColSze(); j++)
            {
                if (board.getSlot(i,j) == ' ')
                {
                    full = false;
                    break;
                }
            }
        }
        return (full ? 3 : win);
    }

    public function getMoves()
    {
        return $this->moves;
    }

    public function addMove($ move)
    {
        $this->moves += move;
    }
}
?>
</head>
</html>