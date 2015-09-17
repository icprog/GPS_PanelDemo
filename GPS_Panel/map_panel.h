#ifndef MAP_PANEL_H
#define MAP_PANEL_H

#include <QWidget>

class ZTPManager;
class MAP_Panel : public QWidget
{
    Q_OBJECT
    ZTPManager* ztpm;
public:
    explicit MAP_Panel(const QRect& _rect,QWidget *parent = 0);
    ~MAP_Panel();
private:
private slots:
    void onRead();
    void paintEvent(QPaintEvent *);
};

#endif // MAP_PANEL_H
