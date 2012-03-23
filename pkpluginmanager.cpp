#include "pkpluginmanager.h"
#include "presentationkit.h"

PKPluginManager::PKPluginManager(PresentationKit *parent, const char* name) :
    PKManager(parent, name)
{
}

PKPluginManager::~PKPluginManager()
{
}
