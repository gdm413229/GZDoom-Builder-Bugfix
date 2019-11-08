#ifndef G4_QTNEWMAPFORM_H
#define G4_QTNEWMAPFORM_H

#include <QDialog>

namespace Ui {
class g4_qtnewmapform;
}

class g4_qtnewmapform : public QDialog
{
    Q_OBJECT

public:
    explicit g4_qtnewmapform(QWidget *parent = nullptr);
    ~g4_qtnewmapform();

private:
    Ui::g4_qtnewmapform *ui;
};

#endif // G4_QTNEWMAPFORM_H
