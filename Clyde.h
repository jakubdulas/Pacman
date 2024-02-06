#pragma once
#include "Ghost.h"
#include "Character.h"
#include "Pacman.h"

class Clyde : public Ghost
{
public:
    Clyde(QWidget *parent = nullptr, int initialXX = 0, int initialYY = 0, Pacman *pacman = nullptr);
    void makeMove();

private:
    int getManhattanDistanceFromPacman();
};
