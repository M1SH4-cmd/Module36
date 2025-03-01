#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QTimer>

class ImageButton : public QPushButton
{
Q_OBJECT

public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Stop");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    mButtonUpPixmap = QPixmap("C:\\Users\\User\\Desktop\\Module36\\Notes\\Note3\\ButtonIsOn.jpg");
    mButtonDownPixmap = QPixmap("C:\\Users\\User\\Desktop\\Module36\\Notes\\Note3\\ButtonIsOff.jpg");

    if (mButtonUpPixmap.isNull() || mButtonDownPixmap.isNull()) {
        std::cerr << "Failed to load button images!" << std::endl;
        return;
    }

    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setUp);
}

void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const {
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent *e) {
    setDown();
    QPushButton::keyPressEvent(e);
}

void ImageButton::setDown() {
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp() {
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    ImageButton button(nullptr);
    button.setFixedSize(100, 100);
    button.move(550, 350);

    QObject::connect(&button, &QPushButton::clicked, []() {std::cout << "clicked!\n" << std::endl;});

    button.show();

    return app.exec();
}

#include <main.moc>