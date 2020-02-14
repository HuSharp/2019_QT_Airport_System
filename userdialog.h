#include <QDialog>

namespace Ui {
class AirLoginDialog;
}

class AirLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AirLoginDialog(QWidget *parent = nullptr);
    ~AirLoginDialog();

private:
    Ui::AirLoginDialog *ui;
};
