#ifndef PROFILE_H
#define PROFILE_H

#include <QMainWindow>

namespace Ui {
class profile;
}

class profile : public QMainWindow
{
    Q_OBJECT

public:
    explicit profile(QWidget *parent = 0);
    ~profile();

private:
    Ui::profile *ui;
};

#endif // PROFILE_H
