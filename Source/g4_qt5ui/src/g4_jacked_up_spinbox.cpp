#include "g4_jacked_up_spinbox.h"
#include "ui_g4_jacked_up_spinbox.h"

g4_jacked_up_spinbox::g4_jacked_up_spinbox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::g4_jacked_up_spinbox)
{
    ui->setupUi(this);
}

g4_jacked_up_spinbox::~g4_jacked_up_spinbox()
{
    delete ui;
}
