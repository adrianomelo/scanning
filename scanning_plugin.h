#ifndef SCANNING_PLUGIN_H
#define SCANNING_PLUGIN_H

#include <QtDeclarative/QDeclarativeExtensionPlugin>

class ScanningPlugin : public QDeclarativeExtensionPlugin
{
    Q_OBJECT
    
public:
    void registerTypes(const char *uri);
};

#endif // SCANNING_PLUGIN_H

