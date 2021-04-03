#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>

namespace Ui {
class configurationdialog;
}

class configurationdialog : public QDialog
{
    Q_OBJECT

public:
    explicit configurationdialog(QWidget *parent = nullptr);
    ~configurationdialog();

    void setPlayer1Name(const QString &p1name);
    void setPlayer2Name(const QString &p2name);
    QString player1Name() const;
    QString player2Name() const;

private:
    Ui::configurationdialog *ui;

private slots:
    void updateOKButtonState();
};

#endif // CONFIGURATIONDIALOG_H
