#include "EndScreen.h"

EndScreen::EndScreen(QWidget *parent, QString str, int score) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *textLabel = new QLabel(str + " Your score: " + QString::number(score), this);
    textLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(textLabel);

    QPushButton *centeredButton = new QPushButton("Play again", this);
    centeredButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    connect(centeredButton, &QPushButton::clicked, this, &EndScreen::buttonClicked);
    layout->addWidget(centeredButton, 0, Qt::AlignCenter);

    setLayout(layout);
    this->setGeometry(0, 0, scale * board_width, scale * board_height);
}

void EndScreen::buttonClicked()
{
    emit playAgain();
}
