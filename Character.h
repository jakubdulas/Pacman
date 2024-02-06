#pragma once
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QPoint>
#include <QKeyEvent>
#include <QDebug>
#include "Direction.h"
#include "constants.h"

using namespace constants;

class Character : public QWidget
{
    Q_OBJECT
public:
    Character(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0);

    virtual void makeMove();
    void goToInitialPosition();
    void changeDirection(Direction d);
    bool collidesWith(const Character &c);
    QPoint *position;
    Direction direction;

protected:
    QLabel *imgLabel;
    Direction newDirection;
    void updatePosition();
    void moveInDirection(Direction d);
    bool canGoRight();
    bool canGoLeft();
    bool canGoDown();
    bool canGoUp();
    QPixmap image;
    int initialX;
    int initialY;
};