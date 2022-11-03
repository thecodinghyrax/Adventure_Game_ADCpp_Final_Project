#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"
#include "area.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createScene();
    void renderScene(Area);

private slots:
    void on_beginButton_clicked();

private:
    Ui::MainWindow *ui;
    Map gameMap;


};
#endif // MAINWINDOW_H
