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
    if(x<10)this->setBrush(Qt::cyan);
    if(x>=10&&x<=20)this->setBrush(Qt::white);
    if(x>20&&x<=30)this->setBrush(Qt::darkRed);
    if(x>30&&x<=40)this->setBrush(Qt::magenta);
    if(x>40&&x<=50)this->setBrush(Qt::yellow);
    if(x>50&&x<=60)this->setBrush(Qt::gray);
    if(x>60&&x<=70)this->setBrush(Qt::green);
    if(x>70&&x<=80)this->setBrush(Qt::blue);
    if(x>80) this->setBrush(Qt::red);
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
