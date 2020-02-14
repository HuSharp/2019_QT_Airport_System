#ifndef USERITEM_H
#define USERITEM_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QTreeWidget>
#include <QVector>
#include "userticket.h"


namespace Ui {
class useritem;
}

class useritem : public QMainWindow
{
    Q_OBJECT

public:
    explicit useritem(QWidget *parent = 0);
    ~useritem();

    void InitMenu();

    void InitModel();
    void InitTable();
    void AddItem(Customer1* item);
    void ClearData();

    void OpenDb(QString fileName);
    void SaveToDb(QString fileName);
    void InsertToDb(Customer1* item);
    void DeleteFromDb(QString name);

private slots:
    void onMenuOpen(bool checked);
    void onMenuSave(bool checked);

    void on_btnSearch_clicked();        //搜索按钮，关键字过滤
    void on_btnAdd_clicked();           //添加
    void on_btnDelete_clicked();        //删除

    void slotAddItem(Customer1* item);   //userticket里添加记录后需要不关闭对话框，因此发个信号
    void on_comboBox_currentTextChanged(const QString &arg1);   //按单位类别过滤
    void on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous); //改变选择区域
    void on_tableView_doubleClicked(const QModelIndex &index);  //数据一行双击修改

    void on_pushButton_clicked();

private:
    QString Type2String(int type);
    QString Area2String(int area);
    QString Province2String(int province);
    Customer1* FindItem(QString name);
    void DeleteItem(QString name);

private:
    Ui::useritem *ui;
    QString mDefaultDB;         //db文件路径
    QStandardItemModel* mModel; //tableview的model
    QVector<Customer1*> mItems;  //所有客户数据

    QStringList mAllType;       //所有单位类型
    QStringList mAllArea;       //所有区域
    QStringList mAllProvince;   //所有省份

    QString mFilterType;        //单位类型过滤
    QString mFilterArea;        //地域过滤
    QString mFilterProvince;    //省份过滤
    QString mFilterKey;         //关键字过滤
};

#endif // useritem_H
