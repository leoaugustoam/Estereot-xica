#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
    //ui->lllllllabel->setText(auxseringa);
}

SecDialog::~SecDialog()
{
    delete ui;
}
