#include <QtGui/QApplication>
#include "presentationkit.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString appName = QString(argv[0]).mid(QString(argv[0]).lastIndexOf("\\")+1);
    if(appName.endsWith(".exe")) //windows
    {
        appName.chop(4);
    }
    else //osx & linux
    {
        appName = QString(argv[0]).mid(QString(argv[0]).lastIndexOf("/")+1);
    }
    a.setApplicationName(appName);
    a.setApplicationVersion("0.0.1");


    PresentationKit PKMain;
    PKMain.setObjectName("PresentationKit");
    PKMain.GetMainWindow()->show();
    
    return a.exec();
}
