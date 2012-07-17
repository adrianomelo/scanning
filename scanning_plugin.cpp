#include "scanning_plugin.h"
#include "scangroup.h"
#include "scanningcontrol.h"

#include <QtDeclarative/qdeclarative.h>

void ScanningPlugin::registerTypes(const char *uri)
{
    // @uri com.adrianomelo
    qmlRegisterType<ScanGroup>(uri, 1, 0, "ScanGroup");
    qmlRegisterType<ScanningControl>(uri, 1, 0, "ScanningControl");
}

Q_EXPORT_PLUGIN2(Scanning, ScanningPlugin)
