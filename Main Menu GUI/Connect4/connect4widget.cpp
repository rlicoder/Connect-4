#include <QApplication>
#include <QMainWindow>
#include "mainwindow.h"
#include "connect4widget.h"
#include <QPushButton>

void connect4widget::handleButtonClick(int index){
    if(m_currentPlayer == Player::Invalid){
        return; //game has not started
    }
    if(index <0 || index >= m_board.size()){
        return; //out of bounds check

}
    QPushButton *button = m_board[index];
    if (button ->text() != " ") return; //invalid move
    button->setText(currentPlayer() == Player::Player1 ? "" : ""); //Game Pieces in ""
    Player winner = checkWinCondition();
    if (winner == Player::Invalid){
        setCurrentPlayer(currentPlayer() == Player::Player1 ?
                             Player::Player2 : Player::Player1);
        return;
    }else{
        emit gameOver(winner);
    }
    }


void connect4widget::initNewGame(){
    for (QPushButton *button: m_Board){
        button->setText(" ");
    }
            setCurrentPlayer(Player::Player1);
    }
}

void MainWindow::startNewGame(){
    ui->player1Name->setText(tr(""));
    ui->player2Name->setText(tr(""));
    ui->gameBoard->initnewGame();
}
