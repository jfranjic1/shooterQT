#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
class Bullet: public QObject,public QGraphicsRectItem{
   Q_OBJECT
private:
    QTimer *t;
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
