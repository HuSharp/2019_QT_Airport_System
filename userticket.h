#ifndef USERTICKET_H
#define USERTICKET_H

#include <QDialog>


namespace Ui {
class userticket;
}

typedef struct Customer_{
    QString name;
    int type;
    int area;
    int province;
    QString city;
    QString address;
    QString site;
    QString contact;
    QString buy;
    QString research;
    QString remark;
}Customer1,*PCustomer1;

class userticket : public QDialog
{
    Q_OBJECT

public:
    explicit userticket(Customer1* item,QWidget *parent = 0);
    ~userticket();

signals:
    void sigAddItem(Customer1*);

private slots:
    void on_btnAdd_clicked();
    void on_btnCancel_clicked();
    void on_combo2_currentTextChanged(const QString &arg1);
    void on_edit1_textChanged(const QString &arg1);

private:
    int String2Province(QString s);
    QString Province2String(int province);

private:
    Ui::userticket *ui;
    Customer1* mItem;
};

#endif // userticket_H
