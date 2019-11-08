#ifndef G4_JACKED_UP_SPINBOX_H
#define G4_JACKED_UP_SPINBOX_H

#include <QWidget>

namespace Ui {
class g4_jacked_up_spinbox;
}

class g4_jacked_up_spinbox : public QWidget
{
    Q_OBJECT

public:
    explicit g4_jacked_up_spinbox(QWidget *parent = nullptr);
    ~g4_jacked_up_spinbox();

private:
    Ui::g4_jacked_up_spinbox *ui;
};

#endif // G4_JACKED_UP_SPINBOX_H
