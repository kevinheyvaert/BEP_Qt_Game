#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "player.h"
#include "score.h"
#include "health.h"

class Game{
public:
    void show();
    Player * player;
    Score * score;
    Health * health;

};

#endif // GAME_H
