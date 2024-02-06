#pragma once
#include "Ghost.h"
#include "Character.h"
#include "Pacman.h"


class Pinky : public Ghost
{
public:
    Pinky(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0, Pacman *pacman = nullptr);
    void makeMove();
};
