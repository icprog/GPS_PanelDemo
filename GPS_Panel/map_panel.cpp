#include "map_panel.h"
#include"ztpmanager.h"
#include<QHostAddress>
#include<QFile>
#include<QPainter>
MAP_Panel::MAP_Panel(const QRect& _rect,QWidget *parent) :
    QWidget(parent)
{
    setGeometry(_rect);
    hide();
    ztpm = new ZTPManager(7878,QHostAddress("224.102.228.40"));
    connect(ztpm,SIGNAL(readyRead()),this,SLOT(onRead()));
}

MAP_Panel::~MAP_Panel()
{
    delete ztpm;
}
void MAP_Panel::onRead()
{
    ZTPprotocol ztp;
    ztpm->getOneZtp(ztp);
    if(ztp.getPara("T") == "GPS_map")
    {
        QFile f("/tmp/gps_map.png");
        f.open(QFile::WriteOnly|QFile::Truncate);
        f.write(ztp.getPara("content",ZTPprotocol::FILE));
        f.close();
        update();
    }
}

void MAP_Panel::paintEvent(QPaintEvent *)
{
    QPainter painter;
    QImage img("/tmp/gps_map.png");
    painter.begin(this);
    painter.drawImage(0,0,img.copy((img.width()-width())/2,(img.height()-height())/2,width(),height()));
    painter.end();
}
