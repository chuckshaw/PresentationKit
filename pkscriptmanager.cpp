#include "pkscriptmanager.h"
#include "presentationkit.h"

PKScriptManager::PKScriptManager(PresentationKit *parent, const char* name) :
    PKManager(parent, name)
{
    _engine = new QScriptEngine();

    this->setObjectName("PKScriptManager");
    this->Slot_AddToEngine(this);
}

PKScriptManager::~PKScriptManager()
{
    if(_engine)
    {
        delete _engine;
        _engine = NULL;
    }
}

void PKScriptManager::Slot_AddToEngine(QObject* obj)
{
    if(_engine)
    {
        QScriptValue scriptObj = _engine->newQObject(obj);
        _engine->globalObject().setProperty(obj->objectName(), scriptObj);
    }
}

void PKScriptManager::Slot_EvaluateFile(QString& file)
{
//TODO
}

void PKScriptManager::Slot_EvaluateScript(QString& script, QString& name)
{
//TODO
}

QScriptValue PKScriptManager::Slot_EvaluateFunction(QString& function)
{
//TODO
}
