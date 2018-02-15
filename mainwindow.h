#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include "qextserialport.h"
#include <QDebug>
#include <QMessageBox>
#include "secdialog.h"



namespace Ui
{
class MainWindow;
}

class QextSerialPort;
class QTimer;
class QextSerialEnumerator;

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;
class QMediaRecorder;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    SecDialog *secdialog;
    ~MainWindow();
    QextSerialPort *Serial;
    QextSerialEnumerator *enumerator;
    QString aux;
    QString aux2;
    BaudRateType auxbaud;

public slots:
    void showMousePosition(QPoint& pos);
    void cronometro();
    void cronometro2();
    void on_conectarButton_clicked();
    //void showMouseClick(QString &texto);

    void onReadyRead();

    void mousePressEvent(QMouseEvent *mouse_event);

    void on_capButton_clicked();

    void on_capButton2_clicked();

    void on_recButton2_clicked();

    void on_stopButton2_clicked();

    void on_bregmaBox_valueChanged(const QString &arg1);

    void on_homeButton_clicked();

    void on_ymaisButton_clicked();

    void on_peso1Button_clicked();

    void on_ymenosButton_clicked();

    void on_xmaisButton_clicked();

    void on_xmenosButton_clicked();

    void on_setButton_clicked();

    void on_peso2Button_clicked();

    void on_peso3Button_clicked();

    void on_zmaisButton_clicked();

    void on_zmenosButton_clicked();

    void on_zerarx_clicked();

    void on_peso0Button_clicked();

    void on_settempButton_clicked();


    void on_x1Browser2_textChanged();


    void on_drillButton_clicked();

    void on_syringeButton_clicked();

    void on_presetbutton_clicked();

    void on_eletrobutton_clicked();



    void on_refresh_clicked();

    void on_desconectarButton_clicked();

    void on_offtemp_clicked();

    void on_sendButton_clicked();

    void on_ocultarButton_clicked();

    void on_clearbutton_clicked();

    void on_outrosButton_clicked();

    void on_stopButton_clicked();

    void on_factorBox_valueChanged(double arg1);

    void on_setseri_clicked();

    void on_menoseri_clicked();

    void on_quad_clicked();


    void on_marcadorcam1_triggered();

    void on_marcadorcam2_triggered();

    void on_tirarfoto2_triggered();

    void on_incluiricon_triggered();

    void on_acassistencia_triggered();

    void on_actionprompot_triggered();

    void on_actionConectar_triggered();

    void on_actionrefresh_triggered();

    void on_acmanual_triggered();

    void on_actiondesenhos_pre_definidos_triggered();

    void on_tabWidget_tabBarClicked(int index);

    void on_circleButton_clicked();

    void on_quadButton_clicked();

    void on_actionTools_triggered();

    void on_z1Browser2_objectNameChanged(const QString &objectName);

    void on_bregmaBox_valueChanged(double arg1);


    void on_pushButton_clicked();

    void on_setserimin_clicked();

    void on_timeon_clicked();

    void on_timereset_clicked();


    void on_stopButton_2_clicked();

    void on_actionChange_camera_triggered();

    void on_actionChange_camera_2_triggered();


    void on_speedbox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

    void mudarnomez();
    void on_maisseringa_clicked();

    void on_menoseringa_clicked();

    void on_zerarse_clicked();

    void on_encherseringa_clicked();

    void on_injetarseringa_clicked();

    void on_zerarseringa_clicked();

signals:
   // void sendMousePosition(QPoint&);
    void sendMouseClick(QString&);

public:
    Ui::MainWindow *ui;
    QCamera *mCamera;
    QCameraViewfinder *mCameraViewfinder;
    QCameraImageCapture *mCameraImageCapture;
    QCamera *m3Camera;
    QCameraViewfinder *m3CameraViewfinder;
    QCameraImageCapture *m3CameraImageCapture;
    QCameraImageCapture *m2CameraImageCapture;
    QVBoxLayout *mLayout;
    QMenu *mOpcionesMenu;
    QAction *mEncenderAction;
    QAction *mApagarAction;
    QAction *mCapturarAction;
    QCamera *m2Camera;
    QCameraViewfinder *m2CameraViewfinder;
    QVBoxLayout *m2Layout;
    QVBoxLayout *m3Layout;
    QMediaRecorder  *recorder;

    QTimer *timer;

protected:

    void paintEvent(QPaintEvent *e);


};

#endif // MAINWINDOW_H
