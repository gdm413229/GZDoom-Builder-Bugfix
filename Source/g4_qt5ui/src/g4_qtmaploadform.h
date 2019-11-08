#ifndef G4_QTMAPLOADFORM_H
#define G4_QTMAPLOADFORM_H

#include <QDialog>

namespace Ui {
class g4_qtmaploadform;
}

class g4_qtmaploadform : public QDialog
{
    Q_OBJECT

public:
    explicit g4_qtmaploadform(QWidget *parent = nullptr);
    ~g4_qtmaploadform();

private:
    Ui::g4_qtmaploadform *ui;
};

#endif // G4_QTMAPLOADFORM_H
