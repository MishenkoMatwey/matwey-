#include "graf.h"
#include "ui_graf.h"

graf::graf(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graf)
{
    ui->setupUi(this);
}

graf::~graf()
{
    delete ui;
}
