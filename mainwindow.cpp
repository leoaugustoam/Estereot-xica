#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QList>
#include <QCameraInfo>
#include <QMediaRecorder>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QMouseEvent>
#include "mouse.h"
#include "qextserialenumerator.h"
#include "secdialog.h"
#include <QTime>
#include <QTimer>

QString vvv;
float compyser=18.94;
float compxser=0.0;
int flagtr;
int auxdisable;
int andamentoprocesso;
float tempototalseringa;
float tempocorridoseringa;
float mincorridoseringa;
float tempodisable;
float tempodisableatual;
int auxtime2;
int auxcliqueseringa;
float atualseringa;
int auxgoto;
int auxselserin;
int flagselserin;
QString qpeso;
int auxdrill;
int auxserin;
int auxoutros;
int posfinal;
QString vz2;
int mudenomez;
int entrada;
int flaganterior;
int qtrocar;
int qtrocar2;
int imin;
int auxcam2;
float auxdes;
float auxdes2;
float velseringa;
float auxtempos;
int auxtempo;
float auxbre;
int flagzferra;
float zferramenta;
int marcadorpromp;
int marcadoricon;
int marcador1;
int marcador2;
int flagbregma;
int ferramenta;
QString f;
int i;
float temp;
bool clicked = false;
QString j;
float valorx;
float valory;
float valorz;
float peso;
double xmm;
double ymm;
double zmm;
double xfator;
double yfator;
double zfator;
double fator;
QString Qpeso;
int flagCam;
int flagdrill;
int flageletrodo;
int flagsyringe;
int flagconectar;
int flagoutros;
float offsetdrill;
float offsetseringa;
float offseteletrodo;
float offsetoutros;
QString pox;//posiçao do mouse
QString poy;
QString poz;
QString pzmm;
QString pxmm;//posiçao do mouse em mm
QString pymm;
QString pzmmfator;
QString pxmmfator;//posiçao do mouse em mm com fator
QString pymmfator;
QString poxn;//posição do mouse centrado em 0,0 da imagem
QString poyn;
QString pozn;
QString poxf;//variaveis referentes ao x e y no bloco quando é clicado com o botao, esperando para ser setado
QString poyf;
QString pozf;
QString aux;
QString vx;
QString vy;
QString vz;
QString linha;
QString print;
QString labelconectado;
QByteArray linha2;
QString linharec;
QString linharecaux;
QByteArray lrec;
int flagrec;

int flagrec2;



QByteArray linha3;
QPoint posponto;
QByteArray msgSerial;
QByteArray valorRecebido = "";
QByteArray msgteste;
QByteArray linhat1;
QString linhat3;
QByteArray linhat2;
QString auxraio;
QString offtools;
int flaglinha;
int tamanholinha;
int flagok;
int flagok2;
float auxseringa;
float xg54;
float yg54;
float zg54;
int auxcam;
float raio;
int ttt;
int seg;
int hora;
int min;
QString tttempo;
QString tseg;
QString thora;
QString tmin;
int auxtime;

int flagn1;
int flagn2;
int flagn3;

QString nome1;
QString nome2;
QString nome3;
QString msglabel;
QString msgvel;
QString msgvelmaq;
QString offd;
QString offe;
QString offs;
QString offo;
//
QString fac;
QString velomaq;
int velmaq;
QString desenho;
QString desenho2;
QString labelbrowxyz;


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{



tempodisable =0;
tempodisableatual=0;
  auxcliqueseringa = 0;
  auxgoto = 0;
  flagselserin = 0;
  auxselserin = 0;
  qtrocar = 4;
  qtrocar2 = 5;
  auxcam = 0;
  auxcam2 = 0;
  ui->setupUi(this);
  flagbregma = 0;
  posfinal = 0;
  flagzferra = 0;
  zferramenta = 0;
mincorridoseringa=0;
  marcador1 = 0;
  marcador2 = 0;
  marcadoricon = 0;
  marcadorpromp = 0;
  xg54 = 0;
  yg54 = 0;
  zg54 = 0;
  auxdrill = 0;
  auxserin = 0;
  auxoutros = 0;
  atualseringa = 0;
  flagrec = 0;
  flagrec2 = 0;
auxtime2=0;
auxdisable=0;
tempototalseringa=0;
tempocorridoseringa=0;
andamentoprocesso=0;
flagtr=0;
  linharec = "";
  ui->speedbox->addItem("100");
  ui->speedbox->addItem("200");
  ui->speedbox->addItem("300");
  ui->speedbox->addItem("400");
  ui->speedbox->addItem("500");
  ui->speedbox->addItem("600");
  ui->speedbox->setCurrentIndex(2);

  ui->xcomp->appendPlainText(QString::number(compxser));
  ui->ycomp->appendPlainText(QString::number(compyser));

  raio = 0;
  ui->seribox->setEnabled(false);
  ui->passoseringa->setEnabled(true);
  ui->seriboxmin->setEnabled(false);
  ui->setseri->setEnabled(false);
  ui->seribar->setEnabled(false);
  ui->seribar->setValue(0);
  ui->seribar->setMinimum(0);
  ui->seribar->setMaximum(100);


  ui->passoseringa->setSuffix("uL");
  ui->seribox->setSuffix("uL");
  ui->seriboxmin->setSuffix("Min");
  ui->desenhobox->setSuffix("mm");
  ui->desenhobox2->setSuffix("mm");
  ui->lab2->setText("Side 2");
  ui->lab1->setText("Side 1");

  ui->desenhobox->setMaximum(10);
  ui->desenhobox->setMinimum(0);
  ui->desenhobox->setValue(1);
  ui->desenhobox->setDecimals(2);
  ui->desenhobox->setSingleStep(0.1);

  ui->desenhobox2->setMaximum(10);
  ui->desenhobox2->setMinimum(0);
  ui->desenhobox2->setValue(1);
  ui->desenhobox2->setDecimals(2);
  ui->desenhobox2->setSingleStep(0.1);




  //***********************************************************************************************************************************//

  //ui->eletrobutton->setStyleSheet("color: rgb(255, 0, 0);");
  flaganterior = 0;

  QTimer *time = new QTimer(this);
  connect(time, SIGNAL(timeout()), this, SLOT(cronometro()));
  connect(time, SIGNAL(timeout()), this, SLOT(cronometro2()));
  time->start(1000);
  auxtime = 0;
  ttt = 0;
  hora = 0;
  min = 0;
  seg = 0;
  tttempo = "00:00:00";
  ui->crono->setText(tttempo);

  entrada = 0;
  mudenomez = 0;


  auxbre = 0;

  ui->frame->setVisible(false);
  ui->frame_2->setVisible(false);

  // ui->ocultarButton->setStyleSheet("background-color: transparent;");

  qDebug() << "Portas disponiveis: " << QextSerialEnumerator::getPorts().length(); //DEPOIS REPETIR ESTE CODIGO NA PARTE DO REFRESH
  foreach (const QextPortInfo info, QextSerialEnumerator::getPorts()) {
    j = info.portName;
    ui->port->addItem(info.portName);
    qDebug() << "ID: " << j;
    qDebug() << "ID: " << info.productID;
  }

  //VERIFICAR CODIGO DO QTARD E INCLUIR A PARTE DO PORTBOX
  ui->port->setEditable(true);

  ferramenta = 4;




  ui->speedbox->setCurrentIndex(2);
  f = " F300\n";







  flagdrill = 0;
  flageletrodo = 1;
  flagsyringe = 0;
  flagconectar = 0;
  flagoutros = 0;


  offsetdrill = 0.0;
  offsetseringa = 0.0;
  offseteletrodo = 0.0;
  offsetoutros = 0.0;


  msglabel = "dril: ";
  offd = QString::number(offsetdrill);
  msglabel.append(offd);
  msglabel.append("\nSeringa:");
  offs = QString::number(offsetseringa);
  msglabel.append(offs);
  msglabel.append("\nEletrodo:");
  offe = QString::number(offseteletrodo);
  msglabel.append(offe);
  msglabel.append("\nOutros:");
  offo = QString::number(offsetoutros);
  msglabel.append(offo);
  msglabel.append("\n");
  //ui->label->setText(msglabel);


  setWindowTitle(tr("VOID3D - ESTEREOTÁXICA V2.7"));
  timer = new QTimer(this);
  timer->setInterval(40);
  aux = ui->port->currentText();





  connect(timer, SIGNAL(timeout()), SLOT(onReadyRead()));



  ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");


  ui->recvEdit->setStyleSheet("color: transparent;");
  ui->recvEdit->setEnabled(false);
  ui->sendEdit->setStyleSheet("color: transparent;");
  ui->sendEdit->setEnabled(false);
  ui->clearbutton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
  ui->clearbutton->setEnabled(false);
  ui->sendButton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
  ui->sendButton->setEnabled(false);


  i = 5;
  imin=i;
  valorx = 0;
  valory = 0;
  valorz = 0;

  peso = 0.1;
  Qpeso = QString::number(peso);
  ui->pesoxyBrowser->setText(Qpeso);
  ui->pesozBrowser->setText(Qpeso);

  poxf = QString::number(0);
  poyf = QString::number(0);

  vx = QString::number(valorx, 'f', 2);
  vy = QString::number(valory, 'f', 2);
  vz = QString::number(valorz, 'f', 2);

  ui->xBrowser->setText(vx);
  ui->yBrowser->setText(vy);
  ui->zBrowser->setText(vz);


  ui->labelbrow->setText(labelbrowxyz);


  flagCam = 0;

  qDebug() << "aqui ";
  QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
  foreach (const QCameraInfo &cameraInfo, cameras) {
    qDebug() << "NOME CAMERAS " << cameraInfo.deviceName();

    imin = i;
    nome1 = cameraInfo.deviceName();
    qDebug() << "string camera " << nome1 << " i: " << i;
    if (i == 5) {
      nome1 = cameraInfo.deviceName();
      mCamera = new QCamera(cameraInfo);
    }
    if (i == 4) {
      nome2 = cameraInfo.deviceName();
      m2Camera = new QCamera(cameraInfo);
    }
    if (i == 3) {
      nome3 = cameraInfo.deviceName();
      m3Camera = new QCamera(cameraInfo);
    }

    i--;
    flagCam++;
  }

  //qDebug() << "I MINIMO - inicio  " << imin;
  qDebug() << "flagcam  " << flagCam;
  /*if (flagCam == 1) {
  }*/
  /*if(flagCam==1){
      mCamera = new QCamera;
  }
  if(flagCam==2){
      mCamera = new QCamera;
      m2Camera = new QCamera;
  }
  if(flagCam==3){
      mCamera = new QCamera;
      m2Camera = new QCamera;
      m3Camera = new QCamera;
  }*/
  connect(ui->fundo_imagem, SIGNAL(sendMousePosition(QPoint&)), this, SLOT(showMousePosition(QPoint&)));

  ui->factorBox->setMaximum(5);
  ui->factorBox->setMinimum(0);
  ui->factorBox->setValue(1);
  ui->factorBox->setDecimals(2);
  ui->factorBox->setSingleStep(0.1);
  fac = QString::number(ui->factorBox->value());
  fator = ui->factorBox->value();






  ui->seribar->setValue(0);
  ui->seribar->setEnabled(false);
  ui->seribar->setMinimum(0);
  ui->seribox->setMinimum(0.1);
  ui->seribox->setMaximum(10);
  ui->seribox->setDecimals(2);
  ui->seribox->setValue(0.1);
  ui->seribox->setSingleStep(0.1);
  ui->passoseringa->setMinimum(0.1);
  ui->passoseringa->setMaximum(1);
  ui->passoseringa->setValue(0.1);
  ui->passoseringa->setDecimals(2);
  ui->passoseringa->setSingleStep(0.1);
  ui->seriboxmin->setValue(1);
  ui->seriboxmin->setMinimum(1);
  ui->seriboxmin->setMaximum(900);


  ui->seribar->setMaximum(100);


  ui->bregmaBox->setMaximum(4.28);
  ui->bregmaBox->setMinimum(-8.24);
  ui->bregmaBox->setValue(0.02);
  ui->bregmaBox->setDecimals(2);
  ui->bregmaBox->setSingleStep(0.1);


  ui->x1Browser2->setPlainText("0");
  ui->z1Browser2->setPlainText("0");



  ui->fundo_imagem->setStyleSheet("background-color: rgba(255, 255, 0, 0);");
  ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura31.jpg);");
  //ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/stop.jpg);");
  //ui->pushButton->setStyleSheet("background-color: rgba(255, 255, 255, 255);");


  if(flagCam==1){
      mCameraViewfinder = new QCameraViewfinder;
      mCameraImageCapture = new QCameraImageCapture(mCamera, this);
      mLayout = new QVBoxLayout;
      mCamera->setViewfinder(mCameraViewfinder);
      mLayout -> addWidget(mCameraViewfinder);
      mLayout->setMargin(0);
      ui->scrollArea->setLayout(mLayout);
      mCamera->start();

  }
  if(flagCam==2){
      mCameraViewfinder = new QCameraViewfinder;
      mCameraImageCapture = new QCameraImageCapture(mCamera, this);
      mLayout = new QVBoxLayout;
      mCamera->setViewfinder(mCameraViewfinder);
      mLayout -> addWidget(mCameraViewfinder);
      mLayout->setMargin(0);
      ui->scrollArea->setLayout(mLayout);
      mCamera->start();

      m2CameraViewfinder = new QCameraViewfinder;
      m2CameraImageCapture = new QCameraImageCapture(m2Camera, this);
      m2Layout = new QVBoxLayout;
      m2Camera->setViewfinder(m2CameraViewfinder);
      m2Layout -> addWidget(m2CameraViewfinder);
      m2Layout->setMargin(0);
      ui->scrollArea2->setLayout(m2Layout);
      m2Camera->start();
  }

  if(flagCam==3){
      mCameraViewfinder = new QCameraViewfinder;
      mCameraImageCapture = new QCameraImageCapture(mCamera, this);
      mLayout = new QVBoxLayout;
      mCamera->setViewfinder(mCameraViewfinder);
      mLayout -> addWidget(mCameraViewfinder);
      mLayout->setMargin(0);
      ui->scrollArea->setLayout(mLayout);
      mCamera->start();
      m2CameraViewfinder = new QCameraViewfinder;
      m2CameraImageCapture = new QCameraImageCapture(m2Camera, this);
      m2Layout = new QVBoxLayout;
      m2Camera->setViewfinder(m2CameraViewfinder);
      m2Layout -> addWidget(m2CameraViewfinder);
      m2Layout->setMargin(0);
      ui->scrollArea2->setLayout(m2Layout);
      m2Camera->start();
      m3CameraViewfinder = new QCameraViewfinder;
      m3CameraImageCapture = new QCameraImageCapture(m3Camera, this);
      m3Layout = new QVBoxLayout;
      m3Camera->setViewfinder(m3CameraViewfinder);
      m3Layout -> addWidget(m3CameraViewfinder);
      m3Layout->setMargin(0);
      m3Camera->start();
  }


  flagn3=0;
  flagn1=2;
  flagn2=1;


}




