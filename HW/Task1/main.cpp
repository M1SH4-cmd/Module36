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
        mGreenCircle = QPixmap("GreenCircle.png");
        mYellowCircle = QPixmap("YellowCircle.png");
        mRedCircle = QPixmap("RedCircle.png");

        if (mGreenCircle.isNull() || mYellowCircle.isNull() || mRedCircle.isNull()) {
            std::cerr << "Failed to load circle images!" << std::endl;
            return;
        }

        mCurrentCircle = mGreenCircle;
        setFixedSize(100, 100);
    }

    QSize minimumSizeHint() const override {
        return QSize(100, 100);
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
    window.setFixedSize(200, 250);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    ColorfulCircle *circle = new ColorfulCircle(nullptr);
    layout->addWidget(circle, 0, Qt::AlignCenter);

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);
    layout->addWidget(slider);

    QObject::connect(slider, &QSlider::valueChanged, [&circle](int newValue) {
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