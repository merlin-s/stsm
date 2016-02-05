#ifdef QT_VERSION
#include "debug.h"
#include <qdatetime.h>
#include <qt_windows.h>

QObject *DBG_OBJ = nullptr;

void QDebugVSOutput(QtMsgType Type, const QMessageLogContext &Context,
                    const QString &Message) {
  OutputDebugString(reinterpret_cast<const wchar_t *>(Message.utf16()));
  if (DBG_OBJ) {
    quint64 currSecs = QDateTime::currentMSecsSinceEpoch() / 1000;
    DBG_OBJ->setProperty(
        "text", (Message + QVariant::fromValue((currSecs) % 10000).toString()));
  }
}
#endif
