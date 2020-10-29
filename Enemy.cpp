#include "Enemy.h"
#include <randomnumbergod.h>
#include <QGraphicsScene>
#include <QDebug>
Enemy::Enemy(){
    RandomNumberGod rng;
    int max=100,min=10;
    x = rng.number_int(min,max);
    int temp = rng.number_int(0, 800-x);
    this->setRect(temp,0,x,x);
    this->t = new QTimer();
    if(x<50)this->setBrush(Qt::cyan);
    else this->setBrush(Qt::red);
    connect(this->t,SIGNAL(timeout()),this,SLOT(move()));
    t->start(30);
}

void Enemy::del(){
    this->scene()->removeItem(this);
    delete this->t;
    delete this;
}

void Enemy::move(){
    this->setY(this->y()+5);
    if(this->y()>600){
       this->scene()->removeItem(this);
       delete this->t;
       delete this;
    }
}
