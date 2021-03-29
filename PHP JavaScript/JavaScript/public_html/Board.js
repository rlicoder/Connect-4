<!--

-->
<title>

</title>
<html>
<head>
<meta>
<script>
class Board
{
    private:
        var board;
        const rowSze = 6;
        const colSze = 7;

    public:
        //default constructor
        constructor()
        {
            board = var (rowSze, var(colSze));
            
            for (var i = 0; i < rowSze; i++)
            {
                for (var j = 0; j < colSze; j++)
                {
                    board[i][j] = ' ';
                }
            }
        }

        //moves constructor
        Board(var moves)
        {
            board = var (rowSze, var(colSze));
            var oneturn = true;
            for (var i = 0; i < (var)moves.size(); i++)
            {
                this.place(moves[i] - '0', oneturn);
                oneturn = !oneturn;
            }
        }
        Board.prototype.displayBoard=function()
        {
            for (var i = 0; i < rowSze; i++)
            {
                for (var j = 0; j < colSze; j++)
                {
                    document.write(board[i][j]);
                    document.write(" | ");
                }
                document.write("<br>");
            }
            document.write("<br>");
        }
        
        //get slot on board
        Board.prototype.getSlot(var row, var col)=function()
        {
            if (row < rowSze && col < colSze && row >= 0 && col >= 0)
            {
                //throw an error.
        }
        return board[row][col];
        }
       
        Board.prototype.place(var col, var oneturn)=function()
        {
            var set = false;
            for (var i = this.getRowSze()-1; i >= 0; i--)
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
    int getRowSze()
    {
        return this.colSze;
    }

    int getColSze()
    {
        return this.rowSze;
    }
}
</script>
</head>
</html>