
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/qapplication.h>

#include "gui/mainwindow.h"

#include "game/crewman.h"
#include "util/debug.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  gui::MainWindow mainWindowInstance;
  gui::mainWindow = &mainWindowInstance;

  gui::mainWindow->GameLoop();

  // return a.exec();
  return 0;
}
