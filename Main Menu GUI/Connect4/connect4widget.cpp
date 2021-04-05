#include "connect4widget.h"
#include <QPushButton>
#include <QGridLayout>
#include <QSignalMapper>
#include <QDebug>

connect4widget::connect4widget(QWidget *parent) : QWidget(parent)
{
    m_currentPlayer = Player::Invalid;
    QGridLayout *gridLayout = new QGridLayout(this);
    QSignalMapper *mapper = new QSignalMapper(this);
    for(int row = 0; row < 7; ++row) {
        for(int column = 0; column < 6; ++column) {
            QPushButton *button = new QPushButton(" ");
            gridLayout->addWidget(button, row, column);
            m_board.append(button);
            mapper->setMapping(button, m_board.count() - 1);
            connect(button, SIGNAL(clicked()), mapper, SLOT(map()));
        }
    }
    connect(mapper, SIGNAL(mapped(int)),
            this,   SLOT(handleButtonClick(int)));
}

void connect4widget::initNewGame() {
    for(QPushButton *button: m_board) {
        button->setText(" ");
    }
    setCurrentPlayer(Player::Player1);
}

void connect4widget::setCurrentPlayer(connect4widget::Player p)
{
    if(m_currentPlayer == p) {
        return;
    }
    m_currentPlayer = p;
    emit currentPlayerChanged(p);
}

void connect4widget::handleButtonClick(int index)
{
    if (m_currentPlayer == Player::Invalid) {
        return; // game is not started
    }
    if(index < 0 || index >= m_board.size()) {
        return; // out of bounds check
    }
    QPushButton *button = m_board[index];
    if(button->text() != " ") return; // invalid move
    button->setText(currentPlayer() == Player::Player1 ? "X" : "O");
    Player winner = checkWinCondition();
    if(winner == Player::Invalid) {
        setCurrentPlayer(currentPlayer() == Player::Player1 ?
                         Player::Player2 : Player::Player1);
        return;
    } else {
        qDebug() << "gameover" << winner;
        emit gameOver(winner);
    }
}

connect4widget::Player connect4widget::checkWinConditionForLine(
        int index1, int index2, int index3) const {
    QString text1 = m_board[index1]->text();
    if (text1 == " ") {
        return Player::Invalid;
    }
    QString text2 = m_board[index2]->text();
    QString text3 = m_board[index3]->text();
    if (text1 == text2 && text1 == text3) {
        return text1 == "X" ? Player::Player1 : Player::Player2;
    }
    return Player::Invalid;
}

connect4widget::Player connect4widget::checkWinCondition() const
{
    Player result = Player::Invalid;
    // check horizontals
    for(int row = 0; row < 7; ++row) {
        result = checkWinConditionForLine(row * 4,
                                          row * 4 + 1,
                                          row * 4 + 2,
                                          row * 4 + 3);
        if (result != Player::Invalid) {
            return result;
        }
    }
    // check verticals
    for(int column = 0; column < 7; ++column) {
         result = checkWinConditionForLine(column,
                                           4 + column,
                                           4 + column,
                                           4 + column);
        if (result != Player::Invalid) {
            return result;
        }
    }
    // check diagonals
    result = checkWinConditionForLine(0, 4, 8, 10);
    if (result != Player::Invalid) {
        return result;
    }
    result = checkWinConditionForLine(2, 4, 6, 8);
    if (result != Player::Invalid) {
        return result;
    }
    // check if there are unoccupied fields left
    for(QPushButton *button: m_board) {
        if(button->text() == " ") {
            return Player::Invalid;
        }
    }
    return Player::Draw;
}
