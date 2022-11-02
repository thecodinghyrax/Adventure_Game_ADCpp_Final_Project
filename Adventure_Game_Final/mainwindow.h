﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include "map.h"
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
    void renderScene(Scene);

private slots:
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<Scene> scenes;

};
#endif // MAINWINDOW_H
