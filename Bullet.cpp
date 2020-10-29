#include "Bullet.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <Enemy.h>
#include <Player.h>

Bullet::Bullet(){
    this->setRect(0,0,3,10);
    this->t = new QTimer();
    connect(this->t,SIGNAL(timeout()),this,SLOT(move()));
    t->start(10);
}

void Bullet::move(){
    this->setY(this->y()-5);
    QList<QGraphicsItem*> collItems = this->collidingItems();
    for(int i=0;i<collItems.size();i++){
        if(typeid(*(collItems[i]))==typeid(Enemy)){
            this->scene()->removeItem(this);
            delete this->t;
            delete this;
            dynamic_cast<Enemy*>(collItems[i])->del();
        }

    }
    if(this->y()+10<0){
        this->scene()->removeItem(this);
        delete this->t;
        delete this;
    }
}
