#include "Bullet.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>

Bullet::Bullet(){
    this->setRect(0,0,3,10);
    QTimer *t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(move()));
    t->start(10);
}

void Bullet::move(){
    this->setY(this->y()-5);
}
