#ifndef G4_QTIMAGEBROWSERVIEWPLUGIN_H
#define G4_QTIMAGEBROWSERVIEWPLUGIN_H

#include <QDesignerCustomWidgetInterface>

class G4_QtImageBrowserViewPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)


public:
    G4_QtImageBrowserViewPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    QIcon icon() const;
    QString domXml() const;
    QString group() const;
    QString includeFile() const;
    QString name() const;
    QString toolTip() const;
    QString whatsThis() const;
    QWidget *createWidget(QWidget *parent);
    void initialize(QDesignerFormEditorInterface *core);

private:
    bool m_initialized;
};

#endif // G4_QTIMAGEBROWSERVIEWPLUGIN_H