MainWindow::~MainWindow()
{
  delete ui;
  if (flagconectar == 1) {
    delete Serial;
  }


  delete enumerator;
  delete mCamera;
  delete mCameraViewfinder;
  delete mCameraImageCapture;
  delete m2CameraImageCapture;
  delete m3CameraImageCapture;
  delete mLayout;
  delete mOpcionesMenu;
  delete mEncenderAction;
  delete mApagarAction;
  delete mCapturarAction;
  delete m2Camera;
  delete m2CameraViewfinder;
  delete m3Camera;
  delete m3CameraViewfinder;
  delete m2Layout;
  delete recorder;

  delete timer;
}

void MainWindow::cronometro2()
{
    if(auxtime2==0){
        //qDebug()<<"n entrou "<<endl;
        if(auxdisable==1){
            tempodisableatual+=1;
            if(tempodisableatual >= tempodisable){
                auxdisable=0;
                tempodisableatual=0;
                tempodisable=0;
                ui->maisseringa->setEnabled(true);
                ui->menoseringa->setEnabled(true);
            }
        }
    }
    if(auxtime2==1){
        tempocorridoseringa+=1;
        mincorridoseringa=tempocorridoseringa/60;
        //qDebug()<<"SEGUNDOS CORRIDOS: "<<tempocorridoseringa<<"s, de um total de "<<tempototalseringa<<endl;
        qDebug()<<tempocorridoseringa<<"s, de "<<tempototalseringa<<". "<<tempocorridoseringa/tempototalseringa<<endl;
        ui->seribar->setValue((tempocorridoseringa/tempototalseringa)*100);

        ui->zerarx->setEnabled(false);
        ui->ymaisButton->setEnabled(false);
        ui->ymenosButton->setEnabled(false);
        ui->xmaisButton->setEnabled(false);
        ui->xmenosButton->setEnabled(false);
        ui->zmaisButton->setEnabled(false);
        ui->zmenosButton->setEnabled(false);
        ui->presetbutton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->drillButton->setEnabled(false);
        ui->eletrobutton->setEnabled(false);
        ui->outrosButton->setEnabled(false);
        ui->syringeButton->setEnabled(false);
        ui->quad->setEnabled(false);
        ui->homeButton->setEnabled(false);
        ui->setButton->setEnabled(false);


        if(tempocorridoseringa == tempototalseringa){
            auxtime2=0;
            tempototalseringa=0;
            mincorridoseringa=0;
            tempocorridoseringa=0;
            andamentoprocesso=0;

            ui->zerarx->setEnabled(true);
            ui->ymaisButton->setEnabled(true);
            ui->ymenosButton->setEnabled(true);
            ui->xmaisButton->setEnabled(true);
            ui->xmenosButton->setEnabled(true);
            ui->zmaisButton->setEnabled(true);
            ui->zmenosButton->setEnabled(true);
            ui->presetbutton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->drillButton->setEnabled(true);
            ui->eletrobutton->setEnabled(true);
            ui->outrosButton->setEnabled(true);
            ui->syringeButton->setEnabled(true);
            ui->quad->setEnabled(true);
            ui->homeButton->setEnabled(true);
            ui->setButton->setEnabled(true);
        }
    }

}

void MainWindow::cronometro()
{
  if (auxtime == 1) {
    ttt += 1;


    hora = (ttt / 3600);
    min = (ttt - (3600 * hora)) / 60;
    seg = (ttt - (3600 * hora) - (min * 60));

    tseg = QString::number(seg);
    thora = QString::number(hora);
    tmin = QString::number(min);

    tttempo = "";
    if (hora < 10) {
      tttempo.append("0");
      tttempo.append(thora);
    }
    else {
      tttempo.append(thora);
    }
    tttempo.append(":");
    if (min < 10) {
      tttempo.append("0");
      tttempo.append(tmin);
    }
    else {
      tttempo.append(tmin);
    }
    tttempo.append(":");
    if (seg < 10) {
      tttempo.append("0");
      tttempo.append(tseg);
    }
    else {
      tttempo.append(tseg);
    }


    ui->crono->setText(tttempo);
    qDebug() << tttempo;
  }
  if (auxtime == 2) {
    ui->crono->setText("00:00:00");
    ttt = 0;
  }
}


void MainWindow::onReadyRead()
{

  if (Serial->bytesAvailable()) {
    ui->recvEdit->moveCursor(QTextCursor::End);
    //linha = QString::fromLatin1(Serial->readAll());
    linha = QString::fromUtf8(Serial->readAll()); //ler ate /n <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    ui->recvEdit->insertPlainText("RECEBIDO: ");
    ui->recvEdit->insertPlainText(linha);
    //ui->recvEdit->insertPlainText("\n");
    qDebug() << "LINHA RECEBIDA::::::" << linha;
    linha2 = "";
    linha2.append(linha);
    //[PRB:110.003,0.000,-10.738:1]

    if ((linha2[0] == '['  && flagrec != 3) || flagrec == 2 ) {
      linharecaux.append(linha2);
      if (linharecaux[0] == '[' && linharecaux[1] == 'P') {
        linharec.append(linharecaux);
        flagrec = 1;

        //qDebug() << "Leu [";
      }
      if (flagrec == 1 && linharecaux[0] == '[' && linharecaux[1] == 'P' && linharecaux[2] == 'R' && linharecaux[3] == 'B') {
        linharec.append(linha2);
        flagrec = 2;
        //qDebug() << "Leu [PRB";
      }
      else {
        linharecaux = "";
      }
      for (int i = 0; i != linharec.length(); i++ ) {
        if (linharec[i] == ']') {
          flagrec = 3;
        }
      }
    }
  }

  if (flagrec == 3) {
    valorRecebido = "";
    for (int i = 0; i != linharec.length() && flagrec2 == 0 ; i++) {
      if (linharec[i] == '[') {
        posfinal = i;
        qDebug() << "posiçao do '[' :" << posfinal;
      }
      if (linharec[i + 28] == ']' && linharec[i] == '[' ) {
        flagrec2 = 1;
      }
    }
    lrec = linharec.toUtf8();
    if(ui->syringeButton->isChecked()){
    for (int ii = posfinal + 20; ii != (posfinal + 27); ii++) {
      valorRecebido[ii - posfinal - 20] = lrec[ii];
    }
    }
    if(ui->syringeButton->isChecked()==false){
    for (int ii = posfinal + 21; ii != (posfinal + 27); ii++) {
      valorRecebido[ii - posfinal - 21] = lrec[ii];
    }
    }
    qDebug() << "VALOR RECEBIDO NA SERIAL DEPOIS DE EXCLUIR OS caracteres: " << valorRecebido;
    vvv = valorRecebido;
    qDebug() << "VVV" << vvv;
    vvv.replace(":","");
    qDebug() << "VVV sem :" << vvv;

    temp = vvv.toFloat();
    qDebug() << "               VALOR RECEBIDO" << temp;


    //print = QString::number(temp);
    //ui->tempBrowser->setText(print);

    if (ui->drillButton->isChecked() && flagdrill == 1) {



      flagdrill = 0;
      flaganterior = 1;
      offsetdrill = temp;
      offd = QString::number(offsetdrill , 'f', 2);

      qDebug() << "               offsetdrill" << offd;
      ui->offdri->setText(offd);
      ui->pushButton_2->setEnabled(true);



      if (auxdrill == 0) {

        qDebug() << "                                             auxdrill VALOR Z:" << valorz;
        valorz = 0 - zg54 - (offsetdrill - offseteletrodo);
        qDebug() << "                                             auxdrill VALOR Z:" << valorz;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
        auxdrill = 1;
        flagselserin = 0;
        auxselserin = 0;
      }


    }
    if (ui->syringeButton->isChecked() && flagsyringe == 1) {
      flagsyringe = 0;
      flaganterior = 2;
      offsetseringa = temp;
      offs = QString::number(offsetseringa , 'f', 2);
      ui->offsy->setText(offs);


      /*if (flagselserin == 2 && auxselserin == 0) { //entrada pela primeira vez

        qDebug() << "COMPENSOU NA SERINGA";
        msgteste = "G55 G91 G1 Y";
        qpeso = "";
        qpeso = QString::number(-compyser);
        msgteste.append(qpeso);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        msgteste = "G90";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        flagselserin = 1;
        auxselserin = 1;
      }

      if (auxserin == 0) {*/

        qDebug() << "                                             auxserin VALOR Z:" << valorz;
        valorz = 0 - zg54 - (offsetseringa - offseteletrodo);
        qDebug() << "                                             auxserin VALOR Z:" << valorz;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
        flagselserin = 1;
        auxselserin = 1;
        auxserin = 1;
      //}



    }

    if (ui->outrosButton->isChecked() && flagoutros == 1) {
      flagoutros = 0;
      flaganterior = 3;
      offsetoutros = temp;
      offo = QString::number(offsetoutros , 'f', 2);
      ui->offothers->setText(offo);



      if (auxoutros == 0) {

        qDebug() << "                                             auxoutros VALOR Z:" << valorz;
        valorz = 0 - zg54 - (offsetoutros - offseteletrodo);
        qDebug() << "                                             auxoutros VALOR Z:" << valorz;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
        auxoutros = 1;
      }


    }

    if (ui->eletrobutton->isChecked() && flageletrodo == 1) {
      ui->zerarx->setEnabled(true);
      flageletrodo = 0;
      flaganterior = 3;
      offseteletrodo = temp;
      offe = QString::number(offseteletrodo , 'f', 2);
      ui->offprobe->setText(offe);
    }





    linharec = "";
    linharecaux = "";
    flagrec = 0;
    flagrec2 = 0;
  }

}

void MainWindow::showMousePosition(QPoint &pos)
{
  pox = QString::number(pos.x());
  poy = QString::number(pos.y());
  posponto = pos;

  poxn = QString::number(pos.x() - 18 - 698);
  poyn = QString::number(pos.y() - 22 - 424);

  xmm = ((pos.x()  - 358) * 0.01470) ;

  //ymm = ((pos.y()  - 398) * 0.01470) ; //mudança do plano de Y
  ymm = ((pos.y()  - 3) * 0.01470) ;

  pxmm = QString::number(xmm, 'f', 2);

  pymm = QString::number(ymm, 'f', 2);

  pzmm = pymm;
  ui->label_pos->setText("X=" + pxmm + ", Z=" + pymm); //POSIÇÃO DO MOUSE ORIGINAL

  //ui->mouseok->setText("X=" + pox + ", Y=" + poy); //POSIÇÃO DO MOUSE ZERADA SO DENTRO DA IMAGEM
  //ui->mousemmok->setText("Xmm=" + pxmm + ", Ymm=" + pymm);
}

void MainWindow::mousePressEvent(QMouseEvent *mouse_event)
{
  if (mouse_event->button() == Qt::LeftButton) {
    //ui->labelMouseClick->setText("botao direito, X: " + pox + " Y: " + poy );

  }
  if (mouse_event->button() == Qt::RightButton) {
    //ui->labelMouseClick->setText("botao esquerdo");
    //poxf=pox;
    //poyf=poy;
    poxf = pxmm;
    poyf = pymm;
    ui->x1Browser2->setPlainText(pxmm);
    ui->z1Browser2->setPlainText(pzmm);
    clicked = true;
    this->update();
  }
}


void MainWindow::on_setButton_clicked()
{
  qDebug() << "AUXGOTO: " << auxgoto;
  xfator = poxf.toFloat() * fator;
  pxmmfator = QString::number(xfator, 'f', 2);

  zfator = poyf.toFloat() * fator;
  pzmmfator = QString::number(zfator, 'f', 2);

  yfator = ui->bregmaBox->value() * fator;
  pymmfator = QString::number(yfator, 'f', 2);


  ui->xBrowser->setText(pxmmfator);
  ui->yBrowser->setText(pymmfator);


  //ui->zBrowser->setText("0");
  //valorz = pzmmfator.toFloat();
  valorx = pxmmfator.toFloat();
  valory = pymmfator.toFloat();



  /*if (ui->outrosButton->isChecked() || ui->drillButton->isChecked()) {
    // ui->zBrowser->setText("0");
    //valorz = 0;
    ui->zBrowser->setStyleSheet("color: rgb(0, 0, 0);");
    zferramenta = pzmmfator.toFloat();
    flagzferra = 1;

    }*/

  if (flagconectar == 1) {
    if (Serial->isOpen()) {



      if ((ui->outrosButton->isChecked() || ui->drillButton->isChecked() || ui->eletrobutton->isChecked())) {
        qDebug() << "                                           outros goto 0 - seringa n selecionada";
        msgteste = "G55 G1 X";
        msgteste.append(pxmmfator);
        msgteste.append(" Y");
        pymmfator = QString::number(yfator, 'f', 2);
        msgteste.append(pymmfator);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }
      if (ui->syringeButton->isChecked()) {
        qDebug() << "                                           seringa goto 1";
        msgteste = "G55 G1 X";
        pxmmfator = QString::number(xfator + compxser, 'f', 2);
        msgteste.append(pxmmfator);
        msgteste.append(" Y");
        pymmfator = QString::number(yfator + compyser, 'f', 2);
        msgteste.append(pymmfator);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }


      /*msgteste = "G55 G1 X";
        msgteste.append(pxmmfator);
        msgteste.append(" Y");
        msgteste.append(pymmfator);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;*/
    }
  }

}

