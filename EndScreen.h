#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <string>
#include "constants.h"

using namespace constants;
using namespace std;

class EndScreen : public QWidget
{
    Q_OBJECT
public:
    EndScreen(QWidget *parent = nullptr, QString str = QString(""), int score = 0);

private slots:
    void buttonClicked();

signals:
    void playAgain();

private:
    QVBoxLayout *layout;
    QPushButton *showMessageButton;
    QPushButton *playAgainButton;
};