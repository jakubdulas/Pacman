#include "Clyde.h"

Clyde::Clyde(QWidget *parent, int initialXX, int initialYY, Pacman *pacman) : Ghost(parent, initialXX, initialYY, QPixmap("pacman-art/ghosts/clyde.png"), pacman)
{
    scaredPosition = new QPoint(0, board_height + 2);
}

void Clyde::makeMove()
{
    int dist = getManhattanDistanceFromPacman();
    QPoint *p;
    if (isScared || dist <= 8)
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

int Clyde::getManhattanDistanceFromPacman()
{
    return std::abs(pacman->position->x() - position->x()) + std::abs(pacman->position->y() - position->y());
}
