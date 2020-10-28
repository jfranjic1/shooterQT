#include "Player.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>

Player::Player(){
    int size=40;
    int width=800,height=600;
    this->setRect(0,0,size,size);
    this->setPos(width/2-size/2, height-size);
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
    this->setX(this->x()-5);
    }
    if(event->key()==Qt::Key_Right){
    this->setX(this->x()+5);
    }
}
