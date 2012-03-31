#ifndef PRESENTATIONKIT_H
#define PRESENTATIONKIT_H

#include "pkmainwindow.h"
#include "pkpluginmanager.h"
#include "pkscriptmanager.h"
#include "pkconfigmanager.h"

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
    PKConfigManager* GetConfigManager() const { return _PKConfigManager; }
    QString GetAppPath() const { return _appPath; }


signals:
    
public slots:
    void Slot_ExitApplication();

private:
    void Ignition();
    PKMainWindow* _PKMainWindow;
    PKPluginManager* _PKPluginManager;
    PKScriptManager* _PKScriptManager;
    PKConfigManager* _PKConfigManager;
    
    QString _appPath;
};

#endif // PRESENTATIONKIT_H