void MainWindow::on_capButton_clicked()
{
    qDebug() << "fotos- FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;

  auto filename = QFileDialog::getSaveFileName(this, "Capturar", "/", "Imagem (*.jpg;*.jpeg)");
  if (filename.isEmpty()) {
    return;
  }

  if(flagn1==2){
      mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
      mCamera->setCaptureMode(QCamera::CaptureStillImage);
      mCamera->start();
      mCamera->searchAndLock();
      mCameraImageCapture->capture(filename);
      mCamera->unlock();
      qDebug() << "FLAGN1";
  }
  if(flagn2==2){
      m2CameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      m2CameraImageCapture->setEncodingSettings(imageEncoderSettings);
      m2Camera->setCaptureMode(QCamera::CaptureStillImage);
      m2Camera->start();
      m2Camera->searchAndLock();
      m2CameraImageCapture->capture(filename);
      m2Camera->unlock();
      qDebug() << "FLAGN2";
  }
  if(flagn3==2){
      m3CameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      m3CameraImageCapture->setEncodingSettings(imageEncoderSettings);
      m3Camera->setCaptureMode(QCamera::CaptureStillImage);
      m3Camera->start();
      m3Camera->searchAndLock();
      m3CameraImageCapture->capture(filename);
      m3Camera->unlock();
      qDebug() << "FLAGN3";
  }
}

void MainWindow::on_capButton2_clicked()
{

    qDebug() << "fotos- FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;

  auto filename = QFileDialog::getSaveFileName(this, "Capturar", "/", "Imagem (*.jpg;*.jpeg)");
  if (filename.isEmpty()) {
    return;
  }
  if(flagn1==1){
      mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
      mCamera->setCaptureMode(QCamera::CaptureStillImage);
      mCamera->start();
      mCamera->searchAndLock();
      mCameraImageCapture->capture(filename);
      mCamera->unlock();
      qDebug() << "FLAGN1";
  }
  if(flagn2==1){
      m2CameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      m2CameraImageCapture->setEncodingSettings(imageEncoderSettings);
      m2Camera->setCaptureMode(QCamera::CaptureStillImage);
      m2Camera->start();
      m2Camera->searchAndLock();
      m2CameraImageCapture->capture(filename);
      m2Camera->unlock();
      qDebug() << "FLAGN2";
  }
  if(flagn3==1){
      m3CameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
      QImageEncoderSettings imageEncoderSettings;
      imageEncoderSettings.setCodec("image/jpeg");
      imageEncoderSettings.setResolution(640, 420);
      m3CameraImageCapture->setEncodingSettings(imageEncoderSettings);
      m3Camera->setCaptureMode(QCamera::CaptureStillImage);
      m3Camera->start();
      m3Camera->searchAndLock();
      m3CameraImageCapture->capture(filename);
      m3Camera->unlock();
      qDebug() << "FLAGN3";
  }

}

void MainWindow::on_recButton2_clicked()
{
  auto filename = QFileDialog::getSaveFileName(this, "Gravar", "/", "video (*.mp4;*.3gp)");
  if (filename.isEmpty()) {
    return;
  }
  //m2Camera->CaptureVideo
  /*recorder = new QMediaRecorder(m2Camera);

    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    recorder->setAudioSettings(audioSettings);

    recorder->setOutputLocation(fromLocalFile(filename));
    recorder->record();*/

}

void MainWindow::on_stopButton2_clicked()
{
  //recorder->stop();
}

/*void MainWindow::paintEvent(QPaintEvent *e)
  {
    QPainter painter(this);
    QPen linepen(Qt::red);
    linepen.setWidth(50);

    painter.setPen(linepen);
    painter.drawLine(1000,1000,10,10);
    painter.drawPoint(posponto2.x(),posponto2.y());
    painter.
  }*/

void MainWindow::paintEvent(QPaintEvent *e)
{ /*
     QPainter painter(this);
     QPen linepen(Qt::red);
     linepen.setWidth(15);
     QPen linepen2(Qt::black);
     linepen2.setWidth(25);

     if(clicked){
     painter.setPen(linepen);
     painter.drawLine(1000,1000,100,100);
     painter.setPen(linepen2);
     painter.drawPoint(200,200);
     }*/

}


void MainWindow::on_bregmaBox_valueChanged(const QString &arg1)
{





  /*if (ui->bregmaBox->value() == 0) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura1.jpg);");
    }
    if (ui->bregmaBox->value() == 1) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura2.jpg);");
    }
    if (ui->bregmaBox->value() == 2) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura3.jpg);");
    }
    if (ui->bregmaBox->value() == 3) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura4.jpg);");
    }
    if (ui->bregmaBox->value() == 4) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura5.jpg);");
    }*/

}

void MainWindow::on_homeButton_clicked()
{

  //MANDAR COMANDO PARA IR PARA A ORIGEM DE CADA EIXO E DEPOIS ZERAR
  offsetdrill = 0;
  offsetseringa = 0;
  offseteletrodo = 0;
  offsetoutros = 0;

  valorx = 0;
  valory = 0;
  valorz = 0;

  raio = 0;
  vx = QString::number(valorx, 'f', 2);
  vy = QString::number(valory, 'f', 2);
  vz = QString::number(valorz, 'f', 2);

  ui->xBrowser->setText(vx);
  ui->yBrowser->setText(vy);
  ui->zBrowser->setText(vz);

  //ui->zerarx->setEnabled(true);
  ui->presetbutton->setEnabled(true);

  if (flagconectar == 1) {
    msgteste = "$3=2";
    msgteste.append("\n");
    Serial->write(msgteste);
    ui->recvEdit->moveCursor(QTextCursor::End);
    ui->recvEdit->insertPlainText("TRANSMITIDO: ");
    ui->recvEdit->insertPlainText(msgteste);
    //ui->recvEdit->insertPlainText("\n");
    qDebug() << msgteste;

    msgteste = "$H";
    msgteste.append("\n");
    Serial->write(msgteste);
    ui->recvEdit->moveCursor(QTextCursor::End);
    ui->recvEdit->insertPlainText("TRANSMITIDO: ");
    ui->recvEdit->insertPlainText(msgteste);
    //ui->recvEdit->insertPlainText("\n");
    qDebug() << msgteste;

    msgteste = "G10 L20 P1 X0. Y0. Z0.";
    msgteste.append("\n");
    Serial->write(msgteste);
    ui->recvEdit->moveCursor(QTextCursor::End);
    ui->recvEdit->insertPlainText("TRANSMITIDO: ");
    ui->recvEdit->insertPlainText(msgteste);
    //ui->recvEdit->insertPlainText("\n");
    qDebug() << msgteste;


    msgteste = "$3=3";
    msgteste.append("\n");
    Serial->write(msgteste);
    ui->recvEdit->moveCursor(QTextCursor::End);
    ui->recvEdit->insertPlainText("TRANSMITIDO: ");
    ui->recvEdit->insertPlainText(msgteste);
    //ui->recvEdit->insertPlainText("\n");
    qDebug() << msgteste;
  }

  flagbregma = 0;


}

