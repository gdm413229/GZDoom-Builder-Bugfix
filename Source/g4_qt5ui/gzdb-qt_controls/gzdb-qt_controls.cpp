#include "g4_qtjackedupspinboxplugin.h"
#include "g4_qtangleselectorplugin.h"
#include "g4_qtimageviewplugin.h"
#include "g4_qtimagebrowserviewplugin.h"
#include "g4_qtretractablepanelplugin.h"
#include "g4_qtspriteviewplugin.h"
#include "gzdb-qt_controls.h"

GZDB_Qt_Controls::GZDB_Qt_Controls(QObject *parent)
    : QObject(parent)
{
    m_widgets.append(new G4_QtJackedUpSpinBoxPlugin(this));
    m_widgets.append(new G4_QtAngleSelectorPlugin(this));
    m_widgets.append(new G4_QtImageViewPlugin(this));
    m_widgets.append(new G4_QtImageBrowserViewPlugin(this));
    m_widgets.append(new G4_QtRetractablePanelPlugin(this));
    m_widgets.append(new G4_QtSpriteViewPlugin(this));

}

QList<QDesignerCustomWidgetInterface*> GZDB_Qt_Controls::customWidgets() const
{
    return m_widgets;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(gzdb-qt_controlsplugin, GZDB-Qt_Controls)
#endif // QT_VERSION < 0x050000
