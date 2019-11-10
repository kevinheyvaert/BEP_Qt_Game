#include "game.h"
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>

void Game::show()
{
    //create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    //Create a view
    QGraphicsView * view = new QGraphicsView(scene);
    //view->setScene(scene;
    view ->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view ->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create player
    player = new Player();
    //Create score
    score = new Score();
    //Create health
    health = new Health();
    health -> setPos(health->x(), health-> y() + 30);

    //Add items to the the screne
    scene->addItem(player);
    scene->addItem(score);
    scene -> addItem(health);

    //Make item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //Set and show the view
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2, view->height() - 100); //TODO get height of player instead of hardcoded value

    //Spawn enemies TODO remove them to a separate class, for exapmle GamePlay.
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player,SLOT(spawn()));
    timer -> start(2000);
}
