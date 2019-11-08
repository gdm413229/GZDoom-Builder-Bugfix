#include "g4_qtimageview.h"
#include "g4_qtimageviewplugin.h"

#include <QtPlugin>

G4_QtImageViewPlugin::G4_QtImageViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtImageViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtImageViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtImageViewPlugin::createWidget(QWidget *parent)
{
    return new G4_QtImageView(parent);
}

QString G4_QtImageViewPlugin::name() const
{
    return QLatin1String("G4_QtImageView");
}

QString G4_QtImageViewPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtImageViewPlugin::icon() const
{
    return QIcon();
}

QString G4_QtImageViewPlugin::toolTip() const
{
    return QLatin1String("An image viewer, nuff said!");
}

QString G4_QtImageViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtImageViewPlugin::isContainer() const
{
    return false;
}

QString G4_QtImageViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtImageView\" name=\"g4_QtImageView\">\n</widget>\n");
}

QString G4_QtImageViewPlugin::includeFile() const
{
    return QLatin1String("g4_qtimageview.h");
}

