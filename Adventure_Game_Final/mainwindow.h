#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringListModel>
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
    void renderScene(Area);


private slots:
    void on_beginButton_clicked();

    void on_northBtn_clicked();

    void on_southBtn_clicked();

    void on_westBtn_clicked();

    void on_eastBtn_clicked();

    void on_quitBtn_clicked();

    void on_pushButton_9_clicked();

    void on_toGame_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Map gameMap;
    Area current;
    QVector<QString> journal;

    void accessArea(Area, Area);
};
#endif // MAINWINDOW_H
