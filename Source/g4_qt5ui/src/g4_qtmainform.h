#ifndef G4_QTMAINFORM_H
#define G4_QTMAINFORM_H

#include <QMainWindow>

namespace Ui {
class G4_QtMainForm;
}

class G4_QtMainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit G4_QtMainForm(QWidget *parent = nullptr);
    ~G4_QtMainForm();

private:
    Ui::G4_QtMainForm *ui;
};

#endif // G4_QTMAINFORM_H
