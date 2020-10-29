#include "Player.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <Bullet.h>
#include <QDebug>
#include <Enemy.h>
#include <randomnumbergod.h>
#include <QFont>
#include <QGraphicsTextItem>
#include <QString>
#include <QGraphicsItem>
#include <QList>

Player::Player(){
    int size=40;
    int width=800,height=600;
    this->setRect(0,0,size,size);
    this->timerSpeed=20;
    this->shootSpeed=100;
    this->setPos(width/2-size/2, height-size);
    this->enemySpeed = 600;
    this->setBrush(Qt::black);
    connect(deathTimer, SIGNAL(timeout()),this, SLOT(deathSlot()));
    connect(leftTimer, SIGNAL(timeout()),this, SLOT(goLeft()));
    connect(rightTimer, SIGNAL(timeout()),this, SLOT(goRight()));
    connect(shootTimer, SIGNAL(timeout()),this, SLOT(shoot()));
    connect(enemyTimer, SIGNAL(timeout()),this, SLOT(spawnEnemy()));
    enemyTimer->start(enemySpeed);
    deathTimer->start(30);
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Space && !this->shootTimer->isActive()){
       this->shootTimer->setSingleShot(false);
       this->shootTimer->start(this->shootSpeed);
    }
    if(event->key()==Qt::Key_Left){
       this->leftTimer->start(timerSpeed);
    }
     if(event->key()==Qt::Key_Right){
       this->rightTimer->start(timerSpeed);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        this->leftTimer->stop();
    }
    if(event->key()==Qt::Key_Right){
        this->rightTimer->stop();
    }
    if(event->key()==Qt::Key_Space){
       this->shootTimer->stop();
    }
}

void Player::increseScore(){
    this->score++;
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

void Player::deathSlot(){
    QList<QGraphicsItem*> colItems = this->collidingItems();
    for(int i=0;i<colItems.size();i++){
    if(typeid(*(colItems[i]))==typeid(Enemy)){
        this->gameOver();
        }
    }
}

void Player::gameOver(){
    QGraphicsTextItem *text= new QGraphicsTextItem();
    text->setFont(QFont("times",100));
    text->setDefaultTextColor(Qt::red);
    text->setPos(60,200);
    text->setPlainText(QString("gg unlucky"));
    this->scene()->addItem(text);
    QList<QGraphicsItem*> items= this->scene()->items();
    for(int i=0;i<items.size();i++){
        if(typeid(*items[i]) == typeid(QGraphicsTextItem) || typeid(*items[i]) == typeid(Player))continue;
        this->scene()->removeItem(items[i]);
    }
    this->scene()->removeItem(this);

    delete this->leftTimer;
    delete this->rightTimer;
    delete this->shootTimer;
    delete this->enemyTimer;
    delete this->deathTimer;

}

void Player::spawnEnemy(){
    Enemy *e = new Enemy();
    this->scene()->addItem(e);
    if(e->collidingItems().size()!=0){
        do {
            e->del();
            e =new Enemy();
            this->scene()->addItem(e);
        } while (this->collidingItems().size()!=0);
    }
}

void Player::goLeft(){
    if(this->x()<=0)return;
    this->setX(this->x()-10);
}



