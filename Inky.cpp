#include "Inky.h"

Inky::Inky(QWidget *parent, int initialXX, int initialYY, Pacman *pacman, Blinky *blinky) : Ghost(parent, initialXX, initialYY, QPixmap("pacman-art/ghosts/inky.png"), pacman)
{
    scaredPosition = new QPoint(board_width, board_height);
    this->blinky = blinky;
}

void Inky::makeMove()
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
            p->setX(p->x() + 2);
        if (pacman->direction == LEFT)
            p->setX(p->x() - 2);
        if (pacman->direction == UP)
            p->setY(p->y() - 2);
        if (pacman->direction == DOWN)
            p->setY(p->y() + 2);
        int dx = position->x() - blinky->position->x();
        int dy = position->y() - blinky->position->y();
        p->setY(p->y() + dy);
        p->setX(p->x() + dx);
    }
    followPoint(*p);
    Character::makeMove();
}
