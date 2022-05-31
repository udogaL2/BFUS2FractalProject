#include <QApplication>
#include "inc/MainMenu.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    fg::MainMenu prog;
    prog.setWindowIcon(QIcon("../fractal.ico"));
    prog.show();

    return app.exec();
}
