#include "Point.h"

Point::Point(QWidget *parent, int x, int y, bool isSuper_) : QWidget(parent)
{
    position = new QPoint(x, y);
    imgLabel = new QLabel(this);
    this->isSuper = isSuper_;

    QString imageFile;

    if (isSuper)
    {
        imageFile = QString("pacman-art/other/strawberry.png");
    }
    else
    {
        imageFile = QString("pacman-art/other/dot.png");
    }

    QPixmap image(imageFile);
    imgLabel->setPixmap(image);
    this->setGeometry(x * gap_size * scale, y * gap_size * scale, image.width(), image.height());
}

void Point::kill()
{
    position->setX(-1);
    position->setY(-1);
    this->move(position->x() * scale * gap_size, position->y() * scale * gap_size);
}
