#include "g4_qtpreferencesform.h"
#include "ui_g4_qtpreferencesform.h"

g4_qtpreferencesform::g4_qtpreferencesform(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::g4_qtpreferencesform)
{
    ui->setupUi(this);
}

g4_qtpreferencesform::~g4_qtpreferencesform()
{
    delete ui;
}
