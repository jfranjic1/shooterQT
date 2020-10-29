#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QTimer>
#include <QObject>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
    int x;
    QTimer *t;
public:
    Enemy();
    void del();
public slots:
    void move();
};

#endif // ENEMY_H
