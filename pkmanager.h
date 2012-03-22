#ifndef PKMANAGER_H
#define PKMANAGER_H

#include <QObject>

class PresentationKit;

class PKManager : public QObject
{
    Q_OBJECT
public:
    explicit PKManager(PresentationKit *parent, const char* name=0);
    virtual ~PKManager();

signals:
    
public slots:

protected:
    PresentationKit* _presentationKit;
    
};

#endif // PKMANAGER_H
