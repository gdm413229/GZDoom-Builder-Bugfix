#include "g4_qtangleselector.h"
#include "g4_qtangleselectorplugin.h"

#include <QtPlugin>

G4_QtAngleSelectorPlugin::G4_QtAngleSelectorPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtAngleSelectorPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtAngleSelectorPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtAngleSelectorPlugin::createWidget(QWidget *parent)
{
    return new G4_QtAngleSelector(parent);
}

QString G4_QtAngleSelectorPlugin::name() const
{
    return QLatin1String("G4_QtAngleSelector");
}

QString G4_QtAngleSelectorPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtAngleSelectorPlugin::icon() const
{
    return QIcon();
}

QString G4_QtAngleSelectorPlugin::toolTip() const
{
    return QLatin1String("The angle selector. (usually seen in the thing and sector inspectors)");
}

QString G4_QtAngleSelectorPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtAngleSelectorPlugin::isContainer() const
{
    return false;
}

QString G4_QtAngleSelectorPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtAngleSelector\" name=\"g4_QtAngleSelector\">\n</widget>\n");
}

QString G4_QtAngleSelectorPlugin::includeFile() const
{
    return QLatin1String("g4_qtangleselector.h");
}

