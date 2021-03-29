#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <connect4widget.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startNewGame();
    void updateNameLabels();
    void handleGameOver(connect4widget::Player winner);

private:
    Ui::MainWindow *ui;
    //void createMenu();
     static void setLabelBold(QLabel *label, bool isBold);
};

#endif // MAINWINDOW_H
