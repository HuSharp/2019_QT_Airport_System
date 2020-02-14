#include "UserItem.h"
#include "ui_UserItem.h"

UserItem::UserItem(Customer* item,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserItem)
{
    ui->setupUi(this);

    mItem = item;

    QFont font( "Microsoft YaHei", 10, 75);
    ui->labelTip->setFont(font);
    ui->labelTip->setStyleSheet("QLabel{color:red;}");
    ui->tableWidget->setRowCount(20);
    for(int i=0;i<20;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(""));
    }

    on_combo2_currentTextChanged("华东");
    if(mItem)
    {
        //修改
        ui->btnAdd->setText("修改");

        ui->edit1->setText(mItem->name);
        ui->combo1->setCurrentIndex(mItem->type);
        ui->combo2->setCurrentIndex(mItem->area);
        on_combo2_currentTextChanged(ui->combo2->currentText());
        ui->combo3->setCurrentText(Province2String(mItem->province));
        ui->edit2->setText(mItem->city);
        ui->edit3->setText(mItem->address);
        ui->edit4->setText(mItem->site);
        ui->textEdit->setText(mItem->buy);
        ui->textEdit2->setText(mItem->research);
        ui->textEdit3->setText(mItem->remark);

        QStringList all = mItem->contact.split(";");
        for(int i=0;i<all.size();i++)
        {
            QStringList row = all[i].split(",");
            if(row.size() >= 6)
            {
                bool bRed = !row[5].isEmpty();
                ui->tableWidget->item(i,0)->setText(row[0]);
                ui->tableWidget->item(i,1)->setText(row[1]);
                ui->tableWidget->item(i,2)->setText(row[2]);
                ui->tableWidget->item(i,3)->setText(row[3]);
                ui->tableWidget->item(i,4)->setText(row[4]);
                ui->tableWidget->item(i,5)->setText(row[5]);
                if(!row[5].isEmpty())
                {
                    ui->tableWidget->item(i,0)->setBackground(Qt::red);
                    ui->tableWidget->item(i,1)->setBackground(Qt::red);
                    ui->tableWidget->item(i,2)->setBackground(Qt::red);
                    ui->tableWidget->item(i,3)->setBackground(Qt::red);
                    ui->tableWidget->item(i,4)->setBackground(Qt::red);
                    ui->tableWidget->item(i,5)->setBackground(Qt::red);
                }
            }
        }
    }
}

UserItem::~UserItem()
{
    delete ui;
}

void UserItem::on_btnAdd_clicked()
{
    if(ui->edit1->text().isEmpty())
    {
        ui->labelTip->setText("航班号名称不能为空!");
        return;
    }
    Customer* p = new Customer;
    p->name = ui->edit1->text();
    p->type = ui->combo1->currentIndex();
    p->area = ui->combo2->currentIndex();
    p->province = String2Province(ui->combo3->currentText());
    p->city = ui->edit2->text();
    p->address = ui->edit3->text();
    p->site = ui->edit4->text();
    p->buy = ui->textEdit->toPlainText();
    p->research = ui->textEdit2->toPlainText();
    p->remark = ui->textEdit3->toPlainText();

    QString sAll = "";
    QString s = "";
    int columns = ui->tableWidget->columnCount();
    for(int i=0;i<ui->tableWidget->rowCount();i++)
    {
        if(ui->tableWidget->item(i,0)->text().isEmpty())
        {
            continue;
        }
        for(int j=0;j<columns;j++)
        {
            //,和;是用来分隔的标记，禁止用户输入这2个符号，如果不小心输了，程序也替换成空格
            s = ui->tableWidget->item(i,j)->text();
            s.replace(","," ");
            s.replace(";"," ");
            sAll += s;
            if(j == columns-1)
            {
                sAll += ";";
            }
            else
            {
                sAll += ",";
            }
        }
    }
    p->contact = sAll;

    if(mItem)
    {
        //修改
        mItem->name = p->name;
        mItem->type = p->type;
        mItem->area = p->area;
        mItem->province = p->province;
        mItem->city = p->city;
        mItem->address = p->address;
        mItem->site = p->site;
        mItem->contact = p->contact;
        mItem->buy = p->buy;
        mItem->research = p->research;
        mItem->remark = p->remark;
        accept();
    }
    else
    {
        //新增
        emit sigAddItem(p);

        ui->edit1->setText("");
        ui->edit2->setText("");
        ui->edit3->setText("");
        ui->edit4->setText("");
        ui->textEdit->setText("");
        ui->textEdit2->setText("");
        ui->textEdit3->setText("");
        for(int i=0;i<20;i++)
        {
            ui->tableWidget->item(i,0)->setText("");
            ui->tableWidget->item(i,1)->setText("");
            ui->tableWidget->item(i,2)->setText("");
            ui->tableWidget->item(i,3)->setText("");
            ui->tableWidget->item(i,4)->setText("");
            ui->tableWidget->item(i,5)->setText("");
        }
        ui->edit1->setFocus();
        ui->labelTip->setText("增加成功!");
    }

}