void MainWindow::on_ymaisButton_clicked()
{
  /*if((valory + peso + yg54)>=100){

      QMessageBox::warning(this, "Warning", "limit of the machine in Y+");
    }
    else{*/
  valory = valory + peso;
  if (valory < 0 && valory > (-0.1)) {
    valory = 0;
  }
  vy = QString::number(valory, 'f', 2);
  ui->yBrowser->setText(vy);








  if (flagconectar == 1) {

    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 Y";
      qpeso = "";
      qpeso = QString::number(peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
    /*if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G1 Y";
      msgteste.append(vy);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      }*/

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 Y";
      msgteste.append(vy);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      // ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }
}

void MainWindow::on_ymenosButton_clicked()
{
  /*if((valory - peso + yg54)<0){

      QMessageBox::warning(this, "Warning", "limit of the machine in Y-");
    }
    else{*/
  valory = valory - peso;
  if (valory < 0.1 && valory > 0) {
    valory = 0;
  }

  //qDebug() << "VALOR Y: " << valory;

  vy = QString::number(valory, 'f', 2);
  ui->yBrowser->setText(vy);

  if (flagconectar == 1) {



    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 Y";
      qpeso = "";
      qpeso = QString::number(-peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }




    /*if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G1 Y";
      msgteste.append(vy);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      }*/

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 Y";
      msgteste.append(vy);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }
}

void MainWindow::on_xmaisButton_clicked()
{

  /*if((valorx + peso + xg54)>=100){

      QMessageBox::warning(this, "Warning", "limit of the machine in X+");
    }
    else{*/

  valorx = valorx + peso;
  if (valorx < 0 && valorx > (-0.1)) {
    valorx = 0;
  }

  vx = QString::number(valorx , 'f', 2);
  ui->xBrowser->setText(vx);

  if (flagconectar == 1) {
    /*if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G1 X";
      msgteste.append(vx);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      }*/

    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 X";
      qpeso = "";
      qpeso = QString::number(peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 X";
      msgteste.append(vx);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }



  /*msgSerial = "MX";
    msgSerial.append(vx);
    if (msgSerial[0] == 'M'){
      valorRecebido = "";
     for(int ii = 2; ii != msgSerial.length(); ii++){
          valorRecebido[ii-2] = msgSerial[ii];
          qDebug()<<ii <<" caracter "<< msgSerial[ii];
          //qDebug()<<"msgSerial: "<< msgSerial;
     }
      qDebug()<<"VALOR RECEBIDO NA SERIAL DEPOIS DE EXCLUIR OS caracteres MX: "<< valorRecebido;
      temp = valorRecebido.toFloat();
      qDebug()<<"msg M: valor em float ja convertido "<< temp;
    }
  */
  //ui->label_10->setText(msgSerial);
  //Serial->write(msgSerial);
}

void MainWindow::on_xmenosButton_clicked()
{
  /*if((valorx - peso + xg54)<0){

        QMessageBox::warning(this, "Warning", "limit of the machine in X-");
    }
    else{*/
  valorx = valorx - peso;
  if (valorx < 0.1 && valorx > 0) {
    valorx = 0;
  }




  vx = QString::number(valorx, 'f', 2);
  ui->xBrowser->setText(vx);

  if (flagconectar == 1) {
    /*if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G1 X";
      msgteste.append(vx);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      }*/
    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 X";
      qpeso = "";
      qpeso = QString::number(-peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }


    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 X";
      msgteste.append(vx);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }
}


void MainWindow::on_peso1Button_clicked()
{
  peso = 0.1;
  Qpeso = QString::number(peso);
  ui->pesoxyBrowser->setText(Qpeso);
  ui->pesozBrowser->setText(Qpeso);
}

void MainWindow::on_peso2Button_clicked()
{
  peso = 1;
  Qpeso = QString::number(peso);
  ui->pesoxyBrowser->setText(Qpeso);
  ui->pesozBrowser->setText(Qpeso);
}

void MainWindow::on_peso3Button_clicked()
{
  peso = 10;
  Qpeso = QString::number(peso);
  ui->pesoxyBrowser->setText(Qpeso);
  ui->pesozBrowser->setText(Qpeso);
}

void MainWindow::on_zmaisButton_clicked()
{

  /*if((valorz + peso + zg54)>=100){

      QMessageBox::warning(this, "Warning", "limit of the machine in Z+");
    }
    else{*/

  valorz = valorz + peso;
  if (valorz < 0 && valorz > (-0.01)) {
    valorz = 0;
  }
  vz = QString::number(valorz, 'f', 2);
  ui->zBrowser->setText(vz);











  if (flagconectar == 1) {
    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 Z";
      qpeso = "";
      qpeso = QString::number(peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 Z";
      msgteste.append(vz);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }
















  /*

    if (flagconectar == 1) {
    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G1 Z";
      msgteste.append(vz);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 Z";
      msgteste.append(vz);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
    }*/

  if ((ui->outrosButton->isChecked() || ui->drillButton->isChecked()) && flagzferra == 1) {

    qDebug() << "z: zferramenta" << zferramenta << "  valorz:" << valorz << " DIFERENÇA: " << zferramenta - valorz;
    if ((valorz == zferramenta) || (((zferramenta - valorz < 0.001) && (zferramenta - valorz > -0.001)) || ((valorz - zferramenta < 0.001) && (valorz - zferramenta > -0.001)))) {
      ui->zBrowser->setStyleSheet("color: rgb(255, 0, 0);");
      qDebug() << "VZ = ZFERRA";
      //flagzferra = 0;
    }
    else {
      ui->zBrowser->setStyleSheet("color: rgb(0, 0, 0);");
      if (valorz < 0.01 && valorz > 0) {
        valorz = 0;
      }
      if (valorz < 0 && valorz > (-0.01)) {
        valorz = 0;
      }
      qDebug() << "fora";
    }
  }

}

void MainWindow::on_zmenosButton_clicked()
{
  qDebug() << "                                             zmenos VALOR Z:" << valorz;
  valorz = valorz - peso;
  if (valorz < 0.01 && valorz > 0) {
    valorz = 0;
  }
  vz = QString::number(valorz, 'f', 2);
  ui->zBrowser->setText(vz);
  qDebug() << "                                             zmenos VALOR Z:" << valorz;








  if (flagconectar == 1) {
    if (Serial->isOpen() && flagbregma == 1) {
      msgteste = "G55 G91 G1 Z";
      qpeso = "";
      qpeso = QString::number(-peso);
      msgteste.append(qpeso);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      msgteste = "G90";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }

    else if (Serial->isOpen() && flagbregma == 0) {
      msgteste = "G54 G1 Z";
      msgteste.append(vz);
      msgteste.append(f);
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
    }
  }










  /*
    if (flagconectar == 1) {
      if (Serial->isOpen() && flagbregma == 1) {
        msgteste = "G55 G1 Z";
        msgteste.append(vz);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }

      else if (Serial->isOpen() && flagbregma == 0) {
        msgteste = "G54 G1 Z";
        msgteste.append(vz);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }
    }*/

  if ((ui->outrosButton->isChecked() || ui->drillButton->isChecked()) && flagzferra == 1) {

    qDebug() << "z: zferramenta" << zferramenta << "  valorz:" << valorz << " DIFERENÇA: " << zferramenta - valorz;
    if ((valorz == zferramenta) || (((zferramenta - valorz < 0.001) && (zferramenta - valorz > -0.001)) || ((valorz - zferramenta < 0.001) && (valorz - zferramenta > -0.001)))) {
      ui->zBrowser->setStyleSheet("color: rgb(255, 0, 0);");
      qDebug() << "VZ = ZFERRA";
      //flagzferra = 0;
    }
    else {
      ui->zBrowser->setStyleSheet("color: rgb(0, 0, 0);");
      if (valorz < 0.01 && valorz > 0) {
        valorz = 0;
      }
      if (valorz < 0 && valorz > (-0.01)) {
        valorz = 0;
      }
      qDebug() << "fora";
    }
  }


  // mudarnomez();
}

void MainWindow::on_zerarx_clicked()
{
  flagbregma = 1;
  ui->setButton->setEnabled(true);
  ui->pushButton_2->setEnabled(true);


  xg54 = xg54 + valorx;
  yg54 = yg54 + valory;
  zg54 = zg54 + valorz;

  //offseteletrodo = 0;
  //ui->offprobe->setText("0.00");

  auxbre = zg54; //VERIFICAR SE IGUALA A VALORZ OU A ZG54
  //xg54 = valorx;
  //yg54 = valory;
  //zg54 = valorz;
  qDebug() << auxbre << " este valor";
  valorx = 0;
  valory = 0;
  valorz = 0;

  vx = QString::number(valorx, 'f', 2);
  vy = QString::number(valory, 'f', 2);
  vz = QString::number(valorz, 'f', 2);

  ui->xBrowser->setText(vx);
  ui->yBrowser->setText(vy);
  ui->zBrowser->setText(vz);
  if (flagconectar == 1) {
    if (Serial->isOpen()) {

      qDebug() << "G10 L20 AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII";
      msgteste = "G10 L20 P2 X0. Y0. Z0.";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;

      /*msgteste = "G4 P5.0"; //DELAY GRBL EM SEGUNDOS
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;*/

      msgteste = "G54 G0 Z0";
      msgteste.append("\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;
      valorz = -auxbre;
      vz = QString::number(valorz, 'f', 2);
      ui->zBrowser->setText(vz);


    }
  }
}

void MainWindow::on_peso0Button_clicked()
{
  peso = 0.01;
  Qpeso = QString::number(peso);
  ui->pesoxyBrowser->setText(Qpeso);
  ui->pesozBrowser->setText(Qpeso);
}

void MainWindow::on_settempButton_clicked()
{
}


void MainWindow::on_x1Browser2_textChanged()
{
  poxf = ui->x1Browser2->toPlainText().toLatin1();
}




void MainWindow::on_drillButton_clicked()
{
    ui->seringa->setEnabled(false);
  if (ui->zerarx->isEnabled() == false && offseteletrodo == 0.0) {
    QMessageBox::warning(this, "Warning", "First refer to the machine before changing the tool!");
    ui->eletrobutton->click();
  }
  else {
    ui->zerarx->setEnabled(false);
    if (flagdrill == 0 && offsetdrill == 0.0) {
      ui->drillButton->setStyleSheet("color: rgb(255, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
      ferramenta = 1;
      flagdrill = 1;
      flageletrodo = 0;
      flagsyringe = 0;
      flagoutros = 0;
      ui->pushButton_2->setEnabled(false);
    }
    if (offsetdrill != 0.0) {
      ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->pushButton_2->setEnabled(true);
      ferramenta = 1;
      flagdrill = 1;
      flageletrodo = 0;
      flagsyringe = 0;
      flagoutros = 0;
    }
    if (flageletrodo == 1 || flagsyringe == 1 || flagoutros == 1) {
      flageletrodo = 0;
      flagsyringe = 0;
      flagoutros = 0;
    }
  }
}

void MainWindow::on_syringeButton_clicked()
{
    ui->seringa->setEnabled(true);
  if (ui->zerarx->isEnabled() == false && offseteletrodo == 0.0) {
    QMessageBox::warning(this, "Warning", "First refer to the machine before changing the tool!");
    ui->eletrobutton->click();
  }
  else {
    ui->zerarx->setEnabled(false);
    if (flagsyringe == 0 && offsetseringa == 0.0 ) {
      ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(255, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
      ferramenta = 2;
      flagsyringe = 1;
      flageletrodo = 0;
      flagdrill = 0;
      flagoutros = 0;
      flagselserin = 2;
      ui->pushButton_2->setEnabled(false);
    }

    if (offsetseringa != 0.0) {
      ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->pushButton_2->setEnabled(true);
      ferramenta = 2;
      flagsyringe = 1;
      flageletrodo = 0;
      flagdrill = 0;
      flagoutros = 0;
      flagselserin = 2;
    }


    if (flagdrill == 1 || flageletrodo == 1 || flagoutros == 1) {
      flagdrill = 0;
      flageletrodo = 0;
      flagoutros = 0;
    }
  }
}

void MainWindow::on_eletrobutton_clicked()
{
    ui->seringa->setEnabled(false);

  ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
  ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
  ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
  ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
  if (offseteletrodo != 0.0) {
    ferramenta = 2;
    flagsyringe = 0;
    flageletrodo = 1;
    flagdrill = 0;
    flagoutros = 0;
    ui->pushButton_2->setEnabled(true);
  }

  if (flagdrill == 1 || flagsyringe == 1 || flagoutros == 1) {
    flagdrill = 0;
    flagsyringe = 0;
    flagoutros = 0;
  }

}

void MainWindow::on_outrosButton_clicked()
{
    ui->seringa->setEnabled(false);

  if (ui->zerarx->isEnabled() == false && offseteletrodo == 0.0) {
    QMessageBox::warning(this, "Warning", "First refer to the machine before changing the tool!");
    ui->eletrobutton->click();
  }
  else {
    ui->zerarx->setEnabled(false);
    if (flagoutros == 0 && offsetoutros == 0.0 ) {
      ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(255, 0, 0);");
      ferramenta = 3;
      flagsyringe = 0;
      flagoutros = 1;
      flageletrodo = 0;
      flagdrill = 0;
      ui->pushButton_2->setEnabled(false);
    }

    if (offsetoutros != 0.0) {
      ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
      ui->pushButton_2->setEnabled(true);
      ferramenta = 3;
      flagoutros = 1;
      flagsyringe = 0;
      flageletrodo = 0;
      flagdrill = 0;
    }
    if (flagdrill == 1 || flageletrodo == 1 || flagsyringe == 1) {
      flagdrill = 0;
      flageletrodo = 0;
      flagsyringe = 0;
    }
  }
}


void MainWindow::on_presetbutton_clicked()
{
  if (ui->drillButton->isChecked() && flagdrill == 1) {
    ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
    flageletrodo = 0;
    flagsyringe = 0;
    flagoutros = 0;

    flaganterior = 1;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {
        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorz = 0;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);

        msgteste = "G54 G0 X110 Y-20";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorx = 110 - xg54;
        valory = 0 - 20 - yg54;

        vx = QString::number(valorx, 'f', 2);
        vy = QString::number(valory, 'f', 2);
        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);

        msgteste = "G38.2 Z-100 F100";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorz = 0 - zg54;



        valorz = 0 - zg54 + (offsetdrill - offseteletrodo);
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
      }
    }
  }









  if (ui->eletrobutton->isChecked() && flageletrodo == 1) {
    ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
    flagdrill = 0;
    flagsyringe = 0;
    flagoutros = 0;
    flaganterior = 0;


    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 X110 Y-20 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorx = 110 - xg54;
        valory = 0 - 20 - yg54;
        vx = QString::number(valorx, 'f', 2);
        vy = QString::number(valory, 'f', 2);
        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);


        msgteste = "G38.2 Z-100 F100";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorz = 0 - zg54;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
      }
    }
  }
  if (ui->syringeButton->isChecked() && flagsyringe == 1) {
    ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
    flagdrill = 0;
    flageletrodo = 0;
    flagoutros = 0;
    flaganterior = 2;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        ui->seribox->setEnabled(false);
        ui->seriboxmin->setEnabled(false);
        ui->setseri->setEnabled(false);

        msgteste = "G54 G0 X110 Y";
        msgteste.append(QString::number((-20+compyser)));
        msgteste.append(" Z0\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorx = 110 - xg54;
        valory = 0 - 20 - yg54;
        vx = QString::number(valorx, 'f', 2);
        vy = QString::number(valory, 'f', 2);
        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);


        msgteste = "G38.2 Z-100 F100";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorz = 0 - zg54;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);
      }
    }
  }
  if (ui->outrosButton->isChecked() && flagoutros == 1) {
    ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
    flagdrill = 0;
    flageletrodo = 0;
    flagsyringe = 0;

    flaganterior = 3;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 X110 Y-20 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorx = 110 - xg54;
        valory = 0 - 20 - yg54;
        vx = QString::number(valorx, 'f', 2);
        vy = QString::number(valory, 'f', 2);
        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);


        msgteste = "G38.2 Z-100 F100";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        valorz = 0 - zg54;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);


      }
    }
  }

}

void MainWindow::on_conectarButton_clicked()
{
  if (flagconectar == 0) {
    Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
    // aux=ui->portBox->currentText();
    Serial->open(QIODevice::ReadWrite);
    Serial-> setBaudRate(BAUD115200);
    Serial-> setFlowControl(FLOW_OFF);
    Serial-> setParity(PAR_NONE);
    Serial->setDataBits(DATA_8);
    Serial->setStopBits(STOP_1);

    flagconectar = 1;









    labelconectado = "";
    labelconectado.append(Serial->portName());
    labelconectado.append("; BAUD: ");
    labelconectado.append(Serial->baudRate());

    qDebug() << "PORT: " << Serial->portName();
    qDebug() << "BAUD: " << Serial->baudRate();
    ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo verde.png);");





    if (!Serial->isOpen()) {
      QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
      ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");

      flagconectar = 0;
    }

    //////////////////////////////////////

    connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));

  }

  else {
    if (!Serial->isOpen()) {
      Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
      Serial->open(QIODevice::ReadWrite);
      Serial-> setBaudRate(BAUD115200);

      ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo verde.png);");


      ui->crono->setText(tttempo);
      if (!Serial->isOpen()) {
        QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
        ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");

      }









      //ZERANDO E RESETANDO TODA A INTERFACE
      ui->pushButton_2->setEnabled(false);
      auxcliqueseringa = 0;
      auxgoto = 0;
      auxselserin = 0;
      flagselserin = 0;
      posfinal = 0;
      flagrec = 0;
      flagrec2 = 0;
      mudenomez = 0;
      atualseringa = 0;
      mincorridoseringa=0;
      andamentoprocesso=0;
      tempototalseringa=0;
      tempocorridoseringa=0;

      compyser=18.94;
      compxser=0.0;

      auxdisable=0;

      tempodisable =0;
      tempodisableatual=0;



      ui->zerarseringa->click();

      auxtime2=0;
      auxdrill = 0;
      auxserin = 0;
      auxoutros = 0;
      entrada = 0;

      //ui->eletrobutton->setStyleSheet("color: rgb(255, 0, 0);");
      flaganterior = 0;
      ui->eletrobutton->click();
      ui->offdri->clear();
      ui->offothers->clear();
      ui->offprobe->clear();
      ui->offsy->clear();

      offsetoutros = 0;
      offsetdrill = 0;
      offseteletrodo = 0;
      offsetseringa = 0;

      ui->recvEdit->clear();

      ui->speedbox->setCurrentIndex(2);
      qtrocar = 4;
      qtrocar2 = 5;
      auxcam = 0;
      auxcam2 = 0;

      ttt = 0;
      hora = 0;
      min = 0;
      seg = 0;

      auxtime = 0;
      flagbregma = 0;
      flagzferra = 0;
      zferramenta = 0;
      marcador1 = 0;
      marcador2 = 0;
      marcadoricon = 0;
      marcadorpromp = 0;
      xg54 = 0;
      yg54 = 0;
      zg54 = 0;

      ui->xcomp->appendPlainText(QString::number(compxser));
      ui->ycomp->appendPlainText(QString::number(compyser));

      ui->seribox->setEnabled(false);
      ui->seribox->setValue(0.1);
      ui->setButton->setEnabled(false);
      ui->seriboxmin->setEnabled(false);
      ui->seriboxmin->setValue(1);
      ui->setseri->setEnabled(false);

      ui->lab2->setText("Side 2");
      ui->lab1->setText("Side 1");

      ui->desenhobox->setMaximum(10);
      ui->desenhobox->setMinimum(0);
      ui->desenhobox->setValue(1);
      ui->desenhobox->setDecimals(2);
      ui->desenhobox->setSingleStep(0.1);
      ui->desenhobox2->setMaximum(10);
      ui->desenhobox2->setMinimum(0);
      ui->desenhobox2->setValue(1);
      ui->desenhobox2->setDecimals(2);
      ui->desenhobox2->setSingleStep(0.1);
      auxbre = 0;

      ui->frame->setVisible(false);
      ui->frame_2->setVisible(false);

      ferramenta = 4;
      f = " F500\n";
      flagdrill = 0;
      flageletrodo = 1;
      flagsyringe = 0;
      flagoutros = 0;


      offsetdrill = 0.0;
      offsetseringa = 0.0;
      offseteletrodo = 0.0;
      offsetoutros = 0.0;

      ui->recvEdit->setStyleSheet("color: transparent;");
      ui->recvEdit->setEnabled(false);
      ui->sendEdit->setStyleSheet("color: transparent;");
      ui->sendEdit->setEnabled(false);
      ui->clearbutton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
      ui->clearbutton->setEnabled(false);
      ui->sendButton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
      ui->sendButton->setEnabled(false);


      i = 5;
      valorx = 0;
      valory = 0;
      valorz = 0;

      peso = 0.1;
      Qpeso = QString::number(peso);
      ui->pesoxyBrowser->setText(Qpeso);
      ui->pesozBrowser->setText(Qpeso);

      poxf = QString::number(0);
      poyf = QString::number(0);

      vx = QString::number(valorx, 'f', 2);
      vy = QString::number(valory, 'f', 2);
      vz = QString::number(valorz, 'f', 2);

      ui->xBrowser->setText(vx);
      ui->yBrowser->setText(vy);
      ui->zBrowser->setText(vz);

      ui->labelbrow->setText(labelbrowxyz);

      ui->factorBox->setMaximum(5);
      ui->factorBox->setMinimum(0);
      ui->factorBox->setValue(1);
      ui->factorBox->setDecimals(2);
      ui->factorBox->setSingleStep(0.1);
      fac = QString::number(ui->factorBox->value());
      fator = ui->factorBox->value();





      ui->seribar->setValue(0);
      ui->seribar->setEnabled(false);
      ui->seribar->setMinimum(0);
      ui->seribox->setMinimum(0.1);
      ui->seribox->setMaximum(10);
      ui->seribox->setDecimals(2);
      ui->seribox->setValue(0.1);
      ui->seribox->setSingleStep(0.1);
      ui->passoseringa->setMinimum(0.1);
      ui->passoseringa->setMaximum(1);
      ui->passoseringa->setValue(0.1);
      ui->passoseringa->setDecimals(2);
      ui->passoseringa->setSingleStep(0.1);
      ui->seriboxmin->setValue(1);
      ui->seriboxmin->setMinimum(1);
      ui->seriboxmin->setMaximum(900);


      ui->seribar->setMaximum(100);


      ui->bregmaBox->setMaximum(4.28);
      ui->bregmaBox->setMinimum(-8.24);
      ui->bregmaBox->setValue(0.02);
      ui->bregmaBox->setDecimals(2);
      ui->bregmaBox->setSingleStep(0.1);


      ui->x1Browser2->setPlainText("0");
      ui->z1Browser2->setPlainText("0");


      ui->fundo_imagem->setStyleSheet("background-color: rgba(255, 255, 0, 0);");
      ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura31.jpg);");

      ui->zerarx->setEnabled(false);
      ui->presetbutton->setEnabled(false);




      ui->speedbox->setCurrentIndex(2);
      f = " F300\n";



















      aux = ui->port->currentText();
      qDebug() << "PORT: " << Serial->portName();
      qDebug() << "BAUD: " << Serial->baudRate();

      connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
    }
    else {
      if ((ui->port->currentText()) != aux) {
        Serial->close();
        Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
        Serial->open(QIODevice::ReadWrite);
        Serial-> setBaudRate(BAUD115200);
        if (!Serial->isOpen()) {
          QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
        }
        aux = ui->port->currentText();
        qDebug() << "PORT: " << Serial->portName();
        qDebug() << "BAUD: " << Serial->baudRate();

        connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
      }
      else {
        Serial->close();
        ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");
        labelconectado = "";
        connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
      }
    }
  }
}


