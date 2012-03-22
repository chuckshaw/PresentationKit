#include "pkmainwindow.h"
#include "presentationkit.h"

PKMainWindow::PKMainWindow(PresentationKit *parent, Qt::WFlags flags) :
    QMainWindow(0, flags)
{
    SetupUI();
}

PKMainWindow::~PKMainWindow()
{
}

void PKMainWindow::SetupUI()
{
    //Set Default Geometry
    this->setGeometry(100, 100, 1280, 800);

    this->setWindowTitle(qApp->applicationName());
}
