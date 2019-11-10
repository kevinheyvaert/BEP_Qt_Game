#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include "game.h"

extern Game * game;

Enemy::Enemy()
{
    //set random position of Enemy
    int random  = rand() % 750;
    setPos(random, 0);

    //set graphic of Enemy
    setPixmap(QPixmap(":/images/spaceship.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+5);
    if(pos().y()+ 50 > 600) //TODO get height of enemy
    {
        //decrease score
        game -> health -> decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() <<"Enemy deleted";
    }

    //TODO check also when enemy hits player (see bullet.cpp)
}
