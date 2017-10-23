#include "mouse.h"

mouse::mouse(QWidget* parent) : QLabel(parent)
//mouse::mouse(QWidget* parent) : QWidget(parent)
{
    this->setMouseTracking(true);
}

void mouse::mouseMoveEvent(QMouseEvent *mouse_event)
{
    QPoint mouse_pos = mouse_event->pos();

    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
        if(mouse_pos.x() >= 18 && mouse_pos.y() >=22 && mouse_pos.x() <= 698 && mouse_pos.y() <= 424 ){
            emit sendMousePosition(mouse_pos);
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

mouse::~mouse()
{

}
