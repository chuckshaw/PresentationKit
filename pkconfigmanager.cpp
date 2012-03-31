
#include "presentationkit.h"
#include "pkconfigmanager.h"
#include "pkmanager.h"

#include <QFile>
#include <QTextStream>
#include <QXmlStreamReader>

#include <iostream>

PKConfigManager::PKConfigManager(PresentationKit *parent, const char *name) :
    PKManager(parent, name)
{
    _configFile = _presentationKit->GetAppPath() + "/Config.xml";
    _styleSheet = "";

    QString config = LoadConfigFile(_configFile);
    this->ParseConfig(config);
}

PKConfigManager::~PKConfigManager()
{

}

QString PKConfigManager::LoadConfigFile(QString& configFile)
{
    QString config = "";

    QFile file(configFile);
    if(!file.exists())
    {
        std::cout << "WARNING: " << configFile.toStdString() << " was not found!" << std::endl;
    }
    else if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            config += in.readLine();
        }
        file.close();
    }

    return config;
}

void PKConfigManager::ParseConfig(QString& config)
{
    //Default Configuration
    _appConfig.geometry.x = 100;
    _appConfig.geometry.y = 100;
    _appConfig.geometry.width = 1024;
    _appConfig.geometry.height = 700;
    _appConfig.hasCentralWidget = false;
    _appConfig.isFullScreen = false;
    _appConfig.showMenuBar = false;
    _appConfig.showStatusBar = false;
    _appConfig.showToolBar = false;
    _appConfig.toolBarLocation = "top";

    QString currentElement = "";

    QXmlStreamReader xmlReader(config);
    while(!xmlReader.atEnd())
    {
        xmlReader.readNext();
        if(xmlReader.isStartElement())
        {
            currentElement = xmlReader.name().toString();

            if("AppConfig" == xmlReader.name())
            {
                if("true" == xmlReader.attributes().value("isFullscreen").toString().toLower())
                {
                    _appConfig.isFullScreen = true;
                }
                if("true" == xmlReader.attributes().value("hasCentralWidget").toString().toLower())
                {
                    _appConfig.hasCentralWidget = true;
                }
            }
            else if("Geometry" == xmlReader.name())
            {
                _appConfig.geometry.x = xmlReader.attributes().value("x").toString().toInt();
                _appConfig.geometry.y = xmlReader.attributes().value("y").toString().toInt();
                _appConfig.geometry.width = xmlReader.attributes().value("width").toString().toInt();
                _appConfig.geometry.height = xmlReader.attributes().value("height").toString().toInt();
            }
            else if("MenuBar" == xmlReader.name())
            {
                if("true" == xmlReader.attributes().value("isVisible").toString().toLower())
                {
                    _appConfig.showMenuBar = true;
                }
            }
            else if("ToolBar" == xmlReader.name())
            {
                if("true" == xmlReader.attributes().value("isVisible").toString().toLower())
                {
                    _appConfig.showToolBar = true;
                }
            }
            else if("StatusBar" == xmlReader.name())
            {
                if("true" == xmlReader.attributes().value("isVisible").toString().toLower())
                {
                    _appConfig.showToolBar = true;
                }
                _appConfig.toolBarLocation = xmlReader.attributes().value("location").toString().toLower();
            }
        }
        else if(xmlReader.isCharacters() && !xmlReader.isWhitespace())
        {
        }
        else if(xmlReader.isEndElement())
        {
            if("AppConfig" == xmlReader.name())
            {
            }
        }
    }
    if(xmlReader.hasError())
    {
        std::cout << "WARNING: There was an error while loading configuration." << std::endl;
        std::cout << "WARNING: You may continue to run as is, but the system may not functoin correctly." << std::endl;
    }
}

PKConfigManager::PluginConfig PKConfigManager::ParsePluginConfig(QString& config)
{

}
