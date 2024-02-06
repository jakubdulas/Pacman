#pragma once
#include "Ghost.h"
#include "Character.h"
#include "Pacman.h"

class Blinky : public Ghost
{
public:
    Blinky(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0, Pacman *pacman = nullptr);
    void makeMove();
};
