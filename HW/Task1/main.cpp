#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget w;
    QLabel label(&w);

    QPixmap pixmap(":/images/green_circle.png");
    if (pixmap.isNull()) {
        label.setText("Image not loaded!");
    } else {
        label.setPixmap(pixmap);
    }

    w.show();
    return a.exec();
}