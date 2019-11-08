#include "g4_qtlinedefedit.h"
#include "ui_g4_qtlinedefedit.h"

g4_qtlinedefedit::g4_qtlinedefedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g4_qtlinedefedit)
{
    ui->setupUi(this);
}

g4_qtlinedefedit::~g4_qtlinedefedit()
{
    delete ui;
}
