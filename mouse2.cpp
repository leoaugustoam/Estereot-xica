#include "mouse2.h"
mouse2::mouse2(QWidget* parent) : QWidget(parent)
//mouse::mouse(QWidget* parent) : QWidget(parent)
{
    this->setMouseTracking(true);
}

void mouse2::mouseMoveEvent2(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();

    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
        if(mouse_pos.x() >= 0 && mouse_pos.y() >=0){
            emit sendMousePosition2(mouse_pos);
        }
    }
}
/*
void mouse::mousePressEvent(QMouseEvent *mouse_event)
{

    if(mouse_event->button()== Qt::LeftButton){
        QString mouse_buttonClick = "botao direito";
        emit sendMouseClick(mouse_buttonClick);
    }
}*/

mouse2::~mouse2()
{

}
