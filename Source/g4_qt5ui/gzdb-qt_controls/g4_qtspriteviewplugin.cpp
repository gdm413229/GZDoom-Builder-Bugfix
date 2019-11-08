#include "g4_qtspriteview.h"
#include "g4_qtspriteviewplugin.h"

#include <QtPlugin>

G4_QtSpriteViewPlugin::G4_QtSpriteViewPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void G4_QtSpriteViewPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool G4_QtSpriteViewPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *G4_QtSpriteViewPlugin::createWidget(QWidget *parent)
{
    return new G4_QtSpriteView(parent);
}

QString G4_QtSpriteViewPlugin::name() const
{
    return QLatin1String("G4_QtSpriteView");
}

QString G4_QtSpriteViewPlugin::group() const
{
    return QLatin1String("GZDB-Qt Exclusive Controls");
}

QIcon G4_QtSpriteViewPlugin::icon() const
{
    return QIcon();
}

QString G4_QtSpriteViewPlugin::toolTip() const
{
    return QLatin1String("A sprite preview, nuff said!");
}

QString G4_QtSpriteViewPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool G4_QtSpriteViewPlugin::isContainer() const
{
    return false;
}

QString G4_QtSpriteViewPlugin::domXml() const
{
    return QLatin1String("<widget class=\"G4_QtSpriteView\" name=\"g4_QtSpriteView\">\n</widget>\n");
}

QString G4_QtSpriteViewPlugin::includeFile() const
{
    return QLatin1String("g4_qtspriteview.h");
}

