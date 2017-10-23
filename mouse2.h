#ifndef MOUSE2_H
#define MOUSE2_H

#include <QObject>
#include <QWidget>
#include <QMouseEvent>

class mouse2 : public QWidget
{
    Q_OBJECT

public:
    mouse2(QWidget *parent = 0);
    ~mouse2();


protected:

    void mouseMoveEvent2(QMouseEvent *mouse_event);
   // void mousePressEvent(QMouseEvent *mouse_event);

signals:
    void sendMousePosition2(QPoint&);
   // void sendMouseClick2(QString&);


};

#endif // MOUSE2_H
