#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_loginBtn_clicked();


    void on_exitBtn_clicked();

    void on_usrLineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_pwdLineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
