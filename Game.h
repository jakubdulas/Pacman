#pragma once
#include <QWidget>
#include <QTimer>
#include <QMessageBox>
#include "GameBoard.h"
#include "Pacman.h"
#include "Direction.h"
#include "Point.h"
#include "EndScreen.h"
#include "Pinky.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

private:
    void initObjects();
    void loadPoints();
    void initGhosts();
    void eatPoint();
    void reset();
    void showEndScreen(QString str);
    void checkCollisions();
    void checkResult();
    void moveGhosts();

    GameBoard *board;
    Pacman *pacman;
    EndScreen *endScreen;
    QTimer *timer;
    QVector<Point *> points;
    QVector<Ghost *> ghosts;

private slots:
    void step();
    void resetSlot();
};