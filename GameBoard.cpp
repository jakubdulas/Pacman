#include "GameBoard.h"

GameBoard::GameBoard(QWidget *parent) : QWidget(parent)
{
    imgLabel = new QLabel(this);
    QPixmap img("pacman-art/map.png");
    img = img.scaled(board_width * scale, board_height * scale);
    imgLabel->setPixmap(img);
    this->setGeometry(0, 0, board_width * scale, board_height * scale);
}
