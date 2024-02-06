#include "Pinky.h"

Pinky::Pinky(QWidget *parent, int initialXX, int initialYY, Pacman *pacman) : Ghost(parent, initialXX, initialYY, QPixmap("pacman-art/ghosts/pinky.png"), pacman)
{
    scaredPosition = new QPoint(3, -3);
}

void Pinky::makeMove()
{

    QPoint *p;
    if (isScared)
    {
        p = new QPoint(scaredPosition->x(), scaredPosition->y());
    }
    else
    {
        p = new QPoint(pacman->position->x(), pacman->position->y());
        if (pacman->direction == RIGHT)
            p->setX(p->x() + 4);
        if (pacman->direction == LEFT)
            p->setX(p->x() - 4);
        if (pacman->direction == UP)
            p->setY(p->y() - 4);
        if (pacman->direction == DOWN)
            p->setY(p->y() + 4);
    }
    followPoint(*p);
    Character::makeMove();
}
