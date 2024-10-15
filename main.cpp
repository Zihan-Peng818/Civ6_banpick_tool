#include "banpicktool.h"
#include <QApplication>

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);
    BanPickTool w;
    w.setWindowTitle("Ban-Pick Tool");
    w.resize(600, 600);
    w.show();
    return a.exec();
}


