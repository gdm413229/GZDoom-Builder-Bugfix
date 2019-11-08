#include "g4_qtjackedupspinbox.h"
#include "g4_qtjackedupspinboxplugin.h"

#include <QtPlugin>

G4_QtJackedUpSpinBoxPlugin::G4_QtJackedUpSpinBoxPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtJackedUpSpinBoxPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtJackedUpSpinBoxPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtJackedUpSpinBoxPlugin::createWidget(QWidget *parent)
{
    return new G4_QtJackedUpSpinBox(parent);
}

QString G4_QtJackedUpSpinBoxPlugin::name() const
{
    return QLatin1String("G4_QtJackedUpSpinBox");
}

QString G4_QtJackedUpSpinBoxPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtJackedUpSpinBoxPlugin::icon() const
{
    return QIcon();
}

QString G4_QtJackedUpSpinBoxPlugin::toolTip() const
{
    return QLatin1String("The result of force-feeding steroid tablets to a QSpinBox.\\nAble to take expressions.");
}

QString G4_QtJackedUpSpinBoxPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtJackedUpSpinBoxPlugin::isContainer() const
{
    return false;
}

QString G4_QtJackedUpSpinBoxPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtJackedUpSpinBox\" name=\"g4_QtJackedUpSpinBox\">\n</widget>\n");
}

QString G4_QtJackedUpSpinBoxPlugin::includeFile() const
{
    return QLatin1String("g4_qtjackedupspinbox.h");
}

