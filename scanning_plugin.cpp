#include "scanning_plugin.h"
#include "scanning.h"
#include "scangroup.h"

#include <QtDeclarative/qdeclarative.h>

void ScanningPlugin::registerTypes(const char *uri)
{
    // @uri com.adrianomelo
    qmlRegisterType<Scanning>(uri, 1, 0, "Scanning");
    qmlRegisterType<ScanGroup>(uri, 1, 0, "ScanGroup");
}

Q_EXPORT_PLUGIN2(Scanning, ScanningPlugin)
