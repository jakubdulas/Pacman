#include "Ghost.h"

Ghost::Ghost(QWidget *parent, int initialXX, int initialYY, QPixmap image, Pacman *pacman)
    : Character(parent, initialXX, initialYY)
{
    this->pacman = pacman;
    this->image = image;
    imgLabel->setPixmap(image);
    this->setGeometry(initialX * gap_size * scale, initialY * gap_size * scale, image.width(), image.height());
    this->isScared = false;
    timer = new QTimer(this);
    timer->setSingleShot(true);
    baseExitPosition = new QPoint(14, 11);

    connect(timer, SIGNAL(timeout()), this, SLOT(finishScare()));
}

void Ghost::scare()
{
    timer->start(1000 * scared_duration);
    imgLabel->setPixmap(scaredImage);
    isScared = true;
}

void Ghost::finishScare()
{
    timer->stop();
    this->isScared = false;
    imgLabel->setPixmap(image);
}

int Ghost::calculateDistance(const QPoint &a, const QPoint &b)
{
    return (a.x() - b.x())*(a.x() - b.x()) + (a.y() - b.y())*(a.y() - b.y());
}

void Ghost::reverse()
{
    if (direction == LEFT)
        direction = RIGHT;
    if (direction == RIGHT)
        direction = LEFT;
    if (direction == UP)
        direction = DOWN;
    if (direction == DOWN)
        direction = UP;
}

void Ghost::followPoint(const QPoint &p)
{
    if (isInBase())
    {
        newDirection = UP;
        return;
    }

    int minDist = 10000000;
    int dist;
    Direction d;
    if (canGoRight() && direction != LEFT)
    {
        position->setX(position->x() + 1);
        dist = calculateDistance(*position, p);
        if (dist < minDist)
        {
            minDist = dist;
            d = RIGHT;
        }
        position->setX(position->x() - 1);
    }
    if (canGoLeft() && direction != RIGHT)
    {
        position->setX(position->x() - 1);
        dist = calculateDistance(*position, p);
        if (dist < minDist)
        {
            minDist = dist;
            d = LEFT;
        }
        position->setX(position->x() + 1);
    }
    if (canGoUp() && direction != DOWN)
    {
        position->setY(position->y() - 1);
        dist = calculateDistance(*position, p);
        if (dist < minDist)
        {
            minDist = dist;
            d = UP;
        }
        position->setY(position->y() + 1);
    }
    if (canGoDown() && direction != UP)
    {
        position->setY(position->y() + 1);
        dist = calculateDistance(*position, p);
        if (dist < minDist)
        {
            minDist = dist;
            d = DOWN;
        }
        position->setY(position->y() - 1);
    }
    newDirection = d;
}

bool Ghost::isInBase()
{
    return (13 < position->x() && position->x() < 16) && (11 < position->y() && position->y() < 15);
}
