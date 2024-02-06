#include "Blinky.h"

Blinky::Blinky(QWidget *parent, int initialXX, int initialYY, Pacman *pacman) : Ghost(parent, initialXX, initialYY, QPixmap("pacman-art/ghosts/blinky.png"), pacman)
{
    scaredPosition = new QPoint(board_width - 3, -3);
}

void Blinky::makeMove()
{

    QPoint *p;
    if (isScared)
    {
        p = new QPoint(scaredPosition->x(), scaredPosition->y());
    }
    else
    {
        p = new QPoint(pacman->position->x(), pacman->position->y());
    }
    followPoint(*p);
    Character::makeMove();
}
