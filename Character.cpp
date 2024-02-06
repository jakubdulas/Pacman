#include "Character.h"

Character::Character(QWidget *parent, int initialXX, int initialYY) : QWidget(parent)
{
    initialX = initialXX;
    initialY = initialYY;
    position = new QPoint(initialXX, initialYY);
    imgLabel = new QLabel(this);
}

bool Character::canGoRight()
{
    if (position->y() == portal_level && position->x() == grid_width - 1)
    {
        return true;
    }
    return matrix[position->y()][position->x() + 1] != wall;
}
bool Character::canGoLeft()
{
    if (position->y() == portal_level && position->x() == 0)
    {
        return true;
    }
    return matrix[position->y()][position->x() - 1] != wall;
}
bool Character::canGoDown()
{
    return matrix[position->y() + 1][position->x()] != wall && matrix[position->y() + 1][position->x()] != door;
}
bool Character::canGoUp()
{
    return matrix[position->y() - 1][position->x()] != wall;
}

void Character::makeMove()
{
    // direction = newDirection;
    // if (direction == UP && canGoUp())
    // {
    //     position->setY(position->y() - 1);
    // }
    // else if (direction == DOWN && canGoDown())
    // {
    //     position->setY(position->y() + 1);
    // }
    // else if (direction == RIGHT && canGoRight())
    // {
    //     if (position->x() + 1 >= grid_width)
    //     {
    //         position->setX(0);
    //     }
    //     else
    //     {
    //         position->setX(position->x() + 1);
    //     }
    // }
    // else if (direction == LEFT && canGoLeft())
    // {
    //     if (position->x() - 1 < 0)
    //     {
    //         position->setX(grid_width - 1);
    //     }
    //     else
    //     {
    //         position->setX(position->x() - 1);
    //     }
    // }

    if (newDirection == UP && canGoUp())
    {
        moveInDirection(UP);
        direction = newDirection;
    }
    else if (newDirection == DOWN && canGoDown())
    {
        moveInDirection(DOWN);
        direction = newDirection;
    }
    else if (newDirection == RIGHT && canGoRight())
    {
        moveInDirection(RIGHT);
        direction = newDirection;
    }
    else if (newDirection == LEFT && canGoLeft())
    {
        moveInDirection(LEFT);
        direction = newDirection;
    }
    else
    {
        moveInDirection(direction);
    }

    updatePosition();
}

void Character ::moveInDirection(Direction d)
{
    if (d == UP && canGoUp())
    {
        position->setY(position->y() - 1);
    }
    else if (d == DOWN && canGoDown())
    {
        position->setY(position->y() + 1);
    }
    else if (d == RIGHT && canGoRight())
    {
        if (position->x() + 1 >= grid_width)
        {
            position->setX(0);
        }
        else
        {
            position->setX(position->x() + 1);
        }
    }
    else if (d == LEFT && canGoLeft())
    {
        if (position->x() - 1 < 0)
        {
            position->setX(grid_width - 1);
        }
        else
        {
            position->setX(position->x() - 1);
        }
    }
}

void Character ::updatePosition()
{
    this->move(position->x() * scale * gap_size, position->y() * scale * gap_size);
}

void Character::goToInitialPosition()
{
    position->setX(initialX);
    position->setY(initialY);
    updatePosition();
}

void Character::changeDirection(Direction d)
{

    // if (d == UP && canGoUp())
    // {
    //     newDirection = d;
    // }
    // else if (d == DOWN && canGoDown())
    // {
    //     newDirection = d;
    // }
    // else if (d == RIGHT && canGoRight())
    // {
    //     newDirection = d;
    // }
    // else if (d == LEFT && canGoLeft())
    // {
    //     newDirection = d;
    // }

    newDirection = d;
}

bool Character::collidesWith(const Character &c)
{
    return position->x() == c.position->x() && position->y() == c.position->y();
}
