#ifndef PRESENTATIONKIT_H
#define PRESENTATIONKIT_H

#include "pkmainwindow.h"
#include "pkpluginmanager.h"
#include "pkscriptmanager.h"

#include <QObject>
#include <QMainWindow>

class PresentationKit : public QObject
{
    Q_OBJECT
public:
    explicit PresentationKit(QObject *parent = 0);
    ~PresentationKit();

    PKMainWindow* GetMainWindow() const { return _PKMainWindow; }
    PKPluginManager* GetPluginManager() const { return _PKPluginManager; }
    PKScriptManager* GetScriptManager() const { return _PKScriptManager; }

signals:
    
public slots:
    void Slot_ExitApplication();

private:
    void Ignition();
    PKMainWindow* _PKMainWindow;
    PKPluginManager* _PKPluginManager;
    PKScriptManager* _PKScriptManager;

    
};

#endif // PRESENTATIONKIT_H
