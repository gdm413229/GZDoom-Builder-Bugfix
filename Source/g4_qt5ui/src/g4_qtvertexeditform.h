#ifndef G4_QTVERTEXEDITFORM_H
#define G4_QTVERTEXEDITFORM_H

#include <QDialog>

namespace Ui {
class g4_qtvertexeditform;
}

class g4_qtvertexeditform : public QDialog
{
    Q_OBJECT

public:
    explicit g4_qtvertexeditform(QWidget *parent = nullptr);
    ~g4_qtvertexeditform();

private:
    Ui::g4_qtvertexeditform *ui;
};

#endif // G4_QTVERTEXEDITFORM_H
