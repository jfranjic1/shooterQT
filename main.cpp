#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Player.h>
#include<QGraphicsItem>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView * v = new QGraphicsView();
    QGraphicsScene * s = new QGraphicsScene();
    v->setScene(s);
    v->setFixedSize(810,610);
    s->setSceneRect(0,0,800,600);
    Player *p= new Player();
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    s->addItem(p);
    v->show();
    return a.exec();
}
