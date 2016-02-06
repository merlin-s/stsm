
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/qapplication.h>

#include "gui/mainwindow.h"

#include "game/crewman.h"
#include "util/debug.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  gui::MainWindow mainWindowInstance;
  gui::mainWindow = &mainWindowInstance;
  // qInstallMessageHandler(QDebugVSOutput);
  // gui::init();
  // gui::MainWindow window(QUrl::fromLocalFile("MainWindow.qml"));
  gui::mainWindow->Start();
  // return a.exec();
  return 0;
}