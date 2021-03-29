<!--

-->
<title>

</title>
<html>
<head>
<meta>
<script>
class Game
{
    private:
        Board board;
        Player player1;
        Player player2;
        var moves;
        var gamestate;
        var oneturn;

    public:
        //default constructor
        constructor()
        {
            this.gamestate = true;
            this.moves = "";
        }

        //moves constructor
        Game(var moves)
        {
        
        }

        //starts game
        Game.prototype.start=function()
        {
            this.oneturn = true;
            while (this.gamestate) 
            {
                board.displayBoard();
                document.write("Choose your column, ");
                document.write(oneturn ? "Player 1 " : "Player 2 </br>");
                var col = document.getElementById("col");
                while (!board.place(col, oneturn))
                {
                    document.write("Try again: ");
                    col = document.getElementById("col");
                }
                this.addMove(col + '0');
                this.oneturn = !this.oneturn;
                if (this.win()>0)
                {
                    this.gamestate = false;
                }
            }
        }
        
        //checks win condition
        Game.protptype.win=function()
        {
            var win = 0;
            //check the general win conditions
            for (var i = 0; i < board.getRowSze(); i++)
            {
                for (var j = 0; j < board.getColSze(); j++)
                {
                    if (board.getSlot(i,j) == ' ')
                    {
                        continue;
                    }
                    var count = 0;
                    for (var k = i, l = j; k < i+4 && l < j+4 && k < board.getRowSze() && l < board.getColSze(); k++, l++)
                    {
                        if (board.getSlot(k,l) == board.getSlot(i,j))
                        {
                            count++;
                        }
                    }
                    if (count == 4)
                    {
                        document.write(board.getSlot(i,j));
                        document.write(" won via downright</br>");
                        return board.getSlot(i,j) == 'X' ? 1 : 2;
                    }
                    count = 0;
                    for (var k = i, l = j; k > i-4 && l > j-4 && k >= 0 && l >= 0; k--, l++)
                    {
                        if (board.getSlot(k,l) == board.getSlot(i,j))
                        {
                            count++;
                        }
                    }
                    if (count == 4)
                    {
                        document.write(board.getSlot(i,j))
                        document.write(" won via upright</br>");
                        return board.getSlot(i,j) == 'X' ? 1 : 2;
                    }
                    count = 0;
                    for (var k = i; k < i+4 && k < board.getRowSze(); k++)
                    {
                        if(board.getSlot(k,j) == board.getSlot(i,j))
                        {
                            count++;
                        }
                    }
                    if (count == 4)
                    {
                        document.write(board.getSlot(i,j));
                        document.write(" won via rightleft</br>";
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
                        document.write(board.getSlot(i,j));
                        document.write(" won by downup</br>");
                        return board.getSlot(i,j) == 'X' ? 1 : 2;
                    }
                }
            }
            //check if the board is full
            var full = true;
            board.displayBoard();
            for (var i = 0; i < board.getRowSze(); i++)
            {
                for (var j = 0; j < board.getColSze(); j++)
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
        
        Game.prototype.getMoves=function()
        {
            return this.moves;
        }

	Game.prototype.addMove=function(var move)
        {
            this.moves += move;
        }

</script>
</head>
</html>