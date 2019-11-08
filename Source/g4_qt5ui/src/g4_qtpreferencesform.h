#ifndef G4_QTPREFERENCESFORM_H
#define G4_QTPREFERENCESFORM_H

#include <QDialog>

namespace Ui {
class g4_qtpreferencesform;
}

class g4_qtpreferencesform : public QDialog
{
    Q_OBJECT

public:
    explicit g4_qtpreferencesform(QWidget *parent = nullptr);
    ~g4_qtpreferencesform();

private:
    Ui::g4_qtpreferencesform *ui;
};

#endif // G4_QTPREFERENCESFORM_H
