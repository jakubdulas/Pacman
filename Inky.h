#pragma once
#include "Ghost.h"
#include "Pacman.h"
#include "Blinky.h"


class Inky : public Ghost
{
public:
    Inky(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0, Pacman *pacman = nullptr, Blinky *blinky = nullptr);
    void makeMove();

private:
    Blinky *blinky;
};
