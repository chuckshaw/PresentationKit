#ifndef PKSCRIPTMANAGER_H
#define PKSCRIPTMANAGER_H

#include "pkmanager.h"
#include "pkscripteditor.h"

#include <QtScript>

class PKScriptManager : public PKManager
{
    Q_OBJECT

public:
    explicit PKScriptManager(PresentationKit *parent, const char* name=0);
    virtual ~PKScriptManager();
    
    QScriptEngine* GetScriptEngine() { return _engine; }
    PKScriptEditor* GetScriptEditor() { return _scriptEditor; }

signals:
    
public slots:
    void Slot_AddToEngine(QObject* obj);
    void Slot_EvaluateFile(QString& file);
    void Slot_EvaluateScript(QString& script, QString& name);
    QScriptValue Slot_EvaluateFunction(QString& function);

private:
    QScriptEngine* _engine;
    QScriptValue _globalScript;
    PKScriptEditor* _scriptEditor;
    
};

#endif // PKSCRIPTMANAGER_H
