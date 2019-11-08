#include "g4_qtimagebrowserview.h"
#include "g4_qtimagebrowserviewplugin.h"

#include <QtPlugin>

G4_QtImageBrowserViewPlugin::G4_QtImageBrowserViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtImageBrowserViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtImageBrowserViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtImageBrowserViewPlugin::createWidget(QWidget *parent)
{
    return new G4_QtImageBrowserView(parent);
}

QString G4_QtImageBrowserViewPlugin::name() const
{
    return QLatin1String("G4_QtImageBrowserView");
}

QString G4_QtImageBrowserViewPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtImageBrowserViewPlugin::icon() const
{
    return QIcon();
}

QString G4_QtImageBrowserViewPlugin::toolTip() const
{
    return QLatin1String("The image browser's view.");
}

QString G4_QtImageBrowserViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtImageBrowserViewPlugin::isContainer() const
{
    return false;
}

QString G4_QtImageBrowserViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtImageBrowserView\" name=\"g4_QtImageBrowserView\">\n</widget>\n");
}

QString G4_QtImageBrowserViewPlugin::includeFile() const
{
    return QLatin1String("g4_qtimagebrowserview.h");
}

