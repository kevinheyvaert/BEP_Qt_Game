#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem * parent): QGraphicsTextItem(parent)
{
    health = 3;
    setPlainText(QString("Lives: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("arial",16));
}

void Health::increase()
{
    health ++;
    setPlainText(QString("Lives: ") + QString::number(health));
}

void Health::decrease()
{
    health --;
    setPlainText(QString("Lives: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
