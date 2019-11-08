#ifndef G4_QTIMAGEVIEWPLUGIN_H
#define G4_QTIMAGEVIEWPLUGIN_H

#include <QDesignerCustomWidgetInterface>

class G4_QtImageViewPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)


public:
    G4_QtImageViewPlugin(QObject *parent = 0);

    bool isContainer() const;
    bool isInitialized() const;
    bool isInteractive() const; // can you click on it???
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

#endif // G4_QTIMAGEVIEWPLUGIN_H
