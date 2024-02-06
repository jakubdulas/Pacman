#pragma once
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <constants.h>

using namespace constants;

class GameBoard : public QWidget
{
public:
    GameBoard(QWidget *parent = nullptr);

private:
    QLabel *imgLabel;
};