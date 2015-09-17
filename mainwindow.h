#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MAP_Panel;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    MAP_Panel* panel;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
