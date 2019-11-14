#ifndef FIGURE_H
#define FIGURE_H

#include <QMainWindow>

namespace Ui {
class figure;
}

class figure : public QMainWindow
{
    Q_OBJECT

public:
    explicit figure(QWidget *parent = 0);
    ~figure();

private:
    Ui::figure *ui;
};

#endif // FIGURE_H
