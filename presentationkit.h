#ifndef PRESENTATIONKIT_H
#define PRESENTATIONKIT_H

#include "pkmainwindow.h"

#include <QObject>
#include <QMainWindow>

class PresentationKit : public QObject
{
    Q_OBJECT
public:
    explicit PresentationKit(QObject *parent = 0);
    ~PresentationKit();

    PKMainWindow* GetMainWindow() const { return _PKMainWindow; }

signals:
    
public slots:

private:
    void Ignition();
    PKMainWindow* _PKMainWindow;
    
};

#endif // PRESENTATIONKIT_H