void MainWindow::on_refresh_clicked()
{

  ui->port->clear();
  qDebug() << "Portas disponiveis: " << QextSerialEnumerator::getPorts().length();
  foreach (const QextPortInfo info, QextSerialEnumerator::getPorts()) {
    j = info.portName;
    ui->port->addItem(info.portName);
    qDebug() << "ID: " << j;
    qDebug() << "ID: " << info.productID;
  }
}

void MainWindow::on_desconectarButton_clicked()
{
  Serial->close();
  ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");
  labelconectado = "";
}

void MainWindow::on_offtemp_clicked()
{
  if (flagconectar == 1) {
    msgSerial = "T0";
    ui->recvEdit->moveCursor(QTextCursor::End);
    ui->recvEdit->insertPlainText("TRANSMITIDO: ");
    ui->recvEdit->insertPlainText(msgSerial);
    ui->recvEdit->insertPlainText("\n");
    Serial->write(msgSerial);
  }
}

void MainWindow::on_sendButton_clicked()
{
  /*if (Serial->isOpen() && !ui->sendEdit->toPlainText().isEmpty()){
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(ui->sendEdit->toPlainText().toLatin1());
      //ui->recvEdit->insertPlainText("\n");
      //Serial->write(ui->sendEdit->toPlainText().toLatin1());

      ui->sendEdit->clear();
    }
    Serial->write("G1 X10 F1000");
    qDebug()<<"enviou $";*/
  if (flagconectar == 1) {
    if (Serial->isOpen() && !ui->sendEdit->toPlainText().isEmpty()) {
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(ui->sendEdit->toPlainText().toLatin1());
      //ui->recvEdit->insertPlainText("\n");
      msgteste = "";
      msgteste = ui->sendEdit->toPlainText().toLatin1();
      msgteste.append("\n");
      Serial->write(msgteste);

      ui->sendEdit->clear();
    }
  }



}

void MainWindow::on_ocultarButton_clicked()
{
  if (ui->ocultarButton->isChecked()) {

    ui->recvEdit->setStyleSheet("color: transparent;");
    ui->recvEdit->setEnabled(false);
    ui->sendEdit->setStyleSheet("color: transparent;");
    ui->sendEdit->setEnabled(false);
    ui->clearbutton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
    ui->clearbutton->setEnabled(false);
    ui->sendButton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
    ui->sendButton->setEnabled(false);
  }
  else {
    ui->recvEdit->setStyleSheet("color: rgb(0, 0, 0);");
    ui->sendEdit->setStyleSheet("color: rgb(0, 0, 0);");
    ui->recvEdit->setEnabled(true);
    ui->sendEdit->setEnabled(true);
    ui->clearbutton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->clearbutton->setEnabled(true);
    ui->sendButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->sendButton->setEnabled(true);

  }
}

void MainWindow::on_clearbutton_clicked()
{
  ui->recvEdit->clear();
}

void MainWindow::on_stopButton_clicked()
{
  if (flagconectar == 1) {
    if (Serial->isOpen()) {
      char resetChar[2] = {0x18, 0x00};
      Serial->write(resetChar, strlen(resetChar));
      /*
         QString val = ui->sendEdit->toPlainText();

        if (val == "reset") {
        char resetChar[2] = {0x18, 0x00};
        Serial->write(resetChar, strlen(resetChar));
        qDebug() << "send reset" << endl;
        }
      */

      //      msgteste = "M00";
      //      msgteste.append("\n");
      //      Serial->write(msgteste);
      //      ui->recvEdit->moveCursor(QTextCursor::End);
      //      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      //      ui->recvEdit->insertPlainText(msgteste);
      //      //ui->recvEdit->insertPlainText("\n");
      // qDebug() << msgteste;
    }
  }

  flagbregma = 0;

}

void MainWindow::on_factorBox_valueChanged(double arg1)
{
  fac = QString::number(ui->factorBox->value());
  fator = ui->factorBox->value();
}





void MainWindow::on_menoseri_clicked()
{

}

void MainWindow::on_quad_clicked()
{
  if (ui->quadButton->isChecked()) {
    if (flagconectar == 1) {
      if (Serial->isOpen()) {



        msgteste = "G55 G1 X";
        //Y esta para o lado1 - que é o desenhobox
        desenho = QString::number( ui->desenhobox->value());
        auxdes = ui->desenhobox->value() / 2;
        desenho2 = QString::number( ui->desenhobox2->value());
        auxdes2 = ui->desenhobox2->value() / 2;
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y"); // Alterar para velocidade setada
        valory = valory - auxdes;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);


        msgteste.append(f);
        msgteste.append("G55 G1 X");
        valorx = valorx + auxdes2;
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);


        msgteste.append("\nG55 G1 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        valory = valory + auxdes * 2;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);


        msgteste.append("\nG55 G1 X");
        valorx = valorx - auxdes2 * 2;
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);


        msgteste.append("\nG55 G1 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        valory = valory - auxdes * 2;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);


        msgteste.append("\nG55 G1 X");
        valorx = valorx + auxdes2;
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);
        msgteste.append("\n");

        msgteste.append("\nG55 G1 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        ui->xBrowser->setText(vx);
        msgteste.append(" Y");
        valory = valory + auxdes;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        ui->yBrowser->setText(vy);
        msgteste.append("\n");



        qDebug() << "codigo" << msgteste;
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
      }
    }
  }

  if (ui->circleButton->isChecked()) {
    if (flagconectar == 1) {
      if (Serial->isOpen()) {
        msgteste = "G55 G1 Y";
        raio = ui->desenhobox->value();
        auxraio = QString::number(ui->desenhobox->value());
        desenho = QString::number( ui->desenhobox->value());
        valory = valory - raio;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        msgteste.append(f);


        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);




        msgteste.append("G55 G3 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        msgteste.append(" Y");
        valory = valory + (2 * raio);
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        msgteste.append(" R");
        msgteste.append(auxraio);
        msgteste.append(f);

        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);

        msgteste.append("G55 G3 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        msgteste.append(" Y");
        valory = valory - (2 * raio);
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        msgteste.append(" R");
        msgteste.append(auxraio);
        msgteste.append(f);

        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);

        msgteste.append("G55 G1 X");
        vx = QString::number(valorx, 'f', 2);
        msgteste.append(vx);
        msgteste.append(" Y");
        valory = valory + raio;
        vy = QString::number(valory, 'f', 2);
        msgteste.append(vy);
        msgteste.append(f);

        ui->xBrowser->setText(vx);
        ui->yBrowser->setText(vy);






        qDebug() << "codigo" << msgteste;
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
      }
    }
  }
}



void MainWindow::on_marcadorcam1_triggered()
{
  if (marcador1 == 0) {
    ui->frame_2->setVisible(true);
    marcador1 = 1;
  }
  else {
    ui->frame_2->setVisible(false);
    marcador1 = 0;
  }
}

void MainWindow::on_marcadorcam2_triggered()
{

  if (marcador2 == 0) {
    ui->frame->setVisible(true);
    marcador2 = 1;
  }
  else {
    ui->frame->setVisible(false);
    marcador2 = 0;
  }
}


void MainWindow::on_tirarfoto2_triggered()
{

  auto filename = QFileDialog::getSaveFileName(this, "Capturar", "/", "Imagem (*.jpg;*.jpeg)");
  if (filename.isEmpty()) {
    return;
  }
  mCameraImageCapture->setCaptureDestination(QCameraImageCapture::CaptureToFile);
  QImageEncoderSettings imageEncoderSettings;
  imageEncoderSettings.setCodec("image/jpeg");
  imageEncoderSettings.setResolution(640, 420);
  mCameraImageCapture->setEncodingSettings(imageEncoderSettings);
  mCamera->setCaptureMode(QCamera::CaptureStillImage);
  mCamera->start();
  mCamera->searchAndLock();
  mCameraImageCapture->capture(filename);
  mCamera->unlock();
}

void MainWindow::on_incluiricon_triggered()
{
  if (marcadoricon == 0) {
    ui->capButton->setVisible(false);
    ui->capButton2->setVisible(false);
    marcadoricon = 1;
  }
  else {
    ui->capButton->setVisible(true);
    ui->capButton2->setVisible(true);
    marcadoricon = 0;
  }



}

void MainWindow::on_acassistencia_triggered()
{
  QMessageBox::information(this, "VOID3D", "EMAIL: contato@void3d.com \n");
}

void MainWindow::on_actionprompot_triggered()
{

  if (marcadorpromp == 1) {

    ui->recvEdit->setStyleSheet("color: transparent;");
    ui->recvEdit->setEnabled(false);
    ui->sendEdit->setStyleSheet("color: transparent;");
    ui->sendEdit->setEnabled(false);
    ui->clearbutton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
    ui->clearbutton->setEnabled(false);
    ui->sendButton->setStyleSheet("background-image: url(:/imagens/fundo fusionjpeg.jpg);border-image: url(:/imagens/fundo fusionjpeg.jpg);image: url(:/imagens/fundo fusionjpeg.jpg);");
    ui->sendButton->setEnabled(false);
    marcadorpromp = 0;
  }
  else {
    ui->recvEdit->setStyleSheet("color: rgb(0, 0, 0);");
    ui->sendEdit->setStyleSheet("color: rgb(0, 0, 0);");
    ui->recvEdit->setEnabled(true);
    ui->sendEdit->setEnabled(true);
    ui->clearbutton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->clearbutton->setEnabled(true);
    ui->sendButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->sendButton->setEnabled(true);
    marcadorpromp = 1;

  }
}

void MainWindow::on_actionConectar_triggered()
{

  if (flagconectar == 0) {
    Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
    // aux=ui->portBox->currentText();
    Serial->open(QIODevice::ReadWrite);
    Serial-> setBaudRate(BAUD115200);
    Serial-> setFlowControl(FLOW_OFF);
    Serial-> setParity(PAR_NONE);
    Serial->setDataBits(DATA_8);
    Serial->setStopBits(STOP_1);

    flagconectar = 1;

    labelconectado = "";
    labelconectado.append(Serial->portName());
    labelconectado.append("; BAUD: ");
    labelconectado.append(Serial->baudRate());

    qDebug() << "PORT: " << Serial->portName();
    qDebug() << "BAUD: " << Serial->baudRate();
    ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo verde.png);");
    if (!Serial->isOpen()) {
      QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
      ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");
      flagconectar = 0;
    }

    //////////////////////////////////////

    connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));

  }

  else {
    if (!Serial->isOpen()) {
      Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
      Serial->open(QIODevice::ReadWrite);
      Serial-> setBaudRate(BAUD115200);

      ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo verde.png);");
      if (!Serial->isOpen()) {
        QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
        ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");
      }
      aux = ui->port->currentText();
      qDebug() << "PORT: " << Serial->portName();
      qDebug() << "BAUD: " << Serial->baudRate();

      connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
    }
    else {
      if ((ui->port->currentText()) != aux) {
        Serial->close();
        Serial = new QextSerialPort(ui->port->currentText(), QextSerialPort::EventDriven, this->parent());
        Serial->open(QIODevice::ReadWrite);
        Serial-> setBaudRate(BAUD115200);
        if (!Serial->isOpen()) {
          QMessageBox::warning(this, "Serial port error", "Impossible to open serial port");
        }
        aux = ui->port->currentText();
        qDebug() << "PORT: " << Serial->portName();
        qDebug() << "BAUD: " << Serial->baudRate();

        connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
      }
      else {
        Serial->close();
        ui->conectarButton->setStyleSheet("background-image: url(:/imagens/fundo vermelho.png);");
        labelconectado = "";

        connect(Serial, SIGNAL(readyRead()), SLOT(onReadyRead()));
      }
    }
  }
}

