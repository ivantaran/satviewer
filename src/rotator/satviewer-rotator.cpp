
#include "../gui/RotatorWidget.h"
#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    RotatorWidget rotator;
    rotator.show();
    return app.exec();
}
