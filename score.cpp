#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    //ini score
    score = 0;
    //draw
    setPlainText(QString("Score: ") + QString::number(score));
    //set color of text
    setDefaultTextColor(Qt::blue);
    //set font
    setFont(QFont("arial",16));
}

void Score::increase()
{
    score ++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}