void MainWindow::on_actionrefresh_triggered()
{


  ui->port->clear();
  qDebug() << "Portas disponiveis: " << QextSerialEnumerator::getPorts().length();
  foreach (const QextPortInfo info, QextSerialEnumerator::getPorts()) {
    j = info.portName;
    ui->port->addItem(info.portName);
    qDebug() << "ID: " << j;
    qDebug() << "ID: " << info.productID;
  }
}

void MainWindow::on_acmanual_triggered()
{
  //QMessageBox::information(this, "HELP", "Em desenvolvimento");
  secdialog = new SecDialog(this);
  secdialog->show();

}

void MainWindow::on_actiondesenhos_pre_definidos_triggered()
{


}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
  if (flagconectar == 1) {
    ui->seringa->isEnabled();

  }
}

void MainWindow::on_circleButton_clicked()
{
  ui->lab1->setText("Radius");
  ui->lab2->setText("");

  ui->labeldesenho->setStyleSheet("background-image: url(:/imagens/cir2.png);");
  ui->desenhobox2->setEnabled(false);
}

void MainWindow::on_quadButton_clicked()
{

  ui->lab1->setText("Side 1");
  ui->lab2->setText("Side 2");
  ui->labeldesenho->setStyleSheet("background-image: url(:/imagens/des4.png);");
  ui->desenhobox2->setEnabled(true);
}




void MainWindow::on_actionTools_triggered()
{
  ui->tools->setEnabled(true);
  ui->tools->setVisible(true);
}



void MainWindow::on_z1Browser2_objectNameChanged(const QString &objectName)
{
  pozf = ui->z1Browser2->toPlainText().toLatin1();
}

void MainWindow::on_bregmaBox_valueChanged(double arg1)
{
  qDebug() << ui->bregmaBox->value();
  ui->bregmaBox->setValue(ui->bregmaBox->value());
  if (ui->bregmaBox->value() == 4.28 || ui->bregmaBox->value() == 4.22) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura1.jpg);");
    ui->bregmaBox->setValue(4.28);
    ui->bregmaBox->setSingleStep(0.3);
  }
  if (ui->bregmaBox->value() == 3.98 || ui->bregmaBox->value() == 3.86) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura2.jpg);");
    ui->bregmaBox->setValue(3.92);
    ui->bregmaBox->setSingleStep(0.3);
  }
  if (ui->bregmaBox->value() == 3.62 || ui->bregmaBox->value() == 3.5 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura3.jpg);");
    ui->bregmaBox->setValue(3.56);
    ui->bregmaBox->setSingleStep(0.3);
  }
  if (ui->bregmaBox->value() == 3.26 || ui->bregmaBox->value() == 3.28) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura4.jpg);");
    ui->bregmaBox->setValue(3.20);
    ui->bregmaBox->setSingleStep(0.3);
  }
  if (ui->bregmaBox->value() == 2.9 || ui->bregmaBox->value() == 3.16 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura5.jpg);");
    ui->bregmaBox->setValue(3.08);
    ui->bregmaBox->setSingleStep(0.2);
  }
  if (ui->bregmaBox->value() == 2.88 || ui->bregmaBox->value() == 3.0 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura6.jpg);");
    ui->bregmaBox->setValue(2.96);
    ui->bregmaBox->setSingleStep(0.2);
  }
  if (ui->bregmaBox->value() == 2.76 || ui->bregmaBox->value() == 2.78 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura7.jpg);");
    ui->bregmaBox->setValue(2.80);
    ui->bregmaBox->setSingleStep(0.2);
  }
  if (ui->bregmaBox->value() == 2.6 || ui->bregmaBox->value() == 2.68 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura8.jpg);");
    ui->bregmaBox->setValue(2.68);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.58 || ui->bregmaBox->value() == 2.56 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura9.jpg);");
    ui->bregmaBox->setValue(2.58);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.48 || ui->bregmaBox->value() == 2.44) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura10.jpg);");
    ui->bregmaBox->setValue(2.46);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.36 || ui->bregmaBox->value() == 2.32 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura11.jpg);");
    ui->bregmaBox->setValue(2.34);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.24 || ui->bregmaBox->value() == 2.20 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura12.jpg);");
    ui->bregmaBox->setValue(2.22);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.12 || ui->bregmaBox->value() == 2.08 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura13.jpg);");
    ui->bregmaBox->setValue(2.10);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 2.0 || ui->bregmaBox->value() == 2.04 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura14.jpg);");
    ui->bregmaBox->setValue(1.98);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.88) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura15.jpg);");
    ui->bregmaBox->setValue(1.94);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.84 || ui->bregmaBox->value() == 1.80 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura16.jpg);");
    ui->bregmaBox->setValue(1.78);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.68 || ui->bregmaBox->value() == 1.64 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura17.jpg);");
    ui->bregmaBox->setValue(1.70);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.60 || ui->bregmaBox->value() == 1.52 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura18.jpg);");
    ui->bregmaBox->setValue(1.54);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.44 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura19.jpg);");
    ui->bregmaBox->setValue(1.42);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.32  || ui->bregmaBox->value() == 1.28 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura20.jpg);");
    ui->bregmaBox->setValue(1.34);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.24  || ui->bregmaBox->value() == 1.2 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura21.jpg);");
    ui->bregmaBox->setValue(1.18);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.08) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura22.jpg);");
    ui->bregmaBox->setValue(1.10);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 1.0  || ui->bregmaBox->value() == 0.96 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura23.jpg);");
    ui->bregmaBox->setValue(0.98);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.88  || ui->bregmaBox->value() == 0.84 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura24.jpg);");
    ui->bregmaBox->setValue(0.86);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.76  || ui->bregmaBox->value() == 0.72 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura25.jpg);");
    ui->bregmaBox->setValue(0.74);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.64  || ui->bregmaBox->value() == 0.6 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura26.jpg);");
    ui->bregmaBox->setValue(0.62);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.52  || ui->bregmaBox->value() == 0.48 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura27.jpg);");
    ui->bregmaBox->setValue(0.50);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.4  || ui->bregmaBox->value() == 0.36 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura28.jpg);");
    ui->bregmaBox->setValue(0.38);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.28  || ui->bregmaBox->value() == 0.24 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura29.jpg);");
    ui->bregmaBox->setValue(0.26);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.16  || ui->bregmaBox->value() == 0.12 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura30.jpg);");
    ui->bregmaBox->setValue(0.14);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == 0.04  || ui->bregmaBox->value() == 0 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura31.jpg);");
    ui->bregmaBox->setValue(0.02);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.08  || ui->bregmaBox->value() == -0.12 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura32.jpg);");
    ui->bregmaBox->setValue(-0.1);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.2  || ui->bregmaBox->value() == -0.24 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura33.jpg);");
    ui->bregmaBox->setValue(-0.22);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.32  || ui->bregmaBox->value() == -0.36 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura34.jpg);");
    ui->bregmaBox->setValue(-0.34);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.44  || ui->bregmaBox->value() == -0.48 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura35.jpg);");
    ui->bregmaBox->setValue(-0.46);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.56  || ui->bregmaBox->value() == -0.60 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura36.jpg);");
    ui->bregmaBox->setValue(-0.58);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.68  || ui->bregmaBox->value() == -0.72 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura37.jpg);");
    ui->bregmaBox->setValue(-0.70);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.8  || ui->bregmaBox->value() == -0.84 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura38.jpg);");
    ui->bregmaBox->setValue(-0.82);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -0.92  || ui->bregmaBox->value() == -0.96 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura39.jpg);");
    ui->bregmaBox->setValue(-0.94);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.04  || ui->bregmaBox->value() == -1.12 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura40.jpg);");
    ui->bregmaBox->setValue(-1.06);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.16  || ui->bregmaBox->value() == -1.24 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura41.jpg);");
    ui->bregmaBox->setValue(-1.22);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.32  || ui->bregmaBox->value() == -1.36 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura42.jpg);");
    ui->bregmaBox->setValue(-1.34);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.44  || ui->bregmaBox->value() == -1.48 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura43.jpg);");
    ui->bregmaBox->setValue(-1.46);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.56  || ui->bregmaBox->value() == -1.60 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura44.jpg);");
    ui->bregmaBox->setValue(-1.58);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.68  || ui->bregmaBox->value() == -1.72 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura45.jpg);");
    ui->bregmaBox->setValue(-1.70);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.80  || ui->bregmaBox->value() == -1.84 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura46.jpg);");
    ui->bregmaBox->setValue(-1.82);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -1.92  || ui->bregmaBox->value() == -1.96 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura47.jpg);");
    ui->bregmaBox->setValue(-1.94);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.04  || ui->bregmaBox->value() == -2.08 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura48.jpg);");
    ui->bregmaBox->setValue(-2.06);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.16  || ui->bregmaBox->value() == -2.20 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura49.jpg);");
    ui->bregmaBox->setValue(-2.18);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.28  || ui->bregmaBox->value() == -2.36 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura50.jpg);");
    ui->bregmaBox->setValue(-2.30);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.40  || ui->bregmaBox->value() == -2.44 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura51.jpg);");
    ui->bregmaBox->setValue(-2.46);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.56  || ui->bregmaBox->value() == -2.60 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura52.jpg);");
    ui->bregmaBox->setValue(-2.54);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.64  || ui->bregmaBox->value() == -2.70 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura53.jpg);");
    ui->bregmaBox->setValue(-2.70);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.80  || ui->bregmaBox->value() == -2.82 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura54.jpg);");
    ui->bregmaBox->setValue(-2.80);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -2.90  || ui->bregmaBox->value() == -2.98 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura55.jpg);");
    ui->bregmaBox->setValue(-2.92);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -3.02  || ui->bregmaBox->value() == -3.06 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura56.jpg);");
    ui->bregmaBox->setValue(-3.08);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.18  || ui->bregmaBox->value() == -3.18 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura57.jpg);");
    ui->bregmaBox->setValue(-3.16);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.26  || ui->bregmaBox->value() == -3.30 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura58.jpg);");
    ui->bregmaBox->setValue(-3.28);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.38  || ui->bregmaBox->value() == -3.42 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura59.jpg);");
    ui->bregmaBox->setValue(-3.40);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.50  || ui->bregmaBox->value() == -3.54 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura60.jpg);");
    ui->bregmaBox->setValue(-3.52);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.62  || ui->bregmaBox->value() == -3.70 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura61.jpg);");
    ui->bregmaBox->setValue(-3.64);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.74  || ui->bregmaBox->value() == -3.78 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura62.jpg);");
    ui->bregmaBox->setValue(-3.80);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.90  || ui->bregmaBox->value() == -3.94 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura63.jpg);");
    ui->bregmaBox->setValue(-3.88);
    ui->bregmaBox->setSingleStep(0.1);
  }

  if (ui->bregmaBox->value() == -3.98  || ui->bregmaBox->value() == -4.06 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura64.jpg);");
    ui->bregmaBox->setValue(-4.04);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.14  || ui->bregmaBox->value() == -4.14 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura65.jpg);");
    ui->bregmaBox->setValue(-4.16);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.26  || ui->bregmaBox->value() == -4.26 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura66.jpg);");
    ui->bregmaBox->setValue(-4.24);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.34  || ui->bregmaBox->value() == -4.38 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura67.jpg);");
    ui->bregmaBox->setValue(-4.36);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.46  || ui->bregmaBox->value() == -4.5 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura68.jpg);");
    ui->bregmaBox->setValue(-4.48);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.58  || ui->bregmaBox->value() == -4.62 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura69.jpg);");
    ui->bregmaBox->setValue(-4.60);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.70  || ui->bregmaBox->value() == -4.74 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura70.jpg);");
    ui->bregmaBox->setValue(-4.72);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.82  || ui->bregmaBox->value() == -4.86 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura71.jpg);");
    ui->bregmaBox->setValue(-4.84);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -4.94  || ui->bregmaBox->value() == -4.92 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura72.jpg);");
    ui->bregmaBox->setValue(-4.96);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.06  || ui->bregmaBox->value() == -5.10 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura73.jpg);");
    ui->bregmaBox->setValue(-5.02);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.12  || ui->bregmaBox->value() == -5.24 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura74.jpg);");
    ui->bregmaBox->setValue(-5.20);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.30  || ui->bregmaBox->value() == -5.30 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura75.jpg);");
    ui->bregmaBox->setValue(-5.34);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.44  || ui->bregmaBox->value() == -5.42 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura76.jpg);");
    ui->bregmaBox->setValue(-5.40);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.50  || ui->bregmaBox->value() == -5.58 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura77.jpg);");
    ui->bregmaBox->setValue(-5.52);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.62  || ui->bregmaBox->value() == -5.70 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura78.jpg);");
    ui->bregmaBox->setValue(-5.68);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.78) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura79.jpg);");
    ui->bregmaBox->setValue(-5.80);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.90  || ui->bregmaBox->value() == -5.9 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura80.jpg);");
    ui->bregmaBox->setValue(-5.88);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -5.98  || ui->bregmaBox->value() == -6.02 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura81.jpg);");
    ui->bregmaBox->setValue(-6.00);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.1  || ui->bregmaBox->value() == -6.14 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura82.jpg);");
    ui->bregmaBox->setValue(-6.12);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.22  || ui->bregmaBox->value() == -6.26 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura83.jpg);");
    ui->bregmaBox->setValue(-6.24);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.34  || ui->bregmaBox->value() == -6.38 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura84.jpg);");
    ui->bregmaBox->setValue(-6.36);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.46  || ui->bregmaBox->value() == -6.54 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura85.jpg);");
    ui->bregmaBox->setValue(-6.48);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.58  || ui->bregmaBox->value() == -6.62 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura86.jpg);");
    ui->bregmaBox->setValue(-6.64);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.74  || ui->bregmaBox->value() == -6.74 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura87.jpg);");
    ui->bregmaBox->setValue(-6.72);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.82  || ui->bregmaBox->value() == -6.86 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura88.jpg);");
    ui->bregmaBox->setValue(-6.84);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -6.94  || ui->bregmaBox->value() == -6.98 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura89.jpg);");
    ui->bregmaBox->setValue(-6.96);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.06  || ui->bregmaBox->value() == -7.1 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura90.jpg);");
    ui->bregmaBox->setValue(-7.08);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.18  || ui->bregmaBox->value() == -7.22 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura91.jpg);");
    ui->bregmaBox->setValue(-7.20);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.30  || ui->bregmaBox->value() == -7.38 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura92.jpg);");
    ui->bregmaBox->setValue(-7.32);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.42  || ui->bregmaBox->value() == -7.46 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura93.jpg);");
    ui->bregmaBox->setValue(-7.48);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.58  || ui->bregmaBox->value() == -7.54 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura94.jpg);");
    ui->bregmaBox->setValue(-7.56);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.66) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura95.jpg);");
    ui->bregmaBox->setValue(-7.64);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.74  || ui->bregmaBox->value() == -7.82 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura96.jpg);");
    ui->bregmaBox->setValue(-7.76);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -7.86  || ui->bregmaBox->value() == -7.9 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura97.jpg);");
    ui->bregmaBox->setValue(-7.92);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -8.02  || ui->bregmaBox->value() == -8.02 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura98.jpg);");
    ui->bregmaBox->setValue(-8.00);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -8.1  || ui->bregmaBox->value() == -8.14 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura99.jpg);");
    ui->bregmaBox->setValue(-8.12);
    ui->bregmaBox->setSingleStep(0.1);
  }
  if (ui->bregmaBox->value() == -8.22 ) {
    ui->fundo_imagem->setStyleSheet("background-image: url(:/imagens/Figura100.jpg);");
    ui->bregmaBox->setValue(-8.24);
    ui->bregmaBox->setSingleStep(0.1);
  }


}


