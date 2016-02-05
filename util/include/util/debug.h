#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <exception>
#include <qbytearray.h>
#include <qdebug.h>

#ifndef QT
extern QObject *DBG_OBJ;
void QDebugVSOutput(QtMsgType Type, const QMessageLogContext &Context,
                    const QString &Message);
#endif

inline void runtime_assert_func(bool b, const char *file, int line,
                                const std::string &&msg) {
  if (!b) {
    const char *msgbase = "runtime assert failed:\n"
                          "   FILE: %s\n"
                          "   LINE: %d\n"
                          "   MSG:  %s\n\n";
    char arr[200];
    qsnprintf(arr, sizeof(arr), msgbase, file, line, msg.c_str());
    throw std::runtime_error(arr);
  }
}

#define runtime_assert(b, msg) runtime_assert_func(b, __FILE__, __LINE__, msg);

#endif
