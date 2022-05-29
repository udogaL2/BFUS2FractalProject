#include <QApplication>
#include "inc/MainMenu.h"

/*
// ЁлОчка
math::Mat22d f1({{{-0.1, 0},
                  {0, 0.16}}});
math::Mat22d f2({{{-0.85, 0},
                  {0, 0.85}}});
math::Mat22d f3({{{-0.1667, -0.2887},
                  {0.2887, -0.1667}}});
math::Mat22d f4({{{-0.1667, 0.2887},
                  {-0.2887, -0.1667}}});

math::Vec2d fp1({{{0}, {1.6}}});
math::Vec2d fp2({{{0}, {1.6}}});
*/

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    fg::MainMenu prog;
    prog.show();

    return app.exec();
}
