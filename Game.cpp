#include "Game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    reset();
}

void Game::reset()
{
    initObjects();
    timer = new QTimer(this);
    timer->start(timestamp);

    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
}

void Game::resetSlot()
{
    endScreen->close();
    disconnect(endScreen, SIGNAL(playAgain()), this, SLOT(resetSlot()));
    reset();
}

void Game::initObjects()
{
    board = new GameBoard(this);
    loadPoints();
    pacman = new Pacman(board, 14, 23);
    initGhosts();
    board->show();
}

void Game::loadPoints()
{
    for (int i = 0; i < grid_height; i++)
    {
        for (int j = 0; j < grid_width; j++)
        {
            if (matrix[i][j] == super_point)
            {
                Point *p = new Point(board, j, i, true);
                points.append(p);
            }
            else if (matrix[i][j] == point)
            {
                Point *p = new Point(board, j, i, false);
                points.append(p);
            }
        }
    }
}

void Game::initGhosts()
{
    Pinky *pinky = new Pinky(board, 13, 13, pacman);
    ghosts.append(pinky);
    Blinky *blinky = new Blinky(board, 13, 13, pacman);
    ghosts.append(blinky);
    Clyde *clyde = new Clyde(board, 14, 14, pacman);
    ghosts.append(clyde);
    Inky *inky = new Inky(board, 14, 14, pacman, blinky);
    ghosts.append(inky);
}

void Game::eatPoint()
{
    for (int i = points.size() - 1; i >= 0; i--)
    {
        if (pacman->canEatPoint(*points.at(i)))
        {
            if (points.at(i)->isSuper)
            {
                for (Ghost *ghost : ghosts)
                {
                    ghost->scare();
                    ghost->reverse();
                }
            }

            delete points.at(i);
            points.remove(i);
            break;
        }
    }
}

void Game::showEndScreen(QString str)
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(step()));
    endScreen = new EndScreen(this, str, pacman->getScore());
    connect(endScreen, SIGNAL(playAgain()), this, SLOT(resetSlot()));
    endScreen->show();
    board->close();
}

void Game::checkResult()
{
    if (points.size() == 0)
    {
        showEndScreen(QString("You won!"));
        return;
    }
    if (pacman->isDead())
    {
        showEndScreen(QString("You lost!"));
        return;
    }
}

void Game::step()
{
    pacman->makeMove();
    checkCollisions();
    moveGhosts();
    checkCollisions();
    eatPoint();
    checkResult();
}

void Game::checkCollisions()
{
    for (int i = 0; i < ghosts.size(); i++)
    {
        if (pacman->collidesWith(*ghosts.at(i)))
        {
            if (ghosts.at(i)->isScared)
            {
                ghosts.at(i)->goToInitialPosition();
                ghosts.at(i)->finishScare();
                pacman->eatGhost();
            }
            else
            {
                for (Ghost *ghost : ghosts)
                {
                    ghost->goToInitialPosition();
                }
                pacman->goToInitialPosition();
                pacman->kill();
            }
        }
    }
}

void Game::moveGhosts()
{
    for (Ghost *ghost : ghosts)
    {
        ghost->makeMove();
    }
}
