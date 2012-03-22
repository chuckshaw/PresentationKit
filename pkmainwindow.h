#ifndef PKMAINWINDOW_H
#define PKMAINWINDOW_H

#include <QApplication>
#include <QMainWindow>

class PresentationKit;

class PKMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit PKMainWindow(PresentationKit *parent = 0, Qt::WFlags flags = 0);
    ~PKMainWindow();
    void SetupUI();
    
protected:
    PresentationKit* _presentationKit;
private:

};

#endif // PKMAINWINDOW_H
