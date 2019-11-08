#ifndef G4_QTLINEDEFEDIT_H
#define G4_QTLINEDEFEDIT_H

#include <QDialog>

namespace Ui {
class g4_qtlinedefedit;
}

class g4_qtlinedefedit : public QDialog
{
    Q_OBJECT

public:
    explicit g4_qtlinedefedit(QWidget *parent = nullptr);
    ~g4_qtlinedefedit();

private:
    Ui::g4_qtlinedefedit *ui;
};

#endif // G4_QTLINEDEFEDIT_H
