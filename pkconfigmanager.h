#ifndef PKCONFIGMANAGER_H
#define PKCONFIGMANAGER_H

#include "pkmanager.h"

#include <QHash>

class PKConfigManager : public PKManager
{
    Q_OBJECT

public:
    explicit PKConfigManager(PresentationKit* parent, const char* name=0);
    virtual ~PKConfigManager();

    struct Info {
        QString name;
        QString version;
        QString type;
        QString location;  //Used for dock widget placement.
        QString title;  //Used for dock widget title.
    };

    struct Geometry {
        int x;
        int y;
        int width;
        int height;
    };

    struct AppConfig {
        Geometry geometry;
        bool isFullScreen;
        bool hasCentralWidget;
        bool showMenuBar;
        bool showToolBar;
        bool showStatusBar;
        QString toolBarLocation;
    };

    struct PluginConfig {
        Info info;
        Geometry geometry;
        bool isCentralWidget;
        bool isDockWidget;
        bool isVisible;
    };

    QString LoadConfigFile(QString& configFile);
    void ParseConfig(QString& config);
    PluginConfig ParsePluginConfig(QString& config);
    AppConfig GetConfig() { return _appConfig; }
    
signals:
    
public slots:

private:
    QString _configFile;
    QString _styleSheet;
    AppConfig _appConfig;
    
    //QHash<QString, PluginConfig> _pluginConfigs;
};

#endif // PKCONFIGMANAGER_H
