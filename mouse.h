#ifndef MOUSE_H
#define MOUSE_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
class mouse : public QLabel
//class mouse : public QWidget
{

    Q_OBJECT


public:
    mouse(QWidget *parent = 0);
    ~mouse();


protected:

    void mouseMoveEvent(QMouseEvent *mouse_event);
   // void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition(QPoint&);
    //void sendMouseClick(QString&);


};

#endif // MOUSE_H
