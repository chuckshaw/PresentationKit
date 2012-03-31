#include "pkmainwindow.h"
#include "presentationkit.h"
#include "pkconfigmanager.h"

PKMainWindow::PKMainWindow(PresentationKit *parent, Qt::WFlags flags) :
    QMainWindow(0, flags)
{
    _presentationKit = parent;

    _menuBar = NULL;
    _toolBar = NULL;
    _fileMenu = NULL;
    _devMenu = NULL;
    _helpMenu = NULL;
    _exitAction = NULL;
    _scriptAction = NULL;
    _aboutAction = NULL;
    _aboutQtAction = NULL;

    SetupUI();
}

PKMainWindow::~PKMainWindow()
{
    if(_menuBar)
    {
        delete _menuBar;
        _menuBar = NULL;
    }

    if(_toolBar)
    {
        delete _toolBar;
        _toolBar = NULL;
    }

    if(_devToolBar)
    {
        delete _devToolBar;
        _devToolBar = NULL;
    }

    if(_fileMenu)
    {
        delete _fileMenu;
        _fileMenu = NULL;
    }

    if(_devMenu)
    {
        delete _devMenu;
        _devMenu = NULL;
    }

    if(_helpMenu)
    {
        delete _helpMenu;
        _helpMenu = NULL;
    }

    if(_exitAction)
    {
        delete _exitAction;
        _exitAction = NULL;
    }

    if(_aboutAction)
    {
        delete _aboutAction;
        _aboutAction = NULL;
    }

    if(_aboutQtAction)
    {
        delete _aboutQtAction;
        _aboutQtAction = NULL;
    }
}

void PKMainWindow::SetupUI()
{
    CreateActions();
    CreateMenuBar(true);
    CreateToolBar(true);
    CreateStatusBar(true);

    //Set Default Geometry
    //this->setGeometry(100, 100, 1280, 800);
    this->resize(1200, 800);
    this->setWindowTitle(qApp->applicationName());
}

void PKMainWindow::CreateActions()
{
    _exitAction = new QAction(QIcon(":/images/Resources/system-log-out.png"), tr("Exit"), this);
    connect(_exitAction, SIGNAL(triggered()), _presentationKit, SLOT(Slot_ExitApplication()));

    _scriptAction = new QAction(QIcon(":/images/Resources/text-x-generic.png"), tr("Script Editor"), this);
    connect(_scriptAction, SIGNAL(triggered()), this, SLOT(Slot_ScriptEditor()));

    _aboutAction = new QAction(tr("&About"), this);
    _aboutAction->setStatusTip(tr("Show the application's About box"));
    connect(_aboutAction, SIGNAL(triggered()), this, SLOT(Slot_About()));

    _aboutQtAction = new QAction(tr("About &Qt"), this);
    _aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(_aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void PKMainWindow::CreateMenuBar(bool isVisible)
{
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_exitAction);

    _devMenu = menuBar()->addMenu(tr("&Developer"));
    _devMenu->addAction(_scriptAction);

    _helpMenu = menuBar()->addMenu(tr("&Help"));
    _helpMenu->addAction(_aboutAction);
    _helpMenu->addAction(_aboutQtAction);
}

void PKMainWindow::CreateToolBar(bool isVisible)
{
    _toolBar = this->addToolBar("PKToolBar");
    _toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    //_toolBar->setIconSize(QSize(25, 25));
    _toolBar->setAutoFillBackground(true);

    _devToolBar = this->addToolBar("DevToolBar");
    _devToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    //_devToolBar->setIconSize(QSize(25, 25));
    _devToolBar->setAutoFillBackground(true);

    if(isVisible)
    {
        _toolBar->show();
        _devToolBar->show();
    }
    else
    {
        _toolBar->hide();
        _devToolBar->hide();
    }

    _toolBar->addAction(_exitAction);
    _devToolBar->addAction(_scriptAction);
}

void PKMainWindow::CreateStatusBar(bool isVisible)
{
    if(isVisible)
    {
        statusBar()->showMessage(tr("Ready"));
    }
}

void PKMainWindow::Slot_About()
{
    QMessageBox::about(this, tr("About PresentationKit"),
                       tr("PresentationKit Version ") + qApp->applicationVersion());
}

void PKMainWindow::Slot_ScriptEditor()
{
    //QMessageBox::information(this, tr("Developer"), tr("Implement Script Editor"));
    _presentationKit->GetScriptManager()->GetScriptEditor()->show();
}
