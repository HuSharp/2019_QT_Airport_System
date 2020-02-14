#ifndef AIRLOGINDIALOG_H
#define AIRLOGINDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class AirLoginDialog;
}

class AirLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AirLoginDialog(QWidget *parent = nullptr);
    ~AirLoginDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();



    void on_pushButton_9_clicked();

private:
    Ui::AirLoginDialog *ui;
    QSqlTableModel *model;
};

#endif // AIRLOGINDIALOG_H




