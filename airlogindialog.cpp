#include "airlogindialog.h"
#include "ui_airlogindialog.h"
#include <QMessageBox>
#include <QSqlError>
#include "logindialog.h"

AirLoginDialog::AirLoginDialog(QWidget *parent) :
    QDialog (parent),
    ui(new Ui::AirLoginDialog)
{
    ui->setupUi(this);
    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select(); //选取整个表的所有行

    //不显示name属性列,如果这时添加记录，则该属性的值添加不上
    // model->removeColumn(1);

    ui->tableView->setModel(model);

    //使其不可编辑
    // ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

AirLoginDialog::~AirLoginDialog()
{
    delete ui;
}

void AirLoginDialog::on_pushButton_clicked()
{
    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    } else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("tableModel"),
                             tr("数据库错误: %1")
                             .arg(model->lastError().text()));
    }
}


void AirLoginDialog::on_pushButton_2_clicked()
{
    model->revertAll();
}

void AirLoginDialog::on_pushButton_5_clicked()
{
    QString name = ui->lineEdit->text();
    //根据姓名进行筛选
    model->setFilter(QString("name = '%1'").arg(name));
    //显示结果
    model->select();
}

void AirLoginDialog::on_pushButton_6_clicked()
{
    model->setTable("student");   //重新关联表
    model->select();   //这样才能再次显示整个表的内容
}

// 升序
void AirLoginDialog::on_pushButton_7_clicked()
{
    //id属性即第0列，升序排列
    model->setSort(0, Qt::AscendingOrder);
    model->select();
}
// 降序
void AirLoginDialog::on_pushButton_8_clicked()
{
    model->setSort(0, Qt::DescendingOrder);
    model->select();
}

void AirLoginDialog::on_pushButton_4_clicked()
{
    //获取选中的行
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
    model->removeRow(curRow);

    int ok = QMessageBox::warning(this,tr("删除当前行!"),
                                  tr("你确定删除当前行吗？"),
                                  QMessageBox::Yes,QMessageBox::No);
    if(ok == QMessageBox::No)
    {
        model->revertAll(); //如果不删除，则撤销
    }
    else model->submitAll(); //否则提交，在数据库中删除该行
}

void AirLoginDialog::on_pushButton_3_clicked()
{
    int rowNum = model->rowCount(); //获得表的行数
    int id = 10;
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum,0),id);
    //model->submitAll(); //可以直接提交
}

void AirLoginDialog::on_pushButton_9_clicked()
{
    LoginDialog *dlg = new LoginDialog;
    dlg->show();
    this->close();
}
