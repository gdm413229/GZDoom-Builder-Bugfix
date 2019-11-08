#include "g4_qtmaploadform.h"
#include "ui_g4_qtmaploadform.h"

g4_qtmaploadform::g4_qtmaploadform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g4_qtmaploadform)
{
    ui->setupUi(this);
}

g4_qtmaploadform::~g4_qtmaploadform()
{
    delete ui;
}
