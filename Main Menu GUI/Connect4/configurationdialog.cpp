#include "configurationdialog.h"
#include "ui_configurationdialog.h"

#include <QPushButton>

configurationdialog::configurationdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::configurationdialog)
{
    ui->setupUi(this);
    connect(ui->player1Name, &QLineEdit::textChanged,
            this, &configurationdialog::updateOKButtonState);
    connect(ui->player2Name, &QLineEdit::textChanged,
            this, &configurationdialog::updateOKButtonState);
    updateOKButtonState();
}

configurationdialog::~configurationdialog()
{
    delete ui;
}

void configurationdialog::updateOKButtonState()
{
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    okButton->setEnabled(!ui->player1Name->text().isEmpty() &&
                         !ui->player2Name->text().isEmpty());
}

void configurationdialog::setPlayer1Name(const QString &p1name)
{
    ui->player1Name->setText(p1name);
}
void configurationdialog::setPlayer2Name(const QString &p2name)
{
    ui->player2Name->setText(p2name);
}
QString configurationdialog::player1Name() const
{
    return ui->player1Name->text();
}
QString configurationdialog::player2Name() const
{
    return ui->player2Name->text();
}
