#include "Bullet.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>

Bullet::Bullet(){
    this->setRect(0,0,3,10);
    QTimer *t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));
    t->start(10);
}

void Bullet::move(){
    this->setY(this->y()-5);
    if(this->y()+10<0){
        this->scene()->removeItem(this);
        delete this;
    }
}
