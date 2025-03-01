#include <iostream>
#include <QApplication>
#include <QSlider>
#include <QSpinBox>

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    auto *slider = new QSlider(Qt::Horizontal);
    auto *spinbox = new QSpinBox();
    slider->setMinimum(0);
    slider->setMaximum(100);
    spinbox->setMinimum(0);
    spinbox->setMaximum(100);

    QObject::connect(slider, &QSlider::valueChanged, spinbox, &QSpinBox::setValue);
    QObject::connect(spinbox, QOverload<int>::of(&QSpinBox::valueChanged), slider, &QSlider::setValue);
    // QOverload позволяет выбрать одну функцию из нескольких
    slider->resize(50, 10);
    spinbox->resize(20, 20);
    spinbox->move(900, 500);
    slider->move(800, 500);

    slider->show();
    spinbox->show();

    app.exec();
    // Только после закрытия обоих окон программа завершится, с кодом выхода 0
}
