#include "g4_qtretractablepanel.h"
#include "g4_qtretractablepanelplugin.h"

#include <QtPlugin>

G4_QtRetractablePanelPlugin::G4_QtRetractablePanelPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtRetractablePanelPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtRetractablePanelPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtRetractablePanelPlugin::createWidget(QWidget *parent)
{
    return new G4_QtRetractablePanel(parent);
}

QString G4_QtRetractablePanelPlugin::name() const
{
    return QLatin1String("G4_QtRetractablePanel");
}

QString G4_QtRetractablePanelPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtRetractablePanelPlugin::icon() const
{
    return QIcon();
}

QString G4_QtRetractablePanelPlugin::toolTip() const
{
    return QLatin1String("A retractable panel. (useful for the info panel and the side panel!)");
}

QString G4_QtRetractablePanelPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtRetractablePanelPlugin::isContainer() const
{
    return true;
}

QString G4_QtRetractablePanelPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtRetractablePanel\" name=\"g4_QtRetractablePanel\">\n</widget>\n");
}

QString G4_QtRetractablePanelPlugin::includeFile() const
{
    return QLatin1String("g4_qtretractablepanel.h");
}

