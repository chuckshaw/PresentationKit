#include "pkmanager.h"
#include "presentationkit.h"

PKManager::PKManager(PresentationKit* parent, const char* name) :
    QObject(0)
{
    _presentationKit = parent;
}

PKManager::~PKManager()
{
}
