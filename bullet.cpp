#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    //draw bullet
    setPixmap(QPixmap(":/images/rocket.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //check if bullet collides with enemy
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            //increase score
            game->score->increase();

            scene() -> removeItem(colliding_items[i]);
            scene() -> removeItem(this);

            //delete objects in heap
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move bullet up
    setPos(x(), y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Bullet deleted";
    }
}
