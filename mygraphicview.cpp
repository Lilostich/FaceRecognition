#include "mygraphicview.h"


MyGraphicView::MyGraphicView(QWidget *parent) : QGraphicsView(parent)
{
    setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
}

void MyGraphicView::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0)
    {
        qDebug() << "wheelEvent " << event->delta();
        zoomSlot(true);
    }
    else
    {
        qDebug() << "wheelEvent " << event->delta();
        zoomSlot(false);
    }
}

void MyGraphicView::zoomSlot(bool direction)
{
    double zoomStep = 0.01;
    if (direction)
        this->scale(1+zoomStep,1+zoomStep);
    else
        this->scale(1-zoomStep,1-zoomStep);
}
