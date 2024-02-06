#pragma once
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QString>
#include "Character.h"
#include "Point.h"

class Pacman : public Character
{
public:
    Pacman(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0);
    void makeMove() override;
    bool canEatPoint(const Point &p);
    bool isDead();
    void kill();
    int getScore();
    void eatGhost();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QPixmap leftImage{"pacman-art/pacman-left/1.png"};
    QPixmap rightImage{"pacman-art/pacman-right/1.png"};
    QPixmap upImage{"pacman-art/pacman-up/1.png"};
    QPixmap downImage{"pacman-art/pacman-down/1.png"};
    int lives;
    int score;
};
