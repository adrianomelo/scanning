#include "scanning_plugin.h"
#include "scanning.h"

#include <QtDeclarative/qdeclarative.h>

void ScanningPlugin::registerTypes(const char *uri)
{
    // @uri com.adrianomelo
    qmlRegisterType<Scanning>(uri, 1, 0, "Scanning");
}

Q_EXPORT_PLUGIN2(Scanning, ScanningPlugin)

