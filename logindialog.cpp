#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

int yonghu=0;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if((ui->usrLineEdit->text() == tr("8211180515") &&
        ui->pwdLineEdit->text() == tr("123456"))    ||
            (ui->usrLineEdit->text() == tr("8211180510") &&
             ui->pwdLineEdit->text() == tr("123456"))  )
    {
        if(ui->usrLineEdit->text() == tr("8211180515") &&
            ui->pwdLineEdit->text() == tr("123456"))
        {
                yonghu=1;
                accept();
        }
        if(ui->usrLineEdit->text() == tr("8211180510") &&
            ui->pwdLineEdit->text() == tr("123456"))
        {
                yonghu=2;
                accept();
        }
    } else {
       QMessageBox::warning(this, QObject::tr("警告!"),
                   QObject::tr("用户名或密码错误!"),
                   QMessageBox::Yes);
    }
    //清除内容 并定位光标
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
}



void LoginDialog::on_exitBtn_clicked()
{
    this->close();
}

void LoginDialog::on_usrLineEdit_cursorPositionChanged(int arg1, int arg2)
{

}

void LoginDialog::on_pwdLineEdit_cursorPositionChanged(int arg1, int arg2)
{

}
