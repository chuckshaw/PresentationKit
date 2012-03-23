#ifndef PKMAINWINDOW_H
#define PKMAINWINDOW_H

#include <QApplication>
#include <QtGui>
#include <QMainWindow>

class PresentationKit;

class PKMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PKMainWindow(PresentationKit *parent = 0, Qt::WFlags flags = 0);
    ~PKMainWindow();
    void SetupUI();
    
public slots:
    void Slot_About();
    void Slot_ScriptEditor();

protected:
    void CreateActions();
    void CreateMenuBar(bool isVisible);
    void CreateToolBar(bool isVisible);
    void CreateStatusBar(bool isVisible);

    PresentationKit* _presentationKit;

private:
    //UI
    QMenuBar* _menuBar;
    QToolBar* _toolBar;
    QToolBar* _devToolBar;

    QMenu* _fileMenu;
    QMenu* _devMenu;
    QMenu* _helpMenu;

    //Actions
    QAction* _exitAction;
    QAction* _scriptAction;
    QAction* _aboutAction;
    QAction* _aboutQtAction;
};

#endif // PKMAINWINDOW_H
