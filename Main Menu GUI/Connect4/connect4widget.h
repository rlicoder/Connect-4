#ifndef CONNECT4WIDGET_H
#define CONNECT4WIDGET_H

#include <QWidget>
#include <QPushButton>

class connect4widget : public QWidget
{
    Q_OBJECT

public:
    explicit connect4widget(QWidget *parent = nullptr);
    enum class Player {
        Invalid, Player1, Player2, Draw
    };
    Q_ENUM(Player)

    Player currentPlayer() const
    {
        return m_currentPlayer;
    }
    void setCurrentPlayer(Player p);
    void initNewGame();

        signals:
        void currentPlayerChanged(Player);
        void gameOver(Player);

private:
    QVector<QPushButton*>m_board;
    Player m_currentPlayer;
    connect4widget::Player checkWinCondition() const;
    connect4widget::Player checkWinConditionForLine(int index1,int index2,int index3,int index4) const;

private slots:
    void handleButtonClick(int index);

public slots:
};

#endif // CONNECT4WIDGET_H
