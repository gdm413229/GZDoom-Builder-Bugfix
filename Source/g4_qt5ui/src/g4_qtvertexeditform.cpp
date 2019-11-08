#include "g4_qtvertexeditform.h"
#include "ui_g4_qtvertexeditform.h"

g4_qtvertexeditform::g4_qtvertexeditform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g4_qtvertexeditform)
{
    ui->setupUi(this);
}

g4_qtvertexeditform::~g4_qtvertexeditform()
{
    delete ui;
}
