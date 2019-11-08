#ifndef G4_QTRETRACTABLEPANELPLUGIN_H
#define G4_QTRETRACTABLEPANELPLUGIN_H

#include <QDesignerCustomWidgetInterface>

class G4_QtRetractablePanelPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_INTERFACES(QDesignerCustomWidgetInterface)


public:
    G4_QtRetractablePanelPlugin(QObject *parent = 0);

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

#endif // G4_QTRETRACTABLEPANELPLUGIN_H
