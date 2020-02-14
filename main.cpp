#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "airlogindialog.h"
#include "connection.h"
#include "useritem.h"

extern int yonghu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return 1;

    MainWindow w;
    useritem u;
    AirLoginDialog ald;
    LoginDialog dlg;

    if (dlg.exec() == QDialog::Accepted && (yonghu==1 || yonghu==2))
    {
        if(yonghu==1){
            w.show();
            return a.exec();
        }
        if(yonghu==2){
            u.show();
            return a.exec();
        }
    }

/*
    if (dlg.exec() == QDialog::Accepted)
    {
       if(!createConnection())
           return 1;

       u.show();
       return a.exec();
    }
 */

    else return 0;

    //return a.exec();
}