void MainWindow::on_pushButton_clicked()
{
  /*
    //     entrada = 1;
    if (ui->drillButton->isChecked() && flagdrill == 1) {
      flaganterior = 1;
      offsetdrill = valorz;
      offd = QString::number(offsetdrill , 'f', 2);

      vz = QString::number((valorz - offsetdrill) , 'f', 2);
      ui->zBrowser->setText(vz);
      ui->offdri->setText(offd);

    }
    if (ui->syringeButton->isChecked() && flagsyringe == 1) {
      flaganterior = 2;
      offsetseringa = valorz;
      offs = QString::number(valorz , 'f', 2);


      ui->offsy->setText(offs);
    }

    if (ui->outrosButton->isChecked() && flagoutros == 1) {
      flaganterior = 3;
      offsetoutros = valorz;
      offo = QString::number(valorz , 'f', 2);
      ui->offothers->setText(offo);
    }

    /* if (ui->eletrobutton->isChecked()) {//PROBE

         offtools = QString::number(valorz, 'f',2);
         ui->offprobe->setText(offtools);

      }*/
  /*
    ui->drillButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->syringeButton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->eletrobutton->setStyleSheet("color: rgb(0, 0, 0);");
    ui->outrosButton->setStyleSheet("color: rgb(0, 0, 0);");
    flagdrill = 0;
    flageletrodo = 0;
    flagsyringe = 0;
    flagoutros = 0;


  */

}

void MainWindow::on_setserimin_clicked()
{

}


void MainWindow::on_timeon_clicked()
{
  if (auxtime == 1) {
    auxtime = 0;
  }
  else {
    auxtime = 1;
  }
}

void MainWindow::on_timereset_clicked()
{
  auxtime = 2;
}



void MainWindow::on_stopButton_2_clicked()
{
  if ((valorz + 10 + zg54) >= 100) {
    QMessageBox::warning(this, "Warning", "limit of the machine in Z+");
  }
  else {

    valorz = valorz + 10;
    if (valorz < 0 && valorz > (-0.01)) {
      valorz = 0;
    }
    vz = QString::number(valorz, 'f', 2);
    ui->zBrowser->setText(vz);

    if (flagconectar == 1) {
      if (Serial->isOpen() && flagbregma == 1) {
        msgteste = "G55 G1 Z";
        msgteste.append(vz);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }

      else if (Serial->isOpen() && flagbregma == 0) {
        msgteste = "G54 G1 Z";
        msgteste.append(vz);
        msgteste.append(f);
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
      }
    }

    if ((ui->outrosButton->isChecked() || ui->drillButton->isChecked()) && flagzferra == 1) {

      qDebug() << "z: zferramenta" << zferramenta << "  valorz:" << valorz << " DIFERENÇA: " << zferramenta - valorz;
      if ((valorz == zferramenta) || (((zferramenta - valorz < 0.001) && (zferramenta - valorz > -0.001)) || ((valorz - zferramenta < 0.001) && (valorz - zferramenta > -0.001)))) {
        ui->zBrowser->setStyleSheet("color: rgb(255, 0, 0);");
        qDebug() << "VZ = ZFERRA";
        //flagzferra = 0;
      }
      else {
        ui->zBrowser->setStyleSheet("color: rgb(0, 0, 0);");
        if (valorz < 0.01 && valorz > 0) {
          valorz = 0;
        }
        if (valorz < 0 && valorz > (-0.01)) {
          valorz = 0;
        }
        qDebug() << "fora";
      }
    }

  }
}

void MainWindow::on_actionChange_camera_triggered()
{
if(flagCam==3){
    qDebug() << "FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;
    if(flagCam==1){
        delete mLayout;
    }
    if(flagCam==2){
        delete mLayout;
        delete m2Layout;
    }
    if(flagCam==3){
        delete mLayout;
        delete m2Layout;
        delete m3Layout;
    }

    i = 5;
    flagCam = 0;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
      //qDebug() << "NOME CAMERAS " << cameraInfo.deviceName();

      imin=i;
      nome1 = cameraInfo.deviceName();
      //qDebug() << "string camera " << nome1 << " i: " << i;
      if (i == 5) {
        nome1 = cameraInfo.deviceName();
      }
      if (i == 4) {
        nome2 = cameraInfo.deviceName();
      }
      if (i == 3) {
        nome3 = cameraInfo.deviceName();
      }
      i--;
      flagCam++;
    }


    mCameraViewfinder = new QCameraViewfinder(this);
    m2CameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    m2CameraImageCapture = new QCameraImageCapture(m2Camera, this);
    m3CameraImageCapture = new QCameraImageCapture(m3Camera, this);
    m3CameraViewfinder = new QCameraViewfinder(this);
    mLayout = new QVBoxLayout;
    m2Layout = new QVBoxLayout;
    m3Layout = new QVBoxLayout;




    qDebug() << "IMIN:" << imin ;

    /*if(imin==4){
        if(flagtr==0){

            qDebug() << "MUDAR CAMERAS - EM TESTE ";
            flagn1=2;
            flagn2=1;
            flagn3=0;
            mCamera->setViewfinder(mCameraViewfinder);
            mLayout -> addWidget(mCameraViewfinder);
            mLayout->setMargin(0);
            ui->scrollArea->setLayout(m2Layout);
            mCamera->start();

            m2Camera->setViewfinder(m2CameraViewfinder);
            m2Layout -> addWidget(m2CameraViewfinder);
            m2Layout->setMargin(0);
            ui->scrollArea2->setLayout(mLayout);
            m2Camera->start();

        flagtr=1;

        }
        else if(flagtr==1){
            qDebug() << "MUDAR CAMERAS - EM TESTE if flagtr=1 ";

            flagn1=1;
            flagn2=2;
            flagn3=0;
            mCamera->setViewfinder(mCameraViewfinder);
            mLayout -> addWidget(mCameraViewfinder);
            mLayout->setMargin(0);
            ui->scrollArea->setLayout(mLayout);
            mCamera->start();

            m2Camera->setViewfinder(m2CameraViewfinder);
            m2Layout -> addWidget(m2CameraViewfinder);
            m2Layout->setMargin(0);
            ui->scrollArea2->setLayout(m2Layout);
            m2Camera->start();

        flagtr=0;
        }


    }*/

    if(imin==3){

        qDebug() << "mudar 3 cameras -----------------mudar segunda ";

        mCamera->setViewfinder(mCameraViewfinder);
        mLayout -> addWidget(mCameraViewfinder);
        mLayout->setMargin(0);
        m2Camera->setViewfinder(m2CameraViewfinder);
        m2Layout -> addWidget(m2CameraViewfinder);
        m2Layout->setMargin(0);
        m3Camera->setViewfinder(m3CameraViewfinder);
        m3Layout -> addWidget(m3CameraViewfinder);
        m3Layout->setMargin(0);





        if(flagn1==2){
            ui->scrollArea->setLayout(mLayout);
            mCamera->start();
        }
        if(flagn2==2){
            ui->scrollArea->setLayout(m2Layout);
            m2Camera->start();
        }
        if(flagn3==2){
            ui->scrollArea->setLayout(m3Layout);
            m3Camera->start();
        }




        if(flagn1==1){
            if(flagn2==0){
                ui->scrollArea2->setLayout(m2Layout);
                m2Camera->start();
                flagn2=1;
                flagn1=0;
            }
            if(flagn3==0){
                ui->scrollArea2->setLayout(m3Layout);
                m3Camera->start();
                flagn1=0;
                flagn3=1;
            }
        }


        else if(flagn2==1){
            if(flagn1==0){
                ui->scrollArea2->setLayout(mLayout);
                mCamera->start();
                flagn2=0;
                flagn1=1;
            }
            if(flagn3==0){
                ui->scrollArea2->setLayout(m3Layout);
                m3Camera->start();
                flagn2=0;
                flagn3=1;
            }
        }


        else if(flagn3==1){
            if(flagn1==0){
                ui->scrollArea2->setLayout(mLayout);
                mCamera->start();
                flagn3=0;
                flagn1=1;
            }
            if(flagn2==0){
                ui->scrollArea2->setLayout(m2Layout);
                m2Camera->start();
                flagn2=1;
                flagn3=0;
            }
        }
    }

    qDebug() << "FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;
}
}
void MainWindow::on_actionChange_camera_2_triggered()
{

    if(flagCam==3){
    qDebug() << "FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;
    if(flagCam==1){
        delete mLayout;
    }
    if(flagCam==2){
        delete mLayout;
        delete m2Layout;
    }
    if(flagCam==3){
        delete mLayout;
        delete m2Layout;
        delete m3Layout;
    }

    i = 5;
    flagCam = 0;
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    foreach (const QCameraInfo &cameraInfo, cameras) {
      //qDebug() << "NOME CAMERAS " << cameraInfo.deviceName();

      imin=i;
      nome1 = cameraInfo.deviceName();
      //qDebug() << "string camera " << nome1 << " i: " << i;
      if (i == 5) {
        nome1 = cameraInfo.deviceName();
      }
      if (i == 4) {
        nome2 = cameraInfo.deviceName();
      }
      if (i == 3) {
        nome3 = cameraInfo.deviceName();
      }
      i--;
      flagCam++;
    }


    mCameraViewfinder = new QCameraViewfinder(this);
    m2CameraViewfinder = new QCameraViewfinder(this);
    mCameraImageCapture = new QCameraImageCapture(mCamera, this);
    m2CameraImageCapture = new QCameraImageCapture(m2Camera, this);
    m3CameraImageCapture = new QCameraImageCapture(m3Camera, this);
    m3CameraViewfinder = new QCameraViewfinder(this);
    mLayout = new QVBoxLayout;
    m2Layout = new QVBoxLayout;
    m3Layout = new QVBoxLayout;




    qDebug() << "IMIN:" << imin ;

    /*if(imin==4){
        if(flagtr==0){

            qDebug() << "MUDAR CAMERAS - EM TESTE ";
            flagn1=2;
            flagn2=1;
            flagn3=0;
            mCamera->setViewfinder(mCameraViewfinder);
            mLayout -> addWidget(mCameraViewfinder);
            mLayout->setMargin(0);
            ui->scrollArea->setLayout(m2Layout);
            mCamera->start();

            m2Camera->setViewfinder(m2CameraViewfinder);
            m2Layout -> addWidget(m2CameraViewfinder);
            m2Layout->setMargin(0);
            ui->scrollArea2->setLayout(mLayout);
            m2Camera->start();

        flagtr=1;

        }
        else if(flagtr==1){
            qDebug() << "MUDAR CAMERAS - EM TESTE if flagtr=1 ";

            flagn1=1;
            flagn2=2;
            flagn3=0;
            mCamera->setViewfinder(mCameraViewfinder);
            mLayout -> addWidget(mCameraViewfinder);
            mLayout->setMargin(0);
            ui->scrollArea->setLayout(mLayout);
            mCamera->start();

            m2Camera->setViewfinder(m2CameraViewfinder);
            m2Layout -> addWidget(m2CameraViewfinder);
            m2Layout->setMargin(0);
            ui->scrollArea2->setLayout(m2Layout);
            m2Camera->start();

        flagtr=0;
        }


    }*/

    if(imin==3){

        qDebug() << "mudar 3 cameras -----------------mudar segunda ";

        mCamera->setViewfinder(mCameraViewfinder);
        mLayout -> addWidget(mCameraViewfinder);
        mLayout->setMargin(0);
        m2Camera->setViewfinder(m2CameraViewfinder);
        m2Layout -> addWidget(m2CameraViewfinder);
        m2Layout->setMargin(0);
        m3Camera->setViewfinder(m3CameraViewfinder);
        m3Layout -> addWidget(m3CameraViewfinder);
        m3Layout->setMargin(0);





        if(flagn1==1){
            ui->scrollArea2->setLayout(mLayout);
            mCamera->start();
        }
        if(flagn2==1){
            ui->scrollArea2->setLayout(m2Layout);
            m2Camera->start();
        }
        if(flagn3==1){
            ui->scrollArea2->setLayout(m3Layout);
            m3Camera->start();
        }


        if(flagn1==2){
            if(flagn2==0){
                ui->scrollArea->setLayout(m2Layout);
                m2Camera->start();
                flagn2=2;
                flagn1=0;
            }
            if(flagn3==0){
                ui->scrollArea->setLayout(m3Layout);
                m3Camera->start();
                flagn1=0;
                flagn3=2;
            }
        }


        else if(flagn2==2){
            if(flagn1==0){
                ui->scrollArea->setLayout(mLayout);
                mCamera->start();
                flagn2=0;
                flagn1=2;
            }
            if(flagn3==0){
                ui->scrollArea->setLayout(m3Layout);
                m3Camera->start();
                flagn2=0;
                flagn3=2;
            }
        }


        else if(flagn3==2){
            if(flagn1==0){
                ui->scrollArea->setLayout(mLayout);
                mCamera->start();
                flagn3=0;
                flagn1=2;
            }
            if(flagn2==0){
                ui->scrollArea->setLayout(m2Layout);
                m2Camera->start();
                flagn2=2;
                flagn3=0;
            }
        }
    }

    qDebug() << "FLAGN1" << flagn1<< ", FLAGN2" << flagn2<< ", FLAGN3" << flagn3;
}
}


