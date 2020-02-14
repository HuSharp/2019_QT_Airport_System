#ifndef DLGITEM_H
#define DLGITEM_H

#include <QDialog>

namespace Ui {
class DlgItem;
}

typedef struct _Customer{
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
}Customer,*PCustomer;

class DlgItem : public QDialog
{
    Q_OBJECT

public:
    explicit DlgItem(Customer* item,QWidget *parent = 0);
    ~DlgItem();

signals:
    void sigAddItem(Customer*);

private slots:
    void on_btnAdd_clicked();
    void on_btnCancel_clicked();
    void on_combo2_currentTextChanged(const QString &arg1);
    void on_edit1_textChanged(const QString &arg1);

private:
    int String2Province(QString s);
    QString Province2String(int province);

private:
    Ui::DlgItem *ui;
    Customer* mItem;
};

#endif // DLGITEM_H
