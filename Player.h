#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    QTimer *leftTimer = new QTimer();
    QTimer *rightTimer = new QTimer();
    QTimer *shootTimer = new QTimer();
    int timerSpeed;
    int shootSpeed;
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public slots:
    void goLeft();
    void goRight();
    void shoot();
};

#endif // PLAYER_H
