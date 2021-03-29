#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startNewGame), &QPushButton::clicked,this,
            &MainWindow::startNewGame);
}

//mainLayout -> setMenuBar(menuBar);


//setLayout(mainLayout);

//setWindowTitle(tr("Connect 4 GUI"));
//setMinimumSize(520, 360);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewGame()
{
    qDebug()<<"button clicked!";


  }
