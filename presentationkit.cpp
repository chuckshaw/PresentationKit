#include "presentationkit.h"

#include <QtGui>

#ifdef WIN32
static QString osType = "windows";
#elif MACOSX
static QString osType = "macosx";
#elif UNIX
static QString osType = "linux";
#elif LINUX
static QString osType = "linux";
#else
static QString osType = "unknown";
#endif

PresentationKit::PresentationKit(QObject *parent) :
    QObject(parent)
{
    _PKMainWindow = NULL;

    Ignition();
}

PresentationKit::~PresentationKit()
{
    if(_PKMainWindow)
    {
        delete _PKMainWindow;
        _PKMainWindow = NULL;
    }
}

void PresentationKit::Ignition()
{
    _PKMainWindow = new PKMainWindow(this, Qt::Window);
}
