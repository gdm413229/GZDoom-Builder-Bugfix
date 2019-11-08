#include "g4_qtnewmapform.h"
#include "ui_g4_qtnewmapform.h"

g4_qtnewmapform::g4_qtnewmapform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g4_qtnewmapform)
{
    ui->setupUi(this);
}

g4_qtnewmapform::~g4_qtnewmapform()
{
    delete ui;
}
