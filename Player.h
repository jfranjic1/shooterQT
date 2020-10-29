#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    QTimer *leftTimer = new QTimer();
    QTimer *rightTimer = new QTimer();
    QTimer *shootTimer = new QTimer();
    QTimer *enemyTimer = new QTimer();
    QTimer *deathTimer = new QTimer();

    int timerSpeed;
    int enemySpeed;
    int score=0;
    int shootSpeed;
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    void gameOver();
    void keyReleaseEvent(QKeyEvent *event);
    void increseScore();
public slots:
    void goLeft();
    void goRight();
    void shoot();
    void deathSlot();
    void spawnEnemy();
};

#endif // PLAYER_H
