
#include <QFont>

#include "core/Integration/integration.h"
#include "core/Integration/qode-api.h"
#include "QtGui/QApplication/napplication.hpp"
namespace qodeIntegration {
  static NApplication* app;

  int QtRunLoopWrapper() {
    int exitCode = app->exec();
    // if(exitCode != 0){
    exit(exitCode);
    // }
    return 0;
  }

  void integrate() {
    // Bootstrap Qt
    app = new NApplication(qode::qode_argc, qode::qode_argv);
    qode::InjectCustomRunLoop(&QtRunLoopWrapper);
    // Other init settings
    QFont f = QApplication::font();
    if (f.defaultFamily().isEmpty()) {
      f.setFamily("Sans-Serif");
      QApplication::setFont(f);
    }
  }
}  // namespace qodeIntegration