void MainWindow::on_speedbox_currentIndexChanged(int index)
{
  //velmaq = ui->speedbox->currentText();
  velomaq = ui->speedbox->currentText();

  f = " F";
  f.append(velomaq);
  f.append("\n");
}

void MainWindow::on_pushButton_2_clicked()
{
  if (ui->drillButton->isChecked()) {
    flaganterior = 1;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorz = -zg54 - (offsetdrill - offseteletrodo);
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);


        if (flagselserin == 1 && auxselserin == 1) {
          msgteste = "G55 G91 G1 Y";
          qpeso = "";
          qpeso = QString::number(-compyser);
          msgteste.append(qpeso);
          msgteste.append(f);
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          msgteste = "G90";
          msgteste.append("\n");
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          flagselserin = 0;
          auxselserin = 0;
          auxgoto = 0;
        }
        /*if(flagselserin==1 && auxselserin==1 && auxgoto ==1){
            msgteste = "G55 G91 G1 Y";
            qpeso = "";
            qpeso = QString::number(0);
            msgteste.append(qpeso);
            msgteste.append(f);
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            msgteste = "G90";
            msgteste.append("\n");
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            flagselserin = 0;
            auxselserin = 0;
            auxgoto = 0;
          }*/


      }
    }
  }

  if (ui->eletrobutton->isChecked()) {

    ui->zerarx->setEnabled(true);
    flaganterior = 0;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorz = -zg54;
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);







        if (flagselserin == 1 && auxselserin == 1) {
          msgteste = "G55 G91 G1 Y";
          qpeso = "";
          qpeso = QString::number(-compyser);
          msgteste.append(qpeso);
          msgteste.append(f);
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          msgteste = "G90";
          msgteste.append("\n");
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          flagselserin = 0;
          auxselserin = 0;
          auxgoto = 0;
        }

        /* if(flagselserin==1 && auxselserin==1 && auxgoto==1){

             msgteste = "G55 G91 G1 Y";
             qpeso = "";
             qpeso = QString::number(0);
             msgteste.append(qpeso);
             msgteste.append(f);
             Serial->write(msgteste);
             ui->recvEdit->moveCursor(QTextCursor::End);
             ui->recvEdit->insertPlainText("TRANSMITIDO: ");
             ui->recvEdit->insertPlainText(msgteste);
             //ui->recvEdit->insertPlainText("\n");
             qDebug() << msgteste;
             msgteste = "G90";
             msgteste.append("\n");
             Serial->write(msgteste);
             ui->recvEdit->moveCursor(QTextCursor::End);
             ui->recvEdit->insertPlainText("TRANSMITIDO: ");
             ui->recvEdit->insertPlainText(msgteste);
             //ui->recvEdit->insertPlainText("\n");
             qDebug() << msgteste;
             flagselserin = 0;
             auxselserin = 0;
             auxgoto=0;
          }*/


        /*if(flaganterior==2){
            msgteste = "G55 G91 G1 Y";
            qpeso = "";
            qpeso = QString::number(-15.94);
            msgteste.append(qpeso);
            msgteste.append(f);
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            msgteste = "G90";
            msgteste.append("\n");
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
          }*/
      }
    }
  }

  if (ui->syringeButton->isChecked()) {
    flaganterior = 2;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorz = -zg54 - (offsetseringa - offseteletrodo);
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);

        if (flagselserin == 2 && auxselserin == 0) {

          qDebug() << "                                 COMPENSOU NA SERINGA!!!!!!!!!!!!!!!!!!";
          msgteste = "G55 G91 G1 Y";
          qpeso = "";
          qpeso = QString::number(compyser);
          msgteste.append(qpeso);
          msgteste.append(f);
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          msgteste = "G90";
          msgteste.append("\n");
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          flagselserin = 1;
          auxselserin = 1;
          auxgoto = 1;
        }
        /*
          if(flagselserin==2 && auxselserin==0 && auxgoto==1){

            qDebug() << "                                 COMPENSOU NA SERINGA!!!!!!!!!!!!!!!!!!";
            msgteste = "G55 G91 G1 Y";
            qpeso = "";
            qpeso = QString::number(0);
            msgteste.append(qpeso);
            msgteste.append(f);
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            msgteste = "G90";
            msgteste.append("\n");
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            flagselserin = 1;
            auxselserin = 1;
          }


          /*if(yg54 - valory >=15.94){
            msgteste = "G55 G91 G1 Y";
            qpeso = "";
            qpeso = QString::number(+15.94);
            msgteste.append(qpeso);
            msgteste.append(f);
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            msgteste = "G90";
            msgteste.append("\n");
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
          }
          if(yg54 - valory <15.94){

            valory=valory-20;
            vy = QString::number(valory, 'f', 2);
            ui->yBrowser->setText(vy);


            msgteste = "G55 G91 G1 Y";
            qpeso = "";
            qpeso = QString::number(20-15.94);
            msgteste.append(qpeso);
            msgteste.append(f);
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
            msgteste = "G90";
            msgteste.append("\n");
            Serial->write(msgteste);
            ui->recvEdit->moveCursor(QTextCursor::End);
            ui->recvEdit->insertPlainText("TRANSMITIDO: ");
            ui->recvEdit->insertPlainText(msgteste);
            //ui->recvEdit->insertPlainText("\n");
            qDebug() << msgteste;
          }*/
      }
    }
  }
  if (ui->outrosButton->isChecked()) {
    flaganterior = 3;

    if (flagconectar == 1) {
      if (Serial->isOpen()) {

        msgteste = "G54 G0 Z0";
        msgteste.append("\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        valorz = -zg54 - (offsetoutros - offseteletrodo);
        vz = QString::number(valorz, 'f', 2);
        ui->zBrowser->setText(vz);




        if (flagselserin == 1 && auxselserin == 1) {
          msgteste = "G55 G91 G1 Y";
          qpeso = "";
          qpeso = QString::number(-compyser);
          msgteste.append(qpeso);
          msgteste.append(f);
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          msgteste = "G90";
          msgteste.append("\n");
          Serial->write(msgteste);
          ui->recvEdit->moveCursor(QTextCursor::End);
          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
          ui->recvEdit->insertPlainText(msgteste);
          //ui->recvEdit->insertPlainText("\n");
          qDebug() << msgteste;
          flagselserin = 0;
          auxselserin = 0;
          auxgoto = 0;
        }


        /*
                      if(flagselserin==1 && auxselserin==1 && auxgoto==1){

                          msgteste = "G55 G91 G1 Y";
                          qpeso = "";
                          qpeso = QString::number(0);
                          msgteste.append(qpeso);
                          msgteste.append(f);
                          Serial->write(msgteste);
                          ui->recvEdit->moveCursor(QTextCursor::End);
                          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
                          ui->recvEdit->insertPlainText(msgteste);
                          //ui->recvEdit->insertPlainText("\n");
                          qDebug() << msgteste;
                          msgteste = "G90";
                          msgteste.append("\n");
                          Serial->write(msgteste);
                          ui->recvEdit->moveCursor(QTextCursor::End);
                          ui->recvEdit->insertPlainText("TRANSMITIDO: ");
                          ui->recvEdit->insertPlainText(msgteste);
                          //ui->recvEdit->insertPlainText("\n");
                          qDebug() << msgteste;
                          flagselserin = 0;
                          auxselserin = 0;
                          auxgoto=0;
                      }*/


      }
    }
  }



}


void MainWindow::mudarnomez() {
  if (ui->drillButton->isChecked()) {
    vz2 = QString::number((valorz + offsetdrill), 'f', 2);
    ui->zBrowser->setText(vz2);
  }
  if (ui->syringeButton->isChecked()) {
    vz2 = QString::number((valorz + offsetseringa), 'f', 2);
    ui->zBrowser->setText(vz2);
  }
}



void MainWindow::on_maisseringa_clicked()
{
  if (flagconectar == 1) {
    if (Serial->isOpen()) {

        ui->maisseringa->setEnabled(false);
        ui->menoseringa->setEnabled(false);
      msgteste = "Q";
      qpeso = "";
      qpeso = QString::number((ui->passoseringa->value()) * 24600);
      msgteste.append(qpeso);
      msgteste.append("TEX\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;











      auxdisable = 1;
      tempodisable = ((ui->passoseringa->value()) *  7.38);
      if(tempodisable<0){
          tempodisable=1.5;
      }
      qDebug() <<"tempo disable atual:"<< tempodisable;

    }
  }
}

void MainWindow::on_menoseringa_clicked()
{

  if (flagconectar == 1) {
    if (Serial->isOpen()) {

        ui->maisseringa->setEnabled(false);
        ui->menoseringa->setEnabled(false);
      msgteste = "Q-";
      qpeso = "";
      qpeso = QString::number((ui->passoseringa->value()) * 24600);
      msgteste.append(qpeso);
      msgteste.append("TEX\n");
      Serial->write(msgteste);
      ui->recvEdit->moveCursor(QTextCursor::End);
      ui->recvEdit->insertPlainText("TRANSMITIDO: ");
      ui->recvEdit->insertPlainText(msgteste);
      //ui->recvEdit->insertPlainText("\n");
      qDebug() << msgteste;





      auxdisable=1;
      tempodisableatual = ((ui->passoseringa->value()) * 7.38);

      if(tempodisable<0){
          tempodisable=1.5;
      }
      qDebug() <<"tempo disable atual:"<< tempodisableatual;
    }
  }
}

void MainWindow::on_zerarse_clicked()
{
    if(andamentoprocesso==1){
        QMessageBox::warning(this, "Warning", "Process in progress, wait for completion!");
        ui->injetarseringa->click();
    }
else{
  atualseringa = 0;
  ui->maisseringa->setEnabled(false);
  ui->menoseringa->setEnabled(false);
  ui->passoseringa->setEnabled(false);
  auxcliqueseringa = 1;
}
}
void MainWindow::on_setseri_clicked()
{

    if(andamentoprocesso==1){
        QMessageBox::warning(this, "Warning", "Process in progress, wait for completion!");
        ui->injetarseringa->click();
    }
else{
  if (flagconectar == 1 && ui->injetarseringa->isChecked() == true) {

    if (atualseringa - ui->seribox->value() >= 0) {
      if (Serial->isOpen()) {
        msgteste = "Q";
        qpeso = "";
        qpeso = QString::number((ui->seribox->value()) * 24600);
        msgteste.append(qpeso);
        msgteste.append("T");
        qpeso = "";
        qpeso = QString::number(ui->seriboxmin->value());
        msgteste.append(qpeso);
        msgteste.append("X\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;

        atualseringa -=ui->seribox->value();



        andamentoprocesso=1;

        auxtime2=1;

        tempototalseringa +=ui->seriboxmin->value()*60;
      }
    }
    else {
      QMessageBox::warning(this, "Warning", "Maximum value of syringe reached!");
    }
  }

  if (flagconectar == 1 && ui->encherseringa->isChecked() == true) {
    if (atualseringa + ui->seribox->value() < 10) {
      if (Serial->isOpen()) {
        msgteste = "Q-";
        qpeso = "";
        qpeso = QString::number((ui->seribox->value()) * 24600);
        msgteste.append(qpeso);
        msgteste.append("TEX\n");
        Serial->write(msgteste);
        ui->recvEdit->moveCursor(QTextCursor::End);
        ui->recvEdit->insertPlainText("TRANSMITIDO: ");
        ui->recvEdit->insertPlainText(msgteste);
        //ui->recvEdit->insertPlainText("\n");
        qDebug() << msgteste;
        atualseringa +=ui->seribox->value();

      }
    }
    else {
      QMessageBox::warning(this, "Warning", "Maximum value of syringe reached!");
    }
  }

}
}

void MainWindow::on_encherseringa_clicked()
{
  if (auxcliqueseringa == 0) {
    QMessageBox::warning(this, "Warning", "First refer to the zero of the syringe!");
    ui->zerarseringa->click();
  }
  else{
  if (auxcliqueseringa == 1) {
    ui->seribox->setEnabled(true);
    ui->seriboxmin->setEnabled(false);
    ui->setseri->setEnabled(true);
    ui->seribar->setEnabled(false);
    ui->seribar->setValue(0);
  }
  if(andamentoprocesso==1){
      QMessageBox::warning(this, "Warning", "Process in progress, wait for completion!");
      ui->injetarseringa->click();
  }
}
}

void MainWindow::on_injetarseringa_clicked()
{
  if (auxcliqueseringa == 0) {
    QMessageBox::warning(this, "Warning", "First refer to the zero of the syringe!");
    ui->zerarseringa->click();
  }
  else{
  if (auxcliqueseringa == 1) {
    ui->seriboxmin->setEnabled(true);
    ui->setseri->setEnabled(true);
    ui->seribar->setEnabled(true);
    ui->seribar->setValue(0);

  }
}
}

void MainWindow::on_zerarseringa_clicked()
{
    if(andamentoprocesso==1){
        QMessageBox::warning(this, "Warning", "Process in progress, wait for completion!");
        ui->injetarseringa->click();
    }
    else{
  ui->maisseringa->setEnabled(true);
  ui->menoseringa->setEnabled(true);
  ui->passoseringa->setEnabled(true);
  ui->setseri->setEnabled(false);
  ui->seribox->setEnabled(false);
  ui->seriboxmin->setEnabled(false);
  ui->seribar->setEnabled(false);
  ui->seribar->setValue(0);

}
}


void MainWindow::on_comp_clicked()
{
    compxser=(ui->xcomp->toPlainText()).toFloat();
    compyser=(ui->ycomp->toPlainText()).toFloat();
    qDebug()<<"compensar em X:"<<compxser;
    qDebug()<<"compensar em Y:"<<compyser;
}
