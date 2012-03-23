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
    _PKPluginManager = NULL;
    _PKScriptManager = NULL;

    Ignition();
}

PresentationKit::~PresentationKit()
{
    if(_PKMainWindow)
    {
        delete _PKMainWindow;
        _PKMainWindow = NULL;
    }

    if(_PKPluginManager)
    {
        delete _PKPluginManager;
        _PKPluginManager = NULL;
    }

    if(_PKScriptManager)
    {
        delete _PKScriptManager;
        _PKScriptManager = NULL;
    }
}

void PresentationKit::Ignition()
{
    _PKScriptManager = new PKScriptManager(this);
    _PKMainWindow = new PKMainWindow(this, Qt::Window);
    _PKPluginManager = new PKPluginManager(this);

    _PKScriptManager->Slot_AddToEngine(this);
}

void PresentationKit::Slot_ExitApplication()
{
    QMessageBox msgBox;
    msgBox.setText("Are you sure you want to exit the application?");
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);

    switch (msgBox.exec())
    {
        case QMessageBox::Ok:
            QApplication::closeAllWindows();
            break;
        case QMessageBox::Cancel:
            return;
            break;
        default:
            // should never be reached
            break;
    }
}
