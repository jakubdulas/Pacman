#include "Pacman.h"

Pacman::Pacman(QWidget *parent, int initialXX, int initialYY)
    : Character(parent, initialXX, initialYY)
{
    direction = RIGHT;
    newDirection = RIGHT;
    imgLabel->setPixmap(rightImage);
    this->setGeometry(initialX * gap_size * scale, initialY * gap_size * scale, rightImage.width(), rightImage.height());

    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    lives = 3;
    score = 0;
}

void Pacman::makeMove()
{
    Character::makeMove();

    if (direction == UP)
    {
        imgLabel->setPixmap(upImage);
    }
    else if (direction == DOWN)
    {
        imgLabel->setPixmap(downImage);
    }
    else if (direction == RIGHT)
    {
        imgLabel->setPixmap(rightImage);
    }
    else if (direction == LEFT)
    {
        imgLabel->setPixmap(leftImage);
    }
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        changeDirection(UP);
        break;
    case Qt::Key_Down:
        changeDirection(DOWN);
        break;
    case Qt::Key_Left:
        changeDirection(LEFT);
        break;
    case Qt::Key_Right:
        changeDirection(RIGHT);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

bool Pacman::canEatPoint(const Point &p)
{
    if (position->x() == p.position->x() && position->y() == p.position->y())
    {
        if (p.isSuper)
        {
            score += 20;
        }
        else
        {
            score += 10;
        }
        return true;
    }
    return false;
}

void Pacman::kill()
{
    --lives;
}

bool Pacman::isDead()
{
    return lives <= 0;
}

int Pacman::getScore()
{
    return score;
}

void Pacman::eatGhost()
{
    score += 50;
}