void UserItem::on_btnCancel_clicked()
{
    reject();
}

int UserItem::String2Province(QString s)
{
    QStringList AllProvince;
    AllProvince<<"山东"<<"浙江"<<"江苏"<<"安徽"<<"上海"<<"福建"
                <<"广东"<<"广西"<<"海南"
                <<"湖北"<<"湖南"<<"河南"<<"江西"
                <<"北京"<<"天津"<<"河北"<<"山西"<<"内蒙"
                <<"宁夏"<<"新疆"<<"青海"<<"陕西"<<"甘肃"<<"四川"<<"云南"<<"贵州"<<"西藏"<<"重庆"<<"辽宁"<<"吉林"<<"黑龙江";
    return AllProvince.indexOf(s);
}

QString UserItem::Province2String(int n)
{
    QStringList AllProvince;
    AllProvince<<"山东"<<"浙江"<<"江苏"<<"安徽"<<"上海"<<"福建"
                <<"广东"<<"广西"<<"海南"
                <<"湖北"<<"湖南"<<"河南"<<"江西"
                <<"北京"<<"天津"<<"河北"<<"山西"<<"内蒙"
                <<"宁夏"<<"新疆"<<"青海"<<"陕西"<<"甘肃"<<"四川"<<"云南"<<"贵州"<<"西藏"<<"重庆"<<"辽宁"<<"吉林"<<"黑龙江";
    if(n>=0 && n<AllProvince.size())
    {
        return AllProvince[n];
    }
    return "";
}

void UserItem::on_combo2_currentTextChanged(const QString &text)
{
    ui->combo3->clear();
    if(text == "华东")
    {
        ui->combo3->addItems(QStringList()<<"山东"<<"浙江"<<"江苏"<<"安徽"<<"上海"<<"福建");
    }
    else if(text == "华南")
    {
        ui->combo3->addItems(QStringList()<<"广东"<<"广西"<<"海南");
    }
    else if(text == "华中")
    {
        ui->combo3->addItems(QStringList()<<"湖北"<<"湖南"<<"河南"<<"江西");
    }
    else if(text == "华北")
    {
        ui->combo3->addItems(QStringList()<<"北京"<<"天津"<<"河北"<<"山西"<<"内蒙");
    }
    else if(text == "其他")
    {
        ui->combo3->addItems(QStringList()<<"宁夏"<<"新疆"<<"青海"<<"陕西"<<"甘肃"<<"四川"<<"云南"<<"贵州"<<"西藏"<<"重庆"<<"辽宁"<<"吉林"<<"黑龙江");
    }
}

void UserItem::on_edit1_textChanged(const QString &arg1)
{
    ui->labelTip->setText("");
}
