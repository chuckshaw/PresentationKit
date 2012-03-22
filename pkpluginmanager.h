#ifndef PKPLUGINMANAGER_H
#define PKPLUGINMANAGER_H

#include "pkmanager.h"

#include <QHash>

class PKPluginManager : public PKManager
{
    Q_OBJECT

public:
    explicit PKPluginManager(PresentationKit *parent, const char* name=0);
    virtual ~PKPluginManager();
    
signals:
    
public slots:

private:
    QString _pluginPath;
    //QHash<QString, PKPlugin*> _Plugins;
    
};

#endif // PKPLUGINMANAGER_H
