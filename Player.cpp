#include "Player.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <Bullet.h>
#include <QDebug>

Player::Player(){
    int size=40;
    int width=800,height=600;
    this->setRect(0,0,size,size);
    this->timerSpeed=20;
    this->shootSpeed=40;
    this->setPos(width/2-size/2, height-size);
    connect(leftTimer, SIGNAL(timeout()),this, SLOT(goLeft()));
    connect(rightTimer, SIGNAL(timeout()),this, SLOT(goRight()));

}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
       this->leftTimer->start(timerSpeed);
    }
    if(event->key()==Qt::Key_Right){
       this->rightTimer->start(timerSpeed);
    }
    if(event->key()==Qt::Key_Space){
        shoot();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        this->leftTimer->stop();
    }
    if(event->key()==Qt::Key_Right){
        this->rightTimer->stop();
    }

}

void Player::goRight(){
    if(this->x()>=this->scene()->width()-40)return;
    this->setX(this->x()+10);
}

void Player::shoot(){
    Bullet *b = new Bullet();
    this->scene()->addItem(b);
    b->setPos(this->x()+20-1.5,this->y()-10);
}
void Player::goLeft(){
    if(this->x()<=0)return;
    this->setX(this->x()-10);
}



