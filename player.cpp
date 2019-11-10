#include "player.h"
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/plane.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Player knows that you pressed a key";
    if(event->key() == Qt::Key_Left)
    {
       if(pos().x() > 0)
        setPos(x() -10, y ());
    }
    else if (event->key() == Qt::Key_Right)
    {
       if(pos().x() + 100 < 800) //TODO width Player and screen are here hardcoded, should be the width of object
        setPos(x() +10, y ());
    }
//    else if(event->key() == Qt::Key_Up)
//    {
//       setPos(x(), y() - 10);
//    }
//    if(event->key() == Qt::Key_Down)
//    {
//       setPos(x(), y () + 10);
//    }
    else if (event ->key() == Qt::Key_Space)
    {
        //create bullet
        Bullet * bullet = new Bullet();
        bullet -> setPos(x() + 14,y());
        qDebug() << "Bullet created";
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    //create enemy TODO move to other class
    Enemy * enemy = new Enemy();
    scene() -> addItem(enemy);
}
