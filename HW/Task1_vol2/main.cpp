#include "mainwindow.h"

#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>

class ColorfulCircle : public QWidget
{
    Q_OBJECT

public:
    ColorfulCircle(QWidget *parent) {
        setParent(parent);
        mGreenCircle = QPixmap(":/images/res/green_circle.png");
        mYellowCircle = QPixmap(":/images/res/yellow_circle.png");
        mRedCircle = QPixmap(":/images/res/red_circle.png");

        if (mGreenCircle.isNull() || mYellowCircle.isNull() || mRedCircle.isNull()) {
            qDebug() << "Failed to load circle images!";
            return;
        }

        mCurrentCircle = mGreenCircle;
        setFixedSize(190, 190);
    }

    QSize minimumSizeHint() const override {
        return QSize(200, 200);
    }

protected:
    void paintEvent(QPaintEvent *e) override {
        QPainter p(this);
        p.drawPixmap(e->rect(), mCurrentCircle);
    }

public slots:
    void setGreen() {
        mCurrentCircle = mGreenCircle;
        update();
    }

    void setYellow() {
        mCurrentCircle = mYellowCircle;
        update();
    }

    void setRed() {
        mCurrentCircle = mRedCircle;
        update();
    }

private:
    QPixmap mCurrentCircle;
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
};

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Colorful Circle");
    window.resize(200, 250);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    ColorfulCircle *circle = new ColorfulCircle(&window);
    layout->addWidget(circle);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    layout->addWidget(slider);

    window.setLayout(layout);

    QObject::connect(slider, &QSlider::valueChanged, circle, [&circle](int newValue) {
        if (newValue < 33) {
            circle->setGreen();
        } else if (newValue < 66) {
            circle->setYellow();
        } else {
            circle->setRed();
        }
    });

    window.show();

    return app.exec();
}
#include <main.moc>
