#pragma once
#include <QWidget>
#include <QPoint>
#include <QPixmap>
#include <QLabel>
#include <QString>
#include "constants.h"

using namespace constants;

class Point : public QWidget
{
public:
    Point(QWidget *parent, int x, int y, bool isSuper);
    void kill();
    QPoint *position;
    bool isSuper;

private:
    QLabel *imgLabel;
};