#include "g4_qtmainform.h"
#include "ui_g4_qtmainform.h"

G4_QtMainForm::G4_QtMainForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::G4_QtMainForm)
{
    ui->setupUi(this);
}

G4_QtMainForm::~G4_QtMainForm()
{
    delete ui;
}
