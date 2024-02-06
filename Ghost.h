#pragma once
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QPoint>
#include <QTimer>
#include <stdio.h>
#include <stdbool.h>
#include "Character.h"
#include "Pacman.h"
#include "constants.h"

using namespace constants;
using namespace std;

class Ghost : public Character
{
    Q_OBJECT
public:
    Ghost(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0, QPixmap image = QPixmap(), Pacman *pacman = nullptr);
    void scare();
    bool isScared;
    QPoint *scaredPosition;
    QPoint *baseExitPosition;
    Pacman *pacman;
    void reverse();

protected:
    int calculateDistance(const QPoint &a, const QPoint &b);
    void followPoint(const QPoint &p);
    bool isInBase();

private:
    QPixmap scaredImage{"pacman-art/ghosts/blue_ghost.png"};
    QTimer *timer;

public slots:
    void finishScare();
};
