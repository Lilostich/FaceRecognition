#ifndef MYGRAPHICVIEW_H
#define MYGRAPHICVIEW_H


#include <QGraphicsView>
#include <QWheelEvent>
#include <QDebug>
#include <QMouseEvent>

class MyGraphicView : public QGraphicsView
{
public:
    MyGraphicView(QWidget *parent = nullptr);

    void wheelEvent(QWheelEvent *event);
    void zoomSlot(bool direction);

private:
};

#endif // MYGRAPHICVIEW_H
