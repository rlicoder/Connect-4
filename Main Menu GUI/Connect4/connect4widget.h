#ifndef CONNECT4WIDGET_H
#define CONNECT4WIDGET_H
#include <QWidget>
#include <QPushButton>

class connect4widget : public QWidget
{
    Q_OBJECT
enum class Player {
    Invalid, Player1, Player2, Draw
};
Q_ENUM(Player)
signals:
void currentPlayerChanged(Player);
void gameOver(Player);

public:
    connect4widget(QWidget *parent = nullptr);
        ~connect4widget();
    Player currentPlayer() const
    {
        return m_currentPlayer;
    }
    void setCurrentPlayer(Player p)
    {
        if(m_currentPlayer ==p){
            return;
        }
        m_currentPlayer = p;
        emit currentPlayerChanged(p);
    }

private:
    QVector<QPushButton*>m_board;
    Player m_currentPlayer;

private slots:
    void handleButtonClick(int index);
};

#endif // CONNECT4WIDGET_H